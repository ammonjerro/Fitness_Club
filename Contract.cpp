#include "Contract.h"
#include <iostream>
#include <sstream>
#include <iomanip>

void Contract::PrintContract() {
    cout<<GetInformation()<<endl;
}

string Contract::GetInformation() {
    string result="";
    result+="ID: "+to_string_with_precision(id, 2)+", Duration: "+to_string(duration)+", Consultant ID: "+to_string(consultant->GetId())+", Trainer ID: "+to_string(trainer->GetId())+", Member ID: "+to_string(member->GetId())
            +", Membership Fee: "+to_string_with_precision(membershipFee, 2)+", Training Fee: "+to_string_with_precision(trainingFee, 2)+", Termination Fee: "+to_string(terminationFee);
    return result;
}

