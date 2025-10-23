// Node1.cc
#include "Node1.h"

Define_Module(Node1);

void Node1::initialize() {
    endServiceEvent = new cMessage("endServiceEvent");
    jobInService = nullptr;
    isBusy = false;
    qLenSignalU1 = registerSignal("queueLenNode1_U1");
    qLenSignalU2 = registerSignal("queueLenNode1_U2");
    emit(qLenSignalU1, 0);
    emit(qLenSignalU2, 0);
}

void Node1::handleMessage(cMessage *msg) {
    if (msg == endServiceEvent) { // Fine del servizio
        // Invia il job alla destinazione successiva
        if (uniform(0, 1) < par("feedbackProbability").doubleValue()) {
            send(jobInService, "toNode2"); // Va al nodo 2 [cite: 606]
        } else {
            send(jobInService, "toSink"); // Lascia il sistema [cite: 606]
        }
        jobInService = nullptr;
        isBusy = false;
        startNextJob();
    } else { // Arrivo di un nuovo job
        Job *job = check_and_cast<Job *>(msg);
        if (job->getType() == 1) {
            queueU1.insert(job);
            emit(qLenSignalU1, queueU1.getLength());
        } else {
            queueU2.insert(job);
            emit(qLenSignalU2, queueU2.getLength());
        }

        if (!isBusy) {
            startNextJob();
        }
    }
}

void Node1::startNextJob() {
    // Disciplina prioritaria: serve prima gli utenti U1 [cite: 604]
    if (!queueU1.isEmpty()) {
        jobInService = (Job*)queueU1.pop();
        emit(qLenSignalU1, queueU1.getLength());
    } else if (!queueU2.isEmpty()) {
        jobInService = (Job*)queueU2.pop();
        emit(qLenSignalU2, queueU2.getLength());
    } else {
        return; // Niente da servire
    }

    isBusy = true;
    simtime_t serviceTime;
    if (jobInService->getType() == 1) {
        // Tempo di servizio uniforme per U1 [cite: 604]
        serviceTime = uniform(par("serviceTimeU1_a").doubleValue(), par("serviceTimeU1_b").doubleValue());
    } else {
        // Tempo di servizio uniforme per U2 [cite: 605]
        serviceTime = uniform(par("serviceTimeU2_c").doubleValue(), par("serviceTimeU2_d").doubleValue());
    }
    scheduleAt(simTime() + serviceTime, endServiceEvent);
}
