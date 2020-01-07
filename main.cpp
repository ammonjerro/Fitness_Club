#include <iostream>
#include <cstdlib>
#include "Employee.h"
#include "FitnessClub.h"
#include "Trainer.h"
#include "Receptionist.h"
#include "Consultant.h"
#include "TrainingPlan.h"
#include <vector>
using namespace std;


int main() {
    FitnessClub* club1 = new FitnessClub("cl1", "ssk", "wawa");
    club1->EmployTrainer("Maciek", "Kowalski", "2344523", "oman", 5, 1, 0.5, 200);
    club1->EmployConsultant("Oskar", "Hacel", "2432523", "address2", 2, 1, 0.1, 0.1, 1000);
    club1->EmployReceptionist("Baran", "Korkmaz", "243243", "address3", 3, 1, 15, 0.1);
    club1->AddMember(1, "Suliaman", "Abass", "India", "M");
    club1->AddMember(2, "Maria", "Sundus", "Romania", "F");
    club1->AddMember(3, "Paulina", "Markiewicz", "Poland", "F");
    club1->PrintEmployees();
    club1->PrintMembers();
    club1->RemoveMember(club1->FindMember(3));
    club1->PrintMembers();
    club1->AddContract(club1->FindMember(1), club1->FindConsultant(2), club1->FindTrainer(5), 1, 150, 120, 600, 6);
    club1->AddContract(club1->FindMember(2), club1->FindConsultant(2), club1->FindTrainer(5), 2, 150, 120, 600, 6);
    club1->FindContract(club1->FindMember(1))->PrintContract();
    club1->TransferContract(club1->FindMember(1), club1->FindMember(2));
    club1->FindContract(1)->PrintContract();
    //club1->TerminateContract(club1->FindContract(1));
    //club1->FindContract(2)->PrintContract();
    //club1->ChargeMonthlyFee(club1->FindContract(2));
    club1->FindMember(2)->TakePersonalTraining();
    club1->FindMember(2)->TakePersonalTraining();

    //club1->ChargeTrainingFee(club1->FindContract(2));
    club1->ChargeMembers();

    club1->FindReceptionist(3)->WorkShift(5);
    cout<<club1->GetSalary(club1->FindEmployee(3));


    return 0;
}