#include "Receptionist.h"

string Receptionist::GetInformation() {
    string result=Employee::GetInformation();
    result+=", Position: Receptionist";
    result+=", Hourly Fee: "+to_string(hourlyFee)+", ";
    result+="Products Interest: "+to_string(productsInterest)+", ";
    result+="Hours Worked: "+to_string(hoursWorked)+", ";
    result+="Products Earnings:: "+to_string(ProductsEarnings);
    return result;
}

bool Receptionist::WorkShift(int hours) {
    if(hours>=4 && hours <=12) {
        hoursWorked += hours;
        return true;
    }
    else return false;
}
