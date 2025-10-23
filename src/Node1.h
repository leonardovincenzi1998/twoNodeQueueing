// Node1.h
#ifndef __TWONODEQUEUEING_NODE1_H_
#define __TWONODEQUEUEING_NODE1_H_

#include <omnetpp.h>
#include "Job_m.h"

using namespace omnetpp;

class Node1 : public cSimpleModule {
  private:
    cQueue queueU1;
    cQueue queueU2;
    cMessage *endServiceEvent;
    Job *jobInService;
    bool isBusy;

    simsignal_t qLenSignalU1;
    simsignal_t qLenSignalU2;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void startNextJob();
};

#endif
