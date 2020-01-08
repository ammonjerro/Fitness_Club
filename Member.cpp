//
// Created by Ammon Pc on 05.01.2020.
//

#include "Member.h"

string Member::GetInformation() {
    string result="";
    result+="Name: "+name+", Surname: "+surname+", Address: "+address+", Gender: "+gender+", Trainings: "+to_string(trainings)+", PersonalTrainings: "+to_string(personalTrainings)+
            ", ActiveContract: "+to_string(hasActiveContract);
    return result;
}

bool Member::TakePersonalTraining() {
    personalTrainings++;
    return true;
}

void Member::PrintMe() {
    cout<<GetInformation()<<endl;
}

bool Member::TakeTraining() {
    if(hasActiveContract){
        trainings++;
        return true;
    }
    else return false;
}
