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


void Receptionist::ResetValues() {
    hoursWorked = 0;
    ProductsEarnings = 0;
}

void Receptionist::SetHourlyFee() {
    switch(GetRank()) {
        case 1:
            hourlyFee=12.0;
            break;
        case 2:
            hourlyFee=15.0;
            break;
        case 3:
            hourlyFee=18.0;
            break;
        case 4:
            hourlyFee=23.0;
            break;
        case 5:
            hourlyFee=27.0;
            break;
    }
}

void Receptionist::SetProductsInterest(){
    switch(GetRank()) {
        case 1:
            productsInterest=0.07;
            break;
        case 2:
            productsInterest=0.1;
            break;
        case 3:
            productsInterest=0.18;
            break;
        case 4:
            productsInterest=0.21;
            break;
        case 5:
            productsInterest=0.25;
            break;
    }
}

bool Receptionist::Promote() {
    if(Employee::Promote()) {
        SetHourlyFee();
        SetProductsInterest();
        return true;
    }
    return false;
}

bool Receptionist::SellProduct(Product *product) {
    if(product) {
        ProductsEarnings += product->price;
        return true;
    }
    return false;
}
