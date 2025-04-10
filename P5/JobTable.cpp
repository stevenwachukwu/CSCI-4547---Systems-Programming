//Written by Steve Nwachukwu

#include "JobTable.hpp"


JobTable::JobTable() : quitFlag(false) {
    for (int i = 0; i < 10; i++) {
       jobs.emplace_back(); //puts in 10 job objects
    }
}

void JobTable::replaceJobs(int index) {
    lock_guard<mutex> guard(lock);
    jobs[index] = Job();
}

static void* kidMain(void* arg) {
    Kid* kid = static_cast<Kid*>(arg);
    kid->run();
    return nullptr;
}
