#ifndef FITNESS_CLUB_MEMBER_H
#define FITNESS_CLUB_MEMBER_H
#include "Trainer.h"
#include "Templates.h"

class Member{
private:
    int id;
    string name;
    string surname;
    string address;
    string gender;
    int trainings;
    int personalTrainings;
    bool hasActiveContract;

public:
    //Constructor and Destructor
    Member(int id, string name, string surname, string address, string gender) : id(id), name(name), surname(surname), address(address), gender(gender){trainings=0; personalTrainings=0; hasActiveContract=0;};
    ~Member(){};
    //Getters and Setters
    int GetId(){return id;};
    bool HasActiveContract(){return hasActiveContract;};
    void SetHasActiveContract(bool x){hasActiveContract=x;};
    int GetTrainings(){return trainings;};
    int GetPersonalTrainings(){return personalTrainings;};

    string GetInformation(); //returns a concatenated string of Member's fields
    void PrintMe(); //prints information about the member in a console

    //Activities
    bool TakeTraining(); //when a member decides to take training it has to be checked if he has an active contract, then value of trainings is incremented
    bool TakePersonalTraining(); //Same as above plus at the end of a month trainers and consultants are paid their interest depending on the amount of trainings taken by a member

};


#endif //FITNESS_CLUB_MEMBER_H
