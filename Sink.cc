// Sink.cc
#include "Sink.h"

Define_Module(Sink);

void Sink::initialize() {
    sojournTimeU1Signal = registerSignal("sojournTimeU1");
    sojournTimeU2Signal = registerSignal("sojournTimeU2");
}

void Sink::handleMessage(cMessage *msg) {
    Job *job = check_and_cast<Job *>(msg);
    simtime_t sojournTime = simTime() - job->getCreationTime();

    if (job->getType() == 1) {
        emit(sojournTimeU1Signal, sojournTime);
    } else {
        emit(sojournTimeU2Signal, sojournTime);
    }

    // Qui si possono calcolare le altre statistiche, come il superamento della soglia
    // OMNeT++ può farlo in post-processing usando i vector registrati.

    delete job;
}
