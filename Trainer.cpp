#include "Trainer.h"


string Trainer::GetInformation() {
    string result=Employee::GetInformation();
    result+=", Position: Trainer, ";
    result+="Training Interest: "+to_string(trainingInterest)+", ";
    result+="Group Workout Fee: "+to_string(groupWorkoutFee);
    return result;
}
