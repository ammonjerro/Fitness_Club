#include "Consultant.h"

string Consultant::GetInformation() {
    string result=Employee::GetInformation();
    result+=", Position: Consultant, ";
    result+="Contract Interest: "+to_string(contractInterest)+", ";
    result+="Training Interest: "+to_string(trainingInterest)+", ";
    result+="Base Salary: "+to_string(baseSalary);
    return result;
}
