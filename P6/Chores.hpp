#ifndef CHORES_HPP
#define CHORES_HPP

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <cstdint> //utilized for uint8_t

using namespace std;

enum MessageCodes : uint8_t {
    MSG_ACK,
    MSG_NACK,
    MSG_NEED_JOB,
    MSG_JOB_COMPLETE,
    MSG_TIME_TO_QUIT,
    MSG_QUIT,
    MSG_SEND_ID,
};

class Job {
public:
    short jobID;
    short kidID;
    short slow;
    short dirty;
    short heavy;
    short value;

    Job() : jobID(0), kidID(-1), slow(0), dirty(0), heavy(0), value(0) {}
    Job(short ID, short s, short d, short h, short v ) :
    jobID(ID), kidID(-1), slow(s), dirty(d), heavy(h), value(v) {} //initial constructor

    void print () const {
        cout << "The Job ID: " << jobID
             << "The Kid ID: " << kidID
             << "[Slow= " << slow
             << ", Dirty = " << dirty
             << ", Heavy = " << heavy
             << ", Value = " << value
             << "]" << endl;
    }

};

#endif
