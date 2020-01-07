#include "FitnessClub.h"
#include <iostream>
#include <vector>

FitnessClub::FitnessClub(string name, string address, string city) {
    this->name = name;
    this->address = address;
    this->city=city;
    this->additionalExpenses = 0;
    this->totalBudget=0;
    this->openTime=8;
    this->closeTime=22;
}

bool FitnessClub::EmployTrainer(string name, string surname, string nip, string address, int id, int rank, float trainingInterest, float groupWorkoutFee) {
    Trainer* result = new Trainer(name, surname, nip, address, id, rank, trainingInterest, groupWorkoutFee);
    Employees.push_back(result);
    return true;
}

bool
FitnessClub::EmployConsultant(string name, string surname, string nip, string address, int id, int rank, float contractInterest,
                              float trainingInterest, float baseSalary) {
    Consultant* result = new Consultant(name, surname, nip, address, id, rank, contractInterest, trainingInterest, baseSalary);
   Employees.push_back(result);
   if (result) return true;
   else return false;
}

bool FitnessClub::EmployReceptionist(string name, string surname, string nip, string address, int id, int rank, float hourlyFee,
                                     float productsInterest) {
    Receptionist* result = new Receptionist(name, surname, nip, address, id, rank, hourlyFee, productsInterest);
    Employees.push_back(result);
    if (result) return true;
    else return false;
}

Employee *FitnessClub::FindEmployee(int id) {
    for(Employee* e : Employees){
        if(e->GetId()==id){
            return e;
        }
    }
    return nullptr;
}

Receptionist *FitnessClub::FindReceptionist(int id) {
    for(Employee* e : Employees){
        if(e->GetId()==id){
            return dynamic_cast<Receptionist*>(e);
        }
    }
    return nullptr;
}

void FitnessClub::AddMember(int id, string name, string surname, string address, string gender) {
    Member* result = new Member(id, name, surname, address, gender);
    Members.push_back(result);
}

Member *FitnessClub::FindMember(int id) {
    for(Member* m : Members){
        if(m->GetId()==id){
            return m;
        }
    }
    return nullptr;
}

void FitnessClub::PrintEmployees() {
    for(Employee* e : Employees)
        PrintEmployee(e);
}

Trainer *FitnessClub::FindTrainer(int id) {
    for(Employee* e : Employees){
        if(e->GetId()==id){
            return dynamic_cast<Trainer*>(e);
        }
    }
    return nullptr;
}

Consultant *FitnessClub::FindConsultant(int id) {
    for(Employee* e : Employees){
        if(e->GetId()==id){
            return dynamic_cast<Consultant*>(e);
        }
    }
    return nullptr;
}

void FitnessClub::PrintEmployee(Employee *emp) {
    cout<<emp->GetInformation()<<endl;
}

void FitnessClub::RemoveMember(Member *member) {
    /*
    int i=0;
    for(Member* m : Members){
        if(m==member){
            Members.erase(Members.begin()+i);
            delete(m);
            return;
        }
        i++;
    }
*/
    for (int j = 0; j < Members.size(); j++) {
        if (Members[j] == member ){
            delete(Members[j]);
            Members.erase(Members.begin()+j);
            return;
        }
    }
}

void FitnessClub::PrintMembers() {
    for (Member* m : Members){
        cout<<m->GetInformation()<<endl;
    }
}

bool FitnessClub::AddContract(Member *member, Consultant *consultant, Trainer *trainer, int id, float membershipFee,
                              float trainingFee, float terminationFee, int duration) {
    Contract* result = new Contract(id, duration, membershipFee, trainingFee, terminationFee, consultant, trainer, member);
    Contracts.push_back(result);
    member->SetHasActiveContract(true);
}

Contract *FitnessClub::FindContract(int id) {
    for(Contract* c : Contracts){
        if(c->GetId()==id){
            return c;
        }
    }
    return nullptr;
}

Contract *FitnessClub::FindContract(Member *member) {
    for(Contract* c : Contracts){
        if(c->GetMember() == member){
            return c;
        }
    }
    return nullptr;
}

bool FitnessClub::TransferContract(Member *from, Member *to) {
    if(from->HasActiveContract() && !to->HasActiveContract())
    {
        FindContract(from)->SetMember(to);
        from->SetHasActiveContract(false);
        to->SetHasActiveContract(true);
        return true;
    }
    return false;
}

bool FitnessClub::TerminateContract(Contract * contract) {
    ChargeTerminationFee(contract);
    DeleteContract(contract);
    return false;
}

void FitnessClub::ChargeMonthlyFee(Contract *contract) {
    totalBudget+=contract->GetMembershipFee();
}

void FitnessClub::ChargeTrainingFee(Contract *contract) {
    totalBudget+=(contract->GetTrainingFee())*(float)(contract->GetMember()->GetPersonalTrainings());
}

bool FitnessClub::ChargeMembers() {
    for(Contract* c : Contracts){
        ChargeMonthlyFee(c);
        ChargeTrainingFee(c);
        }
    return true;
    }

bool FitnessClub::ChargeTerminationFee(Contract *contract) {
    totalBudget+=contract->GetTerminationFee();
}

float FitnessClub::GetSalary(Employee *emp) {
    float salary=0;
    if(typeid(*emp) == typeid(Trainer))
    {
        Trainer* trainer = dynamic_cast<Trainer *>(emp);
        salary+=trainer->GroupWorkoutsSalary();
        for(Contract* c : Contracts){
            if(c->GetTrainer()==trainer){
                salary+=(c->GetTrainingFee())*(float)(c->GetMember()->GetPersonalTrainings())*(float)trainer->GetTrainingInterest();
            }
        }
        return salary;
    }

    else if(typeid(*emp) == typeid(Consultant))
    {
        Consultant* consultant = dynamic_cast<Consultant *>(emp);
        salary+=consultant->GetBaseSalary();
        for(Contract* c : Contracts){
            if(c->GetConsultant()==consultant){
                salary+=(c->GetTrainingFee())*(float)(c->GetMember()->GetPersonalTrainings())*(float)consultant->GetTrainingInterest();
                salary+=(c->GetMembershipFee()*(float)(consultant->GetContractInterest()));
            }
        }
        return salary;
    }

    else
    {
        Receptionist* receptionist = dynamic_cast<Receptionist *>(emp);
        salary+=receptionist->GetHourlyFee()*(float)(receptionist->GetHoursWorked());
        salary+=receptionist->GetProductsEarnings()*receptionist->GetProductsInterest();
        return salary;
    }

}

bool FitnessClub::GatherFromReceptionists() {
    for(Employee* emp : Employees){
        if(typeid(*emp) == typeid(Receptionist)){
            Receptionist* receptionist = dynamic_cast<Receptionist *>(emp);
            totalBudget+=receptionist->GetProductsEarnings();
        }
    }
}

bool FitnessClub::PaySalary(Employee* emp) {
    totalBudget-=GetSalary(emp);
}

bool FitnessClub::PayAdditionalExpenses() {
    totalBudget-=additionalExpenses;
}

bool FitnessClub::PaySalaryToAll() {
    for (Employee* emp : Employees){
        PaySalary(emp);
    }
}

void FitnessClub::SetAdditionalExpenses(float value) {
    additionalExpenses=value;
}

bool FitnessClub::setOpenHours(int open, int closed) {
    if(open>=0 && open < 24 && closed >=0 && closed <=24 && closed > open){
        openTime=open;
        closeTime=closed;
        return true;
    }
    else return  false;
}

void FitnessClub::NextMonth() {
    ChargeMembers();
    PaySalaryToAll();
    ResetHoursWorked();
    DecrementContractDurations();
    DeleteExpiredContracts();
}

void FitnessClub::ResetHoursWorked() {
    for(Employee* emp : Employees){
        if(typeid(*emp) == typeid(Receptionist)){
            Receptionist* receptionist = dynamic_cast<Receptionist *>(emp);
            receptionist->SetHoursWorked(0);
        }
    }
}

void FitnessClub::DecrementContractDurations() {
    for(Contract* c : Contracts){
        c->SetDuration(c->GetDuration()-1);
    }
}

void FitnessClub::DeleteExpiredContracts() {
    for(Contract* c : Contracts){
        if(c->GetDuration()==0)
            DeleteContract(c);
    }
}

void FitnessClub::DeleteContract(Contract * contract) {
    int i=0;
    for(Contract* c : Contracts){
        if(c==contract){
            Contracts.erase(Contracts.begin()+i);
            contract->GetMember()->SetHasActiveContract(false);
            delete(c);
        }
        i++;
    }
}

string FitnessClub::GetInformation() {
    string result="";
    result+="Name: "+name+", Address: "+address+", City: "+city+", Open Hours: "+to_string(openTime)+" - "+to_string(closeTime)+", Total Budget: "+to_string(totalBudget)
            +", Additional Expenses: "+to_string(additionalExpenses);
    return result;
}

void FitnessClub::PrintInformation() {
    cout<<GetInformation()<<endl;
}

