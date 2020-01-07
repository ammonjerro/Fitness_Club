#ifndef FITNESS_CLUB_RECEPTIONIST_H
#define FITNESS_CLUB_RECEPTIONIST_H
#include "Employee.h"

struct Product{
    int id;
    string name;
    float price;
};

class Receptionist : public Employee{
private:
    float hourlyFee;
    float productsInterest; // % of money they receive from each sold product
    int hoursWorked;
    float ProductsEarnings; //amount of funds Receptionist gathered in cash from Products, at the end of the month he will be paid adequate part
public:
    //Constructor and Destructor
    Receptionist(string name, string surname, string nip, string address, int id, int rank, float hourlyFee, float productsInterest) : hourlyFee(hourlyFee), productsInterest(productsInterest), Employee(name, surname, nip, address, id, rank){hoursWorked=0; ProductsEarnings=0;};
    ~Receptionist(){};

    //Getters and Setters
    float GetHourlyFee(){return hourlyFee;};
    int GetHoursWorked(){ return hoursWorked;};
    float GetProductsEarnings(){return ProductsEarnings;};
    float GetProductsInterest(){return productsInterest;};
    void SetHourlyFee(float amount);
    void SetHoursWorked(int amount){hoursWorked=amount;};

    string GetInformation() override; //returns a concatenated string of Employee's fields, Trainer's fields and his position name
    bool Promote()override{}; //Dependent on their rank attribute, their horlyFee and/or productsInterest increase
    bool ResetValues()override{}; // sets hoursWorked and ProductEarnings to 0
    bool WorkShift(int hours); //Each time receptionist comes to workplace he can take a shift, a number between 4-12 hours
    bool WeekendShift(int hours); //During weekends their hours count as two
    bool SellProduct(Product* product); //Receptionist chooses product from a static vector of products from main class FitnessClub, then adds corresponding value to his ProductsEarnings

};

#endif //FITNESS_CLUB_RECEPTIONIST_H
