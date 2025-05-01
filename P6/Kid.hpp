#ifndef KID_HPP
#define KID_HPP

#include "Chores.hpp"
#include <vector>
#include <cstdio>

//The kid function prototypes
void MessageSender(FILE* FP, MessageCodes msgs);
void JobTableReceived(FILE* FP, vector<Job>& jobs);

#endif
