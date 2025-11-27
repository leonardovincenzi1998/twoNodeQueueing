// Node2.h
#ifndef __TWONODEQUEUEING_NODE2_H_
#define __TWONODEQUEUEING_NODE2_H_

#include <omnetpp.h>
#include "Job_m.h"

using namespace omnetpp;

class Node2 : public cSimpleModule {
  private:
    cQueue queueSS1;
    cQueue queueSS2;
    cMessage *endServiceSS1Event;
    cMessage *endServiceSS2Event;
    Job *jobInServiceSS1;
    Job *jobInServiceSS2;
    bool isBusySS1;
    bool isBusySS2;

    simsignal_t qLenSignalSS1;
    simsignal_t qLenSignalSS2;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void startNextJobSS1();
    void startNextJobSS2();
};
#endif
