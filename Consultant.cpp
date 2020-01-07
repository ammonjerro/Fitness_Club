#include "Consultant.h"

string Consultant::GetInformation() {
    string result=Employee::GetInformation();
    result+=", Position: Consultant, ";
    result+="Contract Interest: "+to_string_with_precision(contractInterest, 2)+", ";
    result+="Training Interest: "+to_string_with_precision(trainingInterest, 2)+", ";
    result+="Base Salary: "+to_string_with_precision(baseSalary, 2);
    return result;
}
