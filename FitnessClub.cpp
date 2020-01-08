#include "FitnessClub.h"
#include <iostream>
#include <vector>
#include "Templates.h"
#include <time.h>

FitnessClub::FitnessClub(string name, string address, string city) {
    this->name = name;
    this->address = address;
    this->city=city;
    this->additionalExpenses = 0;
    this->totalBudget=0;
    this->openTime=8;
    this->closeTime=22;
}

vector<Product*> FitnessClub::Products;

bool FitnessClub::EmployTrainer(string name, string surname, string nip, string address, int id, int rank) {
    if(!IdExistsEmployees(id)) {
        Trainer *result = new Trainer(name, surname, nip, address, id, rank);
        Employees.push_back(result);
        return true;
    }
    return false;
}

bool FitnessClub::EmployConsultant(string name, string surname, string nip, string address, int id, int rank) {
    if(!IdExistsEmployees(id)) {
        Consultant *result = new Consultant(name, surname, nip, address, id, rank);
        Employees.push_back(result);
        return true;
    }
   return false;
}

bool FitnessClub::EmployReceptionist(string name, string surname, string nip, string address, int id, int rank) {
    if(!IdExistsEmployees(id)) {
        Receptionist *result = new Receptionist(name, surname, nip, address, id, rank);
        Employees.push_back(result);
        return true;
    }
    return false;
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
        m->PrintMe();
    }
}

bool FitnessClub::AddContract(Member *member, Consultant *consultant, Trainer *trainer, int id, float membershipFee,
                              float trainingFee, float terminationFee, int duration) {
    if(!member->HasActiveContract()) {
        Contract *result = new Contract(id, duration, membershipFee, trainingFee, terminationFee, consultant, trainer,
                                        member);
        Contracts.push_back(result);
        member->SetHasActiveContract(true);
        return true;
    }
    return false;
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
    if(contract) {
        ChargeTerminationFee(contract);
        DeleteContract(contract);
        return true;
    }
    else return false;
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
    if(contract) {
        totalBudget += contract->GetTerminationFee();
        return true;
    }
    return false;
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

void FitnessClub::GatherFromReceptionists() {
    for(Employee* emp : Employees){
        if(typeid(*emp) == typeid(Receptionist)){
            Receptionist* receptionist = dynamic_cast<Receptionist *>(emp);
            totalBudget+=receptionist->GetProductsEarnings();
        }
    }
}

bool FitnessClub::PaySalary(Employee* emp) {
    if(emp) {
        totalBudget -= GetSalary(emp);
        return true;
    }
    return false;
}

void FitnessClub::PayAdditionalExpenses() {
    totalBudget-=additionalExpenses;
}

void FitnessClub::PaySalaryToAll() {
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
    GatherFromReceptionists();
    PaySalaryToAll();
    ResetEmployees();
    DecrementContractDurations();
    DeleteExpiredContracts();
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
    string result="Name: "+name+", Address: "+address+", City: "+city+", Open Hours: "+to_string(openTime)+"-"+to_string(closeTime)+", Total Budget: "+to_string_with_precision(totalBudget, 2)
            +", Additional Expenses: "+to_string_with_precision(additionalExpenses, 2);
    return result;
}

void FitnessClub::PrintInformation() {
    cout<<GetInformation()<<endl;
}

void FitnessClub::ResetEmployees() {
    for (Employee* emp : Employees){
        emp->ResetValues();
    }
}

void FitnessClub::FireEmployee(Employee *emp) {
    for(Contract* c : Contracts){
        if(c->GetTrainer()==emp)
            c->SetTrainer(nullptr);
        else if(c->GetConsultant()==emp)
            c->SetConsultant(nullptr);
    }

    for (int j = 0; j < Employees.size(); j++) {
        if (Employees[j] == emp ){
            delete(Employees[j]);
            Employees.erase(Employees.begin()+j);
            break;
        }
    }
    for(Contract* c : Contracts){
        if(c->GetTrainer()==NULL)
            c->SetTrainer(RandomTrainer());
        if(c->GetConsultant()==NULL)
            c->SetConsultant(RandomConsultant());
    }
}

Trainer *FitnessClub::RandomTrainer() {
    static bool wasInitalized = false;
    if (wasInitalized == false){
        srand(time(NULL));
        wasInitalized = true;
    }
    int trainerCount = 0;
    for(Employee *employee : Employees){
        if(typeid(Trainer)==typeid(*employee)){
            trainerCount++;
        }
    }
    int randInt = rand() % trainerCount;
    trainerCount = 0;
    for(Employee *employee : Employees){
        if(typeid(Trainer)==typeid(*employee)){
            if (trainerCount == randInt)
                return dynamic_cast<Trainer*>(employee);
            trainerCount++;
        }
    }
    return NULL;
}

//PRODUCTS

bool FitnessClub::AddProduct(int id, string name, float price) {
    if(!FindProduct(id)) {
        Product *product = new Product();
        product->name = name;
        product->id = id;
        product->price = price;
        FitnessClub::Products.push_back(product);
        return true;
    }
    return false;
}


void FitnessClub::RemoveProduct(Product *product) {
    for (int j = 0; j < Products.size(); j++) {
        if (Products[j] == product ){
            delete(Products[j]);
            Products.erase(Products.begin()+j);
            return;
        }
    }
}


Product *FitnessClub::FindProduct(int id) {
    for(Product* p : Products){
        if(p->id==id){
            return p;
        }
    }
    return nullptr;
}

bool FitnessClub::ChangeProductPrice(Product *product, float newPrice) {
    if(product) {
        product->price = newPrice;
        return true;
    }
    return false;
}

void FitnessClub::PrintProducts() {
    for(Product* p : Products){
        cout <<"ID: " + to_string(p->id) + ", Name: " + p->name + ", Price: " + to_string_with_precision(p->price, 2)<<endl;
    }
}

Consultant *FitnessClub::RandomConsultant() {
    static bool wasInitalized = false;
    if (wasInitalized == false){
        srand(time(NULL));
        wasInitalized = true;
    }
    int consultantCount = 0;
    for(Employee *employee : Employees){
        if(typeid(Consultant)==typeid(*employee)){
            consultantCount++;
        }
    }
    int randInt = rand() % consultantCount;
    consultantCount = 0;
    for(Employee *employee : Employees){
        if(typeid(Consultant)==typeid(*employee)){
            if (consultantCount == randInt)
                return dynamic_cast<Consultant*>(employee);
            consultantCount++;
        }
    }
    return NULL;
}

bool FitnessClub::IdExistsEmployees(int id) {
    for (Employee* e : Employees){
        if(e->GetId()==id)
            return true;
    }
    return false;
}
bool FitnessClub::IdExistsContracts(int id) {
    for (Contract* c : Contracts){
        if(c->GetId()==id)
            return true;
    }
    return false;
}
bool FitnessClub::IdExistsMembers(int id) {
    for (Member* m : Members){
        if(m->GetId()==id)
            return true;
    }
    return false;
}





