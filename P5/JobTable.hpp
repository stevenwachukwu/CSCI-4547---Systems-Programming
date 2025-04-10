//Written by Steve Nwachukwu

#ifndef JOBTABLE_HPP
#define JOBTABLE_HPP

#include <vector>
#include <mutex>
#include "Job.hpp"

using namespace std;

class JobTable {
public:
    vector <Job> jobs; //used for the table of 10 jobs
    mutex lock;

    JobTable(); //constructor to initialize JobTable object
    void replaceJobs(int index); //function to give new jobs

private:
    bool quitFlag;
};

static void* kidMain(void* arg); //creates the kids

#endif //JOBTABLE_HPP
