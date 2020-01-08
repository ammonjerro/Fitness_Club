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

    /*
    FitnessClub* club1 = new FitnessClub("cl1", "ssk", "wawa");
    club1->EmployTrainer("Maciek", "Kowalski", "2344523", "oman", 6, 2);
    club1->EmployTrainer("Mateusz", "Zdanowski", "35456", "oman", 5, 2);
    club1->EmployTrainer("Kapitan", "Bomba", "111111", "oman", 7, 2);

    club1->EmployConsultant("Oskar", "Hacel", "2432523", "address2", 2, 1);
    club1->EmployConsultant("Austin", "Wu", "2432524", "address11", 8, 1);
    club1->EmployConsultant("Sergi", "Abdou", "210243032", "address12", 9, 1);

    club1->EmployReceptionist("Baran", "Korkmaz", "243243", "address3", 3, 1);
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
    //club1->ChargeMonthlyFee(club1->FindContract(2));

    club1->FindMember(2)->TakePersonalTraining();
    club1->FindMember(2)->TakePersonalTraining();
    club1->FindContract(2)->PrintContract();
    club1->PrintInformation();
    club1->NextMonth();
    club1->PrintInformation();
    club1->PrintEmployee(club1->FindEmployee(3));
    club1->FindEmployee(3)->Promote();
    club1->PrintEmployee(club1->FindEmployee(3));
    club1->FindEmployee(3)->Promote();

    club1->FindContract(club1->FindMember(1))->PrintContract();
    club1->FireEmployee(club1->FindEmployee(5));
    club1->FireEmployee(club1->FindEmployee(2));
    club1->FindContract(club1->FindMember(1))->PrintContract();


    //club1->ChargeTrainingFee(club1->FindContract(2));
    //club1->ChargeMembers();

    //club1->FindReceptionist(3)->WorkShift(5);
    //cout<<club1->GetSalary(club1->FindEmployee(3));

    */
    FitnessClub* TestClub = new FitnessClub("Platinum", "TestAdress", "Warsaw"); //allocating memory for new
    TestClub->setOpenHours(6, 22); //setting opening hours, this is just an information, opening hours don't matter in the logic of application
    TestClub->SetAdditionalExpenses(4000); //by default value is 0
    TestClub->SetTotalBudget(10000);

    //For all 8 methods below, data is verified, some objects are created and then added to the right lists
    TestClub->EmployConsultant("Maciej", "Zalewski", "123456789", "Address1", 1, 1);
    TestClub->EmployReceptionist("Andrzej", "Kowalski", "987654321", "Address2", 2, 2);
    TestClub->EmployTrainer("Bogdan", "Maciejczyk", "999999999", "Address3", 3, 1);//returns false, the employee of such ID already exists

    TestClub->AddMember(1, "Mateusz", "Mlynarski", "Address4", "M");
    TestClub->AddMember(2, "Adam", "Nowak", "Address5", "M");
    TestClub->AddMember(3, "Kasia", "Grechuta", "Address6", "F");

    //For the purpose of testing, since many methods take pointers as arguments, we are assigning created members and employees to variables, so that we can easily distinguish between them and to spare some space used on searching methods
    Consultant* exampleConsultant = TestClub->FindConsultant(1);
    Receptionist* exampleReceptionist = TestClub->FindReceptionist(2);
    Trainer* exampleTrainer = TestClub->FindTrainer(3);
    Member* member1 = TestClub->FindMember(1);
    Member* member2 = TestClub->FindMember(2);
    Member* member3 = TestClub->FindMember(3);

    //Adding two right contracts, values are checked and objects created and associated to other objects
    TestClub->AddContract(member1, exampleConsultant, exampleTrainer, 1, 150, 150, 500, 5);
    TestClub->AddContract(member2, exampleConsultant, exampleTrainer, 2, 200, 100, 600, 12);

    //Now let's try to add contract to a member who already has an active contract, operation will not work, method returns "false"
    cout << TestClub->AddContract(member2, exampleConsultant, exampleTrainer, 3, 100, 200, 300, 3) <<endl;

    //So lets transfer his contract to member of id = 3
    TestClub->TransferContract(member2, member3);
    //Now the operation is going to work
    cout << TestClub->AddContract(member2, exampleConsultant,exampleTrainer, 3, 170, 120, 400, 7) <<endl;

    //Let's promote Employee of id=2;
    TestClub->FindEmployee(2)->Promote();

    //now we will try to terminate nonexistent contract with id=5
    cout << TestClub->TerminateContract(TestClub->FindContract(5)) <<endl; //returns false

    //So let's terminate a contract with id=3, now member of id=2 has no active contract
    TestClub->TerminateContract(TestClub->FindContract(3)); //returns true

    //Member without a contract tries to take training
    cout << member2->TakeTraining() <<endl; //returns false

    //member with a contract decides to take a training, at the end of a month he is going to pay for it according to the terms of contract
    //club will execute the payment and add the sum to its budget
    //and finally the trainer and consultant will be paid their interest
    cout << member1->TakePersonalTraining() <<endl; //returns true

    //Receptionist wants to work for 13 hours, the amount will be added to his hours worked total, and when the month ends, he will get paid according to his monthly fee
    cout << exampleReceptionist->WorkShift(13) << endl; //returns false, 13 is not a value in interval [8; 12]
    cout << exampleReceptionist->WorkShift(8) << endl; //true, now its okay

    //Adding some products to list of products so that receptionist can sell them
    FitnessClub::AddProduct(1, "Bottle of water", 4.0);
    FitnessClub::AddProduct(2, "Protein Supplement", 150.0);
    FitnessClub::ChangeProductPrice(FitnessClub::FindProduct(2), 130.5);

    cout << exampleReceptionist->SellProduct(FitnessClub::FindProduct(3)) << endl;//returns false, such product does not exist in the list
    cout <<exampleReceptionist->SellProduct(FitnessClub::FindProduct(2)) << endl; //Protein Supplement sold for 130.50, proper amount of money added to employee's account, he will get his interest from it

    //Trainer adds new training plan to his list of plans, then adds an exercise to the plan, prints it and then removes the whole plan
    exampleTrainer->AddTrainingPlan(1, "StrengthPlan", 6, 3);
    exampleTrainer->FindTrainingPlan(1)->AddExercise(1, "Bench Press", "How to do that", 10, 4);
    exampleTrainer->FindTrainingPlan(1)->AddExercise(2, "Pull Ups", "How to do that", 8, 4);
    exampleTrainer->FindTrainingPlan(1)->Print(); //output: TrainingPlan 1, StrengthPlan, 6 weeks, 3 times a week, Exercises: Bench Press, Pull Ups

    exampleTrainer->RemoveTrainingPlan(exampleTrainer->FindTrainingPlan(2)); //Plan "Strength Plan" was properly removed from the list and memory was deallocated
    exampleTrainer->GroupWorkout(); //Adds 1 to trainer groupWorkouts value, he will be paid for that at the end of a month, does not influence any members




    return 0;
}