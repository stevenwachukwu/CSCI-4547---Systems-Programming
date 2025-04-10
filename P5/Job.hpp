//Written by Steve Nwachukwu

#ifndef JOB_HPP
#define JOB_HPP
#include <string>
#include "enums.hpp"

using namespace std;

class Job {
public:
    short Q; //variable for quick work
    short P; //variable for pleasant work
    short E; //variable for easy work
    int jobValue;
    string name;
    JobStatus status;

    Job(); //default constructor for job
    void chooseJob(string kidName, int jobNumber);
    void announceDone();
};


#endif JOB_HPP
