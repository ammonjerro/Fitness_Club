#ifndef FITNESS_CLUB_CONTRACT_H
#define FITNESS_CLUB_CONTRACT_H
#include <vector>
#include <iostream>
#include "Member.h"
#include "Trainer.h"
#include "Consultant.h"

class Contract{
private:
    int id; //unique identifier
    int duration; //time to expiration (int months), decremented when method NextMonth() in FitnessClub is called
    Consultant* consultant; //consultant who sold the contract to the member
    Trainer* trainer; //trainer chosen by member
    Member* member; // member that signed the contract
    float membershipFee; //amount paid monthly
    float trainingFee; //amount paid for one personal training
    float terminationFee; // amount paid when member decides to cancel the contract before it expired
public:
    string GetInformation(); //returns string containing information about the contract
    void PrintContract(); //prints information about the contract in console

    //Contructor and Destructor
    Contract(int id, int duration, float membershipFee, float trainingFee, float terminationFee, Consultant* consultant, Trainer* trainer, Member* member) : id(id), duration(duration), consultant(consultant), trainer(trainer), member(member), membershipFee(membershipFee),
    trainingFee(trainingFee), terminationFee(terminationFee) {};
    //~Contract(){};
    //Getters and Setters
    void SetDuration(int duration);
    void SetMembershipFee(float amount);
    void SetTrainingFee(float amount);
    void SetTerminationFee(float amount);
    void SetTrainer();
    void SetMember(Member* m){member=m;};
    void SetConsultant(Consultant* consultant);
    int GetId(){return id;};
    int GetDuration();
    Member* GetMember(){return member;};
    float GetMembershipFee(){return membershipFee;};;
    float GetTrainingFee(){return trainingFee;};
    float GetTerminationFee(){return terminationFee;};
    Consultant* GetConsultant(){return consultant;};
    Trainer* GetTrainer(){return trainer;};
    //Member* GetMember();

};

#endif //FITNESS_CLUB_CONTRACT_H
