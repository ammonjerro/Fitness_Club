cmake_minimum_required(VERSION 3.15)
project(Fitness_Club)

set(CMAKE_CXX_STANDARD 11)

add_executable(Fitness_Club main.cpp Employee.h Employee.cpp FitnessClub.h Trainer.h Contract.h Trainer.cpp Receptionist.h Receptionist.cpp Consultant.h TrainingPlan.h Member.cpp Member.h Contract.cpp FitnessClub.cpp Consultant.cpp Templates.h TrainingPlan.cpp)