#include <string>
#include <iostream>
#include <sstream>

#ifndef FITNESS_CLUB_EMPLOYEE_H
#define FITNESS_CLUB_EMPLOYEE_H
using namespace std;
class Employee{
private:
    int id;
    int rank;
    string name;
    string surname;
    string nip;
    string address;
public:
    //Constructors and Destructor
    Employee (string name, string surname, string nip, string address, int id, int rank) : name(name), surname(surname), nip(nip), address(address), id(id), rank(rank) {};
    ~Employee(){};

    //Getters and Setters
    string GetName();
    string GetSurname();
    string GetNip();
    string GetAddress();
    int GetId(){return id;};
    int GetRank();
    void SetName(string name);
    void SetSurname(string surname);
    void SetNip(string nip);
    void SetAddress(string address);
    void SetId(int id);
    void SetRank(int rank);

    virtual bool Promote(){}; //each employee promotes in different way, check override methods
    virtual string GetInformation(); //each employee returns information depending on his position in club
    virtual bool ResetValues(){}; //method set some fields specific to each employee to 0, used at the end of a month

};

#endif //FITNESS_CLUB_EMPLOYEE_H
/*
virtual string GetInformation(){ //each employee returns different information
    string string1 = tostr(salary);
    return string("Employee: ")  +  name + ", " + surname + ", " + nip +", " + address + ", " + string1;
}

template <typename T> string tostr(const T& t) {
    ostringstream os;
    os<<t;
    return os.str();
}
 */