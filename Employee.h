#include <string>
#include <iostream>
#include <sstream>
#include "Templates.h"

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
    string GetName(){return name;};
    string GetSurname(){return surname;};
    string GetNip(){return nip;};
    string GetAddress(){return address;};
    int GetId(){return id;};
    int GetRank(){return rank;};
    void SetName(string value){name=value;};
    void SetSurname(string value){surname=value;};
    void SetNip(string value){nip=value;};
    void SetAddress(string value){address=value;};
    void SetId(int value){id=value;};
    void SetRank(int value){rank=value;};

    virtual bool Promote(); //each employee promotes in different way, check override methods
    virtual string GetInformation(); //each employee returns information depending on his position in club
    virtual void ResetValues(){}; //method set some fields specific to each employee to 0, used at the end of a month

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