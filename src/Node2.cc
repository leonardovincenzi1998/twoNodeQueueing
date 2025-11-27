// Node2.cc
#include "Node2.h"

Define_Module(Node2);

void Node2::initialize() {
    endServiceSS1Event = new cMessage("endServiceSS1Event");
    endServiceSS2Event = new cMessage("endServiceSS2Event");
    jobInServiceSS1 = nullptr;
    jobInServiceSS2 = nullptr;
    isBusySS1 = false;
    isBusySS2 = false;
    qLenSignalSS1 = registerSignal("queueLenSS1");
    qLenSignalSS2 = registerSignal("queueLenSS2");
    emit(qLenSignalSS1, 0);
    emit(qLenSignalSS2, 0);
}

void Node2::handleMessage(cMessage *msg) {
    if (msg == endServiceSS1Event) {
        send(jobInServiceSS1, "out"); // Feedback
        jobInServiceSS1 = nullptr;
        isBusySS1 = false;
        startNextJobSS1();
    } else if (msg == endServiceSS2Event) {
        send(jobInServiceSS2, "out"); // Feedback
        jobInServiceSS2 = nullptr;
        isBusySS2 = false;
        startNextJobSS2();
    } else {
        Job *job = check_and_cast<Job *>(msg);
        // SS1 serve solo U1, SS2 serve solo U2 [cite: 608]
        if (job->getType() == 1) {
            queueSS1.insert(job);
            emit(qLenSignalSS1, queueSS1.getLength());
            if (!isBusySS1) startNextJobSS1();
        } else {
            queueSS2.insert(job);
            emit(qLenSignalSS2, queueSS2.getLength());
            if (!isBusySS2) startNextJobSS2();
        }
    }
}

void Node2::startNextJobSS1() {
    if (queueSS1.isEmpty()) return;
    jobInServiceSS1 = (Job*)queueSS1.pop();
    emit(qLenSignalSS1, queueSS1.getLength());
    isBusySS1 = true;
    // Tempo di servizio esponenziale per SS1 [cite: 609]
    simtime_t serviceTime = exponential(par("serviceTimeSS1").doubleValue());
    scheduleAt(simTime() + serviceTime, endServiceSS1Event);
}

void Node2::startNextJobSS2() {
    if (queueSS2.isEmpty()) return;
    jobInServiceSS2 = (Job*)queueSS2.pop();
    emit(qLenSignalSS2, queueSS2.getLength());
    isBusySS2 = true;
    // Tempo di servizio esponenziale per SS2 [cite: 609]
    simtime_t serviceTime = exponential(par("serviceTimeSS2").doubleValue());
    scheduleAt(simTime() + serviceTime, endServiceSS2Event);
}
