//Written by Steve Nwachukwu

#ifndef MOM_HPP
#define MOM_HPP

#include "Chores.hpp"
#include <vector>
#include <cstdio>
#include <ctime>

struct KidConnector {
    int sockFD; //The socket file descriptor
    FILE* sock_FP; //FILE* for better input and output
    int kidID;
};

//The Mom function prototypes
vector<Job> createJobs();
void JobTableSender(FILE* FP, const vector<Job>& jobs);
void MessageSender(FILE* FP, MessageCodes msgs);

#endif
