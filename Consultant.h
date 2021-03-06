#ifndef FITNESS_CLUB_CONSULTANT_H
#define FITNESS_CLUB_CONSULTANT_H
#include "Employee.h"
#include "Templates.h"

class Consultant: public Employee{
private:
    float contractInterest;
    float trainingInterest;
    float baseSalary;
public:
    //Constructor and destructor
    Consultant(string name, string surname, string nip, string address, int id, int rank) : Employee(name, surname, nip, address, id, rank){SetContractInterest(); SetTrainingInterest(); SetBaseSalary();};
    ~Consultant();

    float GetBaseSalary(){return baseSalary;};
    float GetTrainingInterest(){return trainingInterest;};
    float GetContractInterest(){return contractInterest;};
    void SetContractInterest();
    void SetTrainingInterest();
    void SetBaseSalary();
    bool Promote()override; //Depending on the rank of an Employee increases his contractInterest, trainingInterest, and baseSalary
    string GetInformation() override; //returns a concatenated string of Employee's fields, Consultant's fields and his position name
};



#endif //FITNESS_CLUB_CONSULTANT_H
