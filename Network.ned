package TwoNodeQueueing.simulations;// Network.ned
// Modulo semplice per la sorgente di utenti
simple Source
{
    parameters:
        volatile double interArrivalTime @unit(s); // Media m dei tempi di interarrivo [cite: 603]
        volatile double userTypeProbability; // Probabilità q che un utente sia di tipo U1 [cite: 601]
    gates:
        output out;
}

// Modulo semplice per il primo nodo di servizio (coda a priorità + servente)
simple Node1
{
    parameters:
        volatile double serviceTimeU1_a @unit(s); // Parametro 'a' per servizio U1 [cite: 604]
        volatile double serviceTimeU1_b @unit(s); // Parametro 'b' per servizio U1 [cite: 604]
        volatile double serviceTimeU2_c @unit(s); // Parametro 'c' per servizio U2 [cite: 605]
        volatile double serviceTimeU2_d @unit(s); // Parametro 'd' per servizio U2 [cite: 605]
        volatile double feedbackProbability; // Probabilità p di andare al nodo 2 [cite: 606]
        @signal[queueLenNode1_U1]; // Segnale per la lunghezza coda U1
        @signal[queueLenNode1_U2]; // Segnale per la lunghezza coda U2
		@statistic[queueLenNode1_U1](title="Queue Length Node 1 U1"; source="queueLenNode1_U1"; record=timeavg; interpolationmode=sample-hold);
        @statistic[queueLenNode1_U2](title="Queue Length Node 1 U2"; source="queueLenNode1_U2"; record=timeavg; interpolationmode=sample-hold);
    gates:
        input in[]; // Gate vettoriale per ricevere più ingressi (nuovi + feedback)
        output toNode2;
        output toSink;
}

// Modulo semplice per il secondo nodo (2 serventi dedicati)
simple Node2
{
    parameters:
        volatile double serviceTimeSS1 @unit(s); // Media m(SS1) per servizio U1 [cite: 609]
        volatile double serviceTimeSS2 @unit(s); // Media m(SS2) per servizio U2 [cite: 609]
        @signal[queueLenSS1]; // Segnale per la lunghezza coda SS1 (U1)
        @signal[queueLenSS2]; // Segnale per la lunghezza coda SS2 (U2)
   		@statistic[queueLenSS1](title="Queue Length SS1"; source="queueLenSS1"; record=timeavg; interpolationmode=sample-hold);
        @statistic[queueLenSS2](title="Queue Length SS2"; source="queueLenSS2"; record=timeavg; interpolationmode=sample-hold);
    gates:
        input in;
        output out; // Uscita per il feedback
}

// Modulo semplice per il sink (calcola le statistiche finali)
simple Sink
{
    parameters:
        @signal[sojournTimeU1];
        @signal[sojournTimeU2];
        @statistic[sojournTimeU1](title="Sojourn Time U1"; unit=s; source="sojournTimeU1"; record=vector,stats; interpolationmode=none);
        @statistic[sojournTimeU2](title="Sojourn Time U2"; unit=s; source="sojournTimeU2"; record=vector,stats; interpolationmode=none);
    gates:
        input in;
}

// Definizione della rete completa
network TwoNodeNetwork
{
    submodules:
        source: Source;
		node1: Node1 {
            gates:
                in[2];  // ✅ 2 ingressi: uno per la sorgente, uno per il feedback
        }        node2: Node2;
        sink: Sink;
        
    connections:
    source.out --> node1.in[0];   // nuovi arrivi
	node2.out   --> node1.in[1];  // feedback
	node1.toNode2 --> node2.in;
	node1.toSink  --> sink.in;
}