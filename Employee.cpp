#include <iostream>
#include "Employee.h"
#include "cstring"

string Employee::GetInformation() {
    string result="";
    result+="ID: "+to_string(id)+", ";
    result+="Rank: "+to_string(rank)+", ";
    result+="Name: "+name+", ";
    result+="Surname: "+surname+", ";
    result+="NIP: "+nip+", ";
    result+="Address: "+address;
    return result;
}

bool Employee::Promote() {
    if(rank < 5){
        rank++;
        return true;
    }
    else return false;
}
