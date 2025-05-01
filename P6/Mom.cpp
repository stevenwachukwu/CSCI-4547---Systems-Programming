#include "Chores.hpp"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sys/socket.h>
#include <netintet/in.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAX_KIDS 4

struct KidConnector {
    int sockFD;
    FILE* sock_FP;
    int kidID;
};

vector<Job> createJobs() {
    vector<Job> jobs;
    short ID = 10;
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        jobs.push_back(Job(ID++, rand()%5+1, rand()%5+1, rand()%5+1, rand()%5+1));
    }
    return jobs;
}

void JobTableSender(FILE *FP, const vector<Job>& jobs) {
    for (const auto& job: jobs) {
        fwrite(&job.jobID, sizeof(short), 1, FP);
        fwrite(&job.kidID, sizeof(short), 1, FP);
        fwrite(&job.slow, sizeof(short), 1, FP);
        fwrite(&job.dirty, sizeof(short), 1, FP);
        fwrite(&job.heavy, sizeof(short), 1, FP);
    }
    fflush(FP);
} //the helper function to send the entire job table to one of the kids over the connection

void MessageSender(FILE *FP, MessageCodes msgs) {
    fwrite(&msgs, sizeof(uint8_t), 1, FP);
    fflush(FP);
}

int main () {
    int server_FD = socket(AF_INET, SOCK_STREAM, 0);
    if (server_FD == -1) {
        perror("The socket has failed!");
        exit(EXIT_FAILURE);
    } //whenever it's "-1" then it would output the error message
}

sockaddr_in address;
socklen_t addrlength = sizeof(address);
memset(&address, 0, addrlength);

//variables to help with the socket connection
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htoms(PORT);

if (bind(server_FD, (sockaddr*)&address, sizeof(address)) < 0) {
    perror("The bind has failed!");
    exit(EXIT_FAILURE);
} //Whenever the bind doesn't work it would give its error message

if (listen(server_FD, MAX_KIDS) < 0) {
    perror("The listening has failed!");
    exit(EXIT_FAILURE);
} //Whenever listen doesn't work it would give its error message

printf("Mom: The server is listening on port %d\n", PORT);

vector<KidConnector> kids;
vector<Job> jobs = createJobs();
time_t startingTime = 0;

//Accepting the four children
for (int i = 0; i < MAX_KIDS; ++i) {
    int new_socket = accept(server_FD, (sockaddr*)&address, &addrlen);
    if (new_socket < 0) {
        perror("The acceptance has failed!");
        exit(EXIT_FAILURE);
    }
    printf("Mom: Kid #%d has been connected!\n", i);

FILE* sock_FP = fdopen(new_socket, "r+");
if (!sock_FP) {
perror("Fdopen has failed!");
exit(EXIT_FAILURE);
}

//Sending out ACK and also the kid ID
MessageSender(sock_FP, MSG_ACK);
fwrite(&i, sizeof(int), 1, sock_FP);
fflush(sock_FP);

kids.push_back({new_socket, sock_FP, i});
}

startingTime = time(NULL);
printf("Mom: All the children have arrived, time to start work!\n");

int activatedKids = MAX_KIDS;

while(activatedKids > 0) {
    for (auto& kid: kids) {
        unint_8 msgCodes;
        if (fread(&msgCodes, sizeof(uint8_t), 1, kid.sock_FP) == 1) {
            if (msgCodes == MSG_NEED_JOB) {
                JobTableSender(kid.sock_FP, jobs);

                int jobIndex;
                fread(&jobIndex, sizeof(int), 1, kid.sock_FP);

                if (jobIndex >= 0 && jobIndex < 10 && jobs[jobiIndex].kidID == -1) {
                    jobs[jobIndex].assignKid(kid.kidID);
                    MessageSender(kid.sock_FP, MSG_ACK);
                }
                else {
                    MessageSender(kid.sock_FP, MSG_NACK);
                    JobTableSender(kid.sock_FP, jobs);
                }
            }
            else if (msgCode == MSG_JOB_COMPLETE) {
                time_t now = time(NULL);
                if (now - startingTime >= 21) {
                    MessageSender(kid.sock_FP, MSG_TIME_TO_QUIT);
                    activatedKids--;
                }
                else {
                    MessageSender(kid.sock_FP, MSG_ACK);
                }
            }
        }
    }

    printf("Mom: All of the children have finished. I'm now closing my shop!\n");
    close(server_FD);
    return 0;
}
