//Written by Steve Nwachukwu

#ifndef MOM_HPP
#define MOM_HPP

#include <unistd.h>
#include <pthread.h>
#include <csignal>
#include <ctime>
#include "JobTable.hpp"

using namespace std;

class Mom {
private:
JobTable jobTable;
const string kidNames[4] = {"Ali", "Cory", "Lee", "Pat"};
pthread_t tids[4];
vector<Job> completedJobs;
Kid* kids[4];
time_t startTime; //stores the start time of the chores
time_t currentTime; //stores the current time which chores

public:
    Mom() {} //constructor created for mom
    void JobTableInitializer();
    void JobTableScanner();
    void run();

private:
void print();

};
#endif //MOM_HPP
