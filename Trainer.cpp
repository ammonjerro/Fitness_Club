#include "Trainer.h"


string Trainer::GetInformation() {
    string result=Employee::GetInformation();
    result+=", Position: Trainer, ";
    result+="Training Interest: "+to_string_with_precision(trainingInterest, 2)+", ";
    result+="Group Workout Fee: "+to_string_with_precision(groupWorkoutFee, 2);
    return result;
}
