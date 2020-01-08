#ifndef FITNESS_CLUB_FITNESSCLUB_H
#define FITNESS_CLUB_FITNESSCLUB_H
#include <vector>
#include <iostream>
#include "Member.h"
#include "Trainer.h"
#include "Consultant.h"
#include "Receptionist.h"
#include "Contract.h"

using namespace std;

class FitnessClub{
    private:
    //basic information
    string name;
    string address;
    string city;
    int openTime;
    int closeTime;

    //finance information
    float totalBudget;
    float additionalExpenses;

    //lists of main objects
    vector <Employee*> Employees;
    vector <Member*> Members;
    vector <Contract*> Contracts;

    static vector<Product*> Products; //Stores the list of products that can be sold by a receptionist

public:
    //Constructor
    FitnessClub(string name, string address, string city);

    //Getters and Setters
    void SetTotalBudget(float value){totalBudget=value;}

    //Members management
    void AddMember(int id, string name, string surname, string address, string gender); //Creates and adds member to the member list
    void RemoveMember(Member* member); //Removes member from the list, and deallocates memory, can only be performed if member doesn't have an active contract
    Member* FindMember(int id); // Searches for a member of a given ID in vector of Members and returns pointer to it or NULL if wasn't found
    //Method FindMember has many overloads, to allow searching by various data

    //Employment management
    //Methods with returning type bool return true when operation was successful and false otherwise
    bool EmployTrainer(string name, string surname, string nip, string address, int id, int rank); //creates new Trainer object, assigns its fields with given values, adds it to Trainer list
    bool EmployConsultant(string name, string surname, string nip, string address, int id, int rank); //creates new Consultant object, assigns its fields with given values, adds it to Trainer list
    bool EmployReceptionist(string name, string surname, string nip, string address, int id, int rank); //creates new Receptionist object, assigns its fields with given values, adds it to Trainer list
    void FireEmployee(Employee* emp); //if they have been associated with any contracts it chooses randomly from other employees and changes the pointers, then removes it from the list of employees, and deallocates memory
    void ResetEmployees(); //invokes each employee's method ResetValues() resets hours worked etc, usually done at the end of the month
    Trainer* RandomTrainer();
    Consultant* RandomConsultant();
    bool IdExistsEmployees(int id);
    bool IdExistsContracts(int id);
    bool IdExistsMembers(int id);
    //Methods Find(**) have many overloads, to allow searching by various data, below examples of ones with ID argument
    Employee* FindEmployee(int id); //searches vector of Employees for the one of a given ID and returns pointer to it or NULL if wasn't found
    Trainer* FindTrainer(int id); //searches vector of Employees for the one of a given ID and returns pointer to it or NULL if wasn't found
    Consultant* FindConsultant(int id);//searches vector of Employees for the one of a given ID and returns pointer to it or NULL if wasn't found
    Receptionist* FindReceptionist(int id);//searches vector of Employees for the one of a given ID and returns pointer to it or NULL if wasn't found

    void PrintEmployee(Employee* emp); //Uses given employee's override method GetInformation() and prints it in console
    //string GetInformation(Employee* emp); //Uses given employee's override method GetInformation()

    //Contracts management
    bool AddContract(Member* member, Consultant* consultant, Trainer* trainer, int id, float membershipFee, float trainingFee, float terminationFee, int duration); //First validates the arguments(for example if first 3 are not NULL), then creates new Contract object, associates it with given people setting proper pointers, sets values of other fields, adds it to the Contract list
    bool TerminateContract(Contract* contract); //executes payment following the terms of terminationFee, sets associated member hasContract value to "false", then removes contract from the list, and deallocates memory
    bool TransferContract(Member* from, Member* to); //first it checks if both members have contracts and determines if operation is possible, then changes given's contract pointer to the latter member and sets proper hasContract values
    Contract* FindContract(int id); //searches the list of contracts by ID, returns NULL if contract wasn't found
    Contract* FindContract(Member* member); //searches the list of contracts by member associated with it, returns NULL if contract wasn't found
    void DeleteContract(Contract* contract); //Removes contract from the list, deallocates memory

    //Finances management
    void ChargeMonthlyFee(Contract* contract); //Adds proper amount of funds to totalBudget
    void ChargeTrainingFee(Contract* contract); //Adds proper amount of funds to totalBudget
    bool ChargeMembers(); //executes payments on all members - int fact it just uses the methods above on each member(we assume that members have infinite money)
    bool ChargeTerminationFee(Contract* contract); //Adds proper amount of funds to totalBudget
    void GatherFromReceptionists(); //For each receptionist employed acquires proper amount of funds from products sold
    float GetSalary(Employee* emp); //calculates the salary of a given Employee depending on his role in the club
    bool PaySalary(Employee* emp); //pays to Employee - in fact it just subtracts specific amount from the totalBudget (calculated by GetSalary())
    void PaySalaryToAll(); // pays to all Employees - performs PaySalary() to all employees
    void PayAdditionalExpenses(); // subtracts the value of AdditionalExpenses from totalBudget, which is a simple representation of such expenses like a rent or electricity of a club
    void SetAdditionalExpenses(float value);

    //Organization
    bool setOpenHours(int open, int closed); //changes values of openTime and closeTime
    void DecrementContractDurations();
    void DeleteExpiredContracts();
    void NextMonth(); //charges members, pays salaries, resets hours worked, decrements contracts durations, deletes expired contracts
    string GetInformation(); //creates a string containing information about a club
    void PrintInformation(); //uses GetInformation and prints it to the console
    void PrintEmployees();
    void PrintMembers();

    //Products

    static bool AddProduct(int id, string name, float price); //creates new Product and adds it to the Products vector;
    static void RemoveProduct(Product* product); //remove Product from the list, and deallocates memory
    static bool ChangeProductPrice(Product* product, float newPrice); //changes given product price
    static Product* FindProduct(int id); //Searches the list of avaliable products in reception by ID, returns NULL if not found;
    static void PrintProducts();

};



#endif //FITNESS_CLUB_FITNESSCLUB_H
