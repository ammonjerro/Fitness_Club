#include "Trainer.h"


string Trainer::GetInformation() {
    string result=Employee::GetInformation();
    result+=", Position: Trainer, ";
    result+="Training Interest: "+to_string_with_precision(trainingInterest, 2)+", ";
    result+="Group Workout Fee: "+to_string_with_precision(groupWorkoutFee, 2);
    return result;
}

void Trainer::ResetValues() {
    SetGroupWorkouts(0);
}

void Trainer::GroupWorkout() {
    groupWorkouts++;
}

void Trainer::SetTrainingInterest() {
    switch(GetRank()) {
        case 1:
            trainingInterest=0.4;
            break;
        case 2:
            trainingInterest=0.45;
            break;
        case 3:
            trainingInterest=0.5;
            break;
        case 4:
            trainingInterest=0.55;
            break;
        case 5:
            trainingInterest=0.6;
            break;
    }

}

void Trainer::SetGroupWorkoutFee() {
    switch (GetRank()) {
        case 1:
            groupWorkoutFee = 60;
            break;
        case 2:
            groupWorkoutFee = 70;
            break;
        case 3:
            groupWorkoutFee = 80;
            break;
        case 4:
            groupWorkoutFee = 90;
            break;
        case 5:
            groupWorkoutFee = 100;
            break;
    }
}

bool Trainer::Promote() {
    if(Employee::Promote()) {
        SetGroupWorkoutFee();
        SetTrainingInterest();
        return true;
    }
   return false;
}

void Trainer::AddTrainingPlan(int id, string name, int duration, int weeklyCount) {
    TrainingPlan* result = new TrainingPlan(id, name, duration, weeklyCount);
    trainingPlans.push_back(result);
}

bool Trainer::RemoveTrainingPlan(TrainingPlan *trainingPlan) {
    if(trainingPlan){
        for (int j = 0; j < trainingPlans.size(); j++) {
            if (trainingPlans[j] == trainingPlan ){
                delete(trainingPlans[j]);
                trainingPlans.erase(trainingPlans.begin()+j);
                return true;
            }
        }
    }
    return false;
}

TrainingPlan *Trainer::FindTrainingPlan(int id) {
    for(TrainingPlan* t : trainingPlans){
        if(t->GetID()==id){
            return t;
        }
    }
    return nullptr;
}
