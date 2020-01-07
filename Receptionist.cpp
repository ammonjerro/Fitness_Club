#include "Receptionist.h"

string Receptionist::GetInformation() {
    string result=Employee::GetInformation();
    result+=", Position: Receptionist";
    result+=", Hourly Fee: "+to_string_with_precision(hourlyFee,2)+", ";
    result+="Products Interest: "+to_string_with_precision(productsInterest, 2)+", ";
    result+="Hours Worked: "+to_string(hoursWorked)+", ";
    result+="Products Earnings:: "+to_string_with_precision(ProductsEarnings, 2);
    return result;
}

bool Receptionist::WorkShift(int hours) {
    if(hours>=4 && hours <=12) {
        hoursWorked += hours;
        return true;
    }
    else return false;
}

bool Receptionist::WeekendShift(int hours) {
    if(hours>=4 && hours <=12) {
        hoursWorked += hours*2;
        return true;
    }
    else return false;
}

bool Receptionist::SellProduct(Product *product) {

}
