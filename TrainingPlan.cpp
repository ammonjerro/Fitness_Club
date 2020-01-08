#include "TrainingPlan.h"
#include <iostream>


string TrainingPlan::GetString(Exercise *exercise) {
    string result = "ID: "+to_string(exercise->id) + "Name: " + exercise->name + ", Description: "+exercise->description+", Repetitions: "
            + to_string(exercise->repetitions)+", Series: "+to_string(exercise->series);
    return result;
}

void TrainingPlan::PrintExercise(Exercise *exercise) {
    cout << GetString(exercise)<<endl;
}

void TrainingPlan::Print() {
    string str = "ID: " + to_string(id) + ", Name: "+name +", Duration: "+to_string(duration)+", Weekly Count: "+to_string(weeklyCount);
    cout << str << endl;
    for(Exercise *e : exercises){
        PrintExercise(e);
    }
}

bool TrainingPlan::AddExercise(int id, string name, string description, int repetitions, int series) {
    Exercise* result = new Exercise();
    result->series = series;
    result->id=id;
    result->repetitions=repetitions;
    result->description = description;
    result->name = name;
    exercises.push_back(result);
}

bool TrainingPlan::RemoveExercise(Exercise *exercise) {
    if(exercise){
        for (int j = 0; j < exercises.size(); j++) {
            if (exercises[j] == exercise ){
                delete(exercises[j]);
                exercises.erase(exercises.begin()+j);
                return true;
            }
        }
    }
    return false;
}

Exercise *TrainingPlan::FindExercise(int id) {
    for(Exercise* e : exercises){
        if(e->id==id){
            return e;
        }
    }
    return nullptr;
}
