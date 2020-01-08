#include "Consultant.h"

string Consultant::GetInformation() {
    string result=Employee::GetInformation();
    result+=", Position: Consultant, ";
    result+="Contract Interest: "+to_string_with_precision(contractInterest, 2)+", ";
    result+="Training Interest: "+to_string_with_precision(trainingInterest, 2)+", ";
    result+="Base Salary: "+to_string_with_precision(baseSalary, 2);
    return result;
}

void Consultant::SetContractInterest() {
    switch(GetRank()) {
        case 1:
            contractInterest=0.05;
            break;
        case 2:
            contractInterest=0.08;
            break;
        case 3:
            contractInterest=0.13;
            break;
        case 4:
            contractInterest=0.18;
            break;
        case 5:
            contractInterest=0.24;
            break;
    }
}

void Consultant::SetTrainingInterest() {
    switch(GetRank()) {
        case 1:
            trainingInterest=0.06;
            break;
        case 2:
            trainingInterest=0.08;
            break;
        case 3:
            trainingInterest=0.1;
            break;
        case 4:
            trainingInterest=0.12;
            break;
        case 5:
            trainingInterest=0.14;
            break;
    }
}

void Consultant::SetBaseSalary() {
    switch(GetRank()) {
        case 1:
            baseSalary=1000;
            break;
        case 2:
            baseSalary=1150;
            break;
        case 3:
            baseSalary=1250;
            break;
        case 4:
            baseSalary=1370;
            break;
        case 5:
            baseSalary=1700;
            break;
    }
}

bool Consultant::Promote() {
    if(Employee::Promote()) {
        SetTrainingInterest();
        SetBaseSalary();
        SetContractInterest();
        return true;
    }
    return false;
}


