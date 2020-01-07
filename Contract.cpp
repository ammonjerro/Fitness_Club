#include "Contract.h"
#include <iostream>

void Contract::PrintContract() {
    cout << GetInformation()<<endl;
}

string Contract::GetInformation() {
    string result="";
    result+="ID: "+to_string(id)+", Duration: "+to_string(duration)+", Consultant ID: "+to_string(consultant->GetId())+", Trainer ID: "+to_string(trainer->GetId())+", Member ID: "+to_string(member->GetId())
            +", Membership Fee: "+to_string(membershipFee)+", Training Fee: "+to_string(trainingFee)+", Termination Fee: "+to_string(terminationFee);
    return result;
}
