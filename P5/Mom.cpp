//Written by Steve Nwachukwu

#include <map>
#include "Mom.hpp"



void Mom::JobTableInitializer() {
    lock_guard<mutex> guard(jobTable.lock);
    for (int i = 0; i < 10; i++) {
        jobTable.jobs[i] = Job();
    }
}

void Mom::JobTableScanner() {
    lock_guard<mutex> guard(jobTable.lock);
    for (int i = 0; i < 10; i++) {
        if (jobTable.jobs[i].status == complete) {
            completedJobs.push_back(jobTable.jobs[i]);
            jobTable.jobs[i] = Job(); //replaces finished job with new one
        }
    }
}

void Mom::run () {
    JobTableInitializer();

    for (int i = 0; i < 4; i++) {
        kids[i] = new Kid(kidNames[i], &jobTable);
        pthread_create(&tids[i], nullptr, kidMain, kids[i]);
    }

    sleep(1); //delay to make the threads ready
    time(&startTime);

    for (int i = 0; i < 4; i++) {
        pthread_kill(tids[i], SIGUSR1);
    }

    while (true) {
        sleep(1);
        time(&currentTime);
        if (difftime(currentTime, startTime) >= 21) break;
        JobTableScanner();
    }

    jobTable.quitFlag = true;
    for (int i = 0; i < 4; i++) {
        pthread_kill(tids[i], SIGQUIT);
    }
    for (int i = 0; i <4; i++) {
            pthread_join(tids[i], nullptr);
            print();
        }
}

void print() {
    map<string,int> earnings;
    for (const Job& j : completedJobs) {
        earnings[j.name] += j.jobValue;
    }
    string topKid;
    int highestEarned = 0;
    for (const auto& [kid, score] : earnings) {
        if (score > highestEarned) {
            topKid = kid;
            highestEarned = score;
        }
    }

    cout << "\n The completed jobs: ";
    for (const Job& j : completedJobs) {
        cout << j.name << " has earned" << j.jobValue << " points!";

        cout << "\n The top earner: " << topKid << "has gotten +$5 bonus!\n";
    }
}
