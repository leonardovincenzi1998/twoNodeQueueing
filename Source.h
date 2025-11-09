#ifndef __TWONODEQUEUEING_SOURCE_H_
#define __TWONODEQUEUEING_SOURCE_H_
// Source.h

#include <omnetpp.h>
#include "Job_m.h"

using namespace omnetpp;

class Source : public cSimpleModule {
  private:
    cMessage *sendMessageEvent;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
