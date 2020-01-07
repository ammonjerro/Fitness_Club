#ifndef FITNESS_CLUB_TRAINER_H
#define FITNESS_CLUB_TRAINER_H
#include "Employee.h"
#include "TrainingPlan.h"
#include <string>
#include <vector>
#include "Templates.h"
using namespace std;

class Trainer: public Employee {
private:
    float trainingInterest; //% of each training he earns
    float groupWorkoutFee; //amount of cash they get from each group workout they organise
    int groupWorkouts; //groupWorkouts performed, additional income
    vector<TrainingPlan*> trainingPlans; //Each trainer has their own Training Plans list, containing information about plans they prepared for their clients


public:
    //Constructor and Destructor
    Trainer(string name, string surname, string nip, string address, int id, int rank, float trainingInterest, float groupWorkoutFee) : trainingInterest(trainingInterest), groupWorkoutFee(groupWorkoutFee), Employee(name, surname, nip, address, id, rank){groupWorkouts=0;};
    ~Trainer(){};

    //Getters and Setters
    float GetTrainingInterest(){return trainingInterest;};
    int GetTrainingsCount();
    int GetGroupWorkouts();
    void SetTrainingInterest(float amount);
    void SetTrainingsCount(int amount);
    void SetGroupWorkouts(int amount);
    float GroupWorkoutsSalary(){return (float)(groupWorkouts)*groupWorkoutFee;};

    void AddTrainingPlan(int id, string name, int duration, int weeklyCount); //creates new TrainingPlan object, and adds it to the list
    void RemoveTrainingPlan(TrainingPlan* trainingPlan); //the plan is removed from the list and then deallocated
    void ModifyTrainingPlan(TrainingPlan* trainingPlan, string name, int duration, int weeklyCount); //modifies fields of TrainingPlan object, method is overloaded many times, depending on which attributes user want to change
    TrainingPlan* FindTrainingPlan(int id); //Searches the list of plans by ID, returns NULL if ID wasn't found


    string GetInformation() override; //returns a concatenated string of Employee's fields, Trainer's fields and his position name
    bool Promote()override{}; //depending on rank of the Employee increases their trainingInterest and groupWorkoutFee
    bool ResetValues()override{}; //sets groupWorkouts to 0;
    bool GroupWorkout(){}; //invoked when trainer decides to organise a group workout, method increments value of groupWorkouts
};

#endif //FITNESS_CLUB_TRAINER_H
/*
string GetInformation() override {
auto name = Employee::GetInformation();
return name + "Position: Trainer of rank " + tostr(rank);
}
*/