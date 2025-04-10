//Written by Steve Nwachukwu

#include "Job.hpp"
#include <cstdlib>

Job::Job () {
   Q = rand() % 5 + 1; //creating random values for quick work
   P = rand() % 5 + 1; //creating random values for pleasant work
   E = rand() % 5 + 1; //creating random values for easy work
   jobValue = Q * (P + E);
   name = "";
   status = notStarted; //initial status
}

//This where the kids choose their job
void Job::chooseJob(string kidName, int jobNumber) {
    name = kidName;
    status = working;
}

//Function works when a kid finishes their job
void Job::announceDone() {
    status = complete;
}
