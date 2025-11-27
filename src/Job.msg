// Job.msg
cplusplus {{
#include <omnetpp.h>
}}

// Messaggio che rappresenta un utente/job nel sistema
message Job {
    int type; // 1 per Utente U1, 2 per Utente U2
    simtime_t creationTime; // Timestamp di creazione per calcolare il sojourn time
}