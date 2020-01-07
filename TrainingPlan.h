#ifndef FITNESS_CLUB_TRAININGPLAN_H
#define FITNESS_CLUB_TRAININGPLAN_H
#include <vector>
#include <string>

using namespace std;

struct Exercise{
    int id;
    string name;
    string description;
    int repetitions;
    int series;
};
class TrainingPlan{
private:
    int id;
    string name;
    int duration; //in weeks
    int weeklyCount;
    vector<Exercise*>exercises;

public:
    TrainingPlan(string name, int duration, int weeklyCount); //Constructor
    ~TrainingPlan(); // Destructor

    string GetString(Exercise* exercise); //returns concatenated string made of given exercise's fields
    void PrintExercise(Exercise* exercise); //prints Exercise info in a console
    void Print(); //Prints information about the plan and all its exercises in a console
    void AddExercise(int id, string name, string description, int repetitions, int series);
    void RemoveExercise(Exercise* exercise); //removes exercise from the list, then deallocates memory
    void ModifyExercise(Exercise* exercise, string name, string description, int repetition, int series); //method is overloaded many times, depending on which attributes user want to change
    Exercise* FindExercise(int id); //Searches for the Exercise in the list by ID, returns NULL if not found
};
#endif //FITNESS_CLUB_TRAININGPLAN_H
