
#ifndef __TWONODEQUEUEING_SINK_H_
#define __TWONODEQUEUEING_SINK_H_
// Sink.h

#include <omnetpp.h>
#include "Job_m.h"

using namespace omnetpp;

class Sink : public cSimpleModule {
  private:
    simsignal_t sojournTimeU1Signal;
    simsignal_t sojournTimeU2Signal;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
#endif
