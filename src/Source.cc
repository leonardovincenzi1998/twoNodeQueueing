// Source.cc
#include "Source.h"

Define_Module(Source);

void Source::initialize() {
    sendMessageEvent = new cMessage("sendMessageEvent");
    // Scheduliamo il primo arrivo
    scheduleAt(simTime() + exponential(par("interArrivalTime").doubleValue()), sendMessageEvent);
}

void Source::handleMessage(cMessage *msg) {
    // Genera un nuovo utente
    Job *job = new Job("job");
    job->setCreationTime(simTime());

    // Assegna il tipo di utente in base alla probabilità q
    if (uniform(0, 1) < par("userTypeProbability").doubleValue()) {
        job->setType(1); // Utente U1
    } else {
        job->setType(2); // Utente U2
    }

    send(job, "out");

    // Schedula il prossimo arrivo usando una distribuzione ESPONENZIALE
    scheduleAt(simTime() + exponential(par("interArrivalTime").doubleValue()), sendMessageEvent);
}
