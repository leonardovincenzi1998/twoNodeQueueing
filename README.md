Analisi di un Sistema a Coda Distribuito (Progetto n. 8)
1. Introduzione e Abstract
Il presente progetto si pone l’obiettivo di analizzare le prestazioni di un sistema a coda distribuito, modellando una rete a due nodi con meccanismi di feedback ritardato. La simulazione è realizzata mediante il framework OMNeT++.

Modello di Riferimento
Il lavoro si basa su una variante specifica del sistema descritto nel seguente articolo:

"Response times in a two-node queueing network with feedback" R.D. van der Mei et al.

Differenze e Specifiche del Progetto
A differenza del modello originale (che prevede un nodo Processor Sharing - PS e un nodo FCFS generico), la variante oggetto di studio (Progetto n. 8) introduce complessità aggiuntive legate alla gestione dell'utenza:

Tipologie di Utenti: Introduzione di due classi distinte, U1 e U2.

Priorità: Gli utenti sono caratterizzati da diverse priorità di servizio.

Routing: Sono definiti instradamenti specifici all'interno della rete per ciascuna tipologia di utente.

Obiettivi della Simulazione
L'analisi mira a stimare le seguenti misure critiche di prestazione:

Length media delle code.

Tempi di soggiorno nel sistema (Response Time).

Percentuale di utenti che superano una determinata soglia di permanenza.

Suggerimenti per l'uso nel README
Badges: Potresti aggiungere dei badge in alto per indicare il linguaggio (C++) e il framework (OMNeT++).

Diagramma: Poiché il testo descrive una topologia di rete specifica, sarebbe molto utile inserire un'immagine del grafo dei nodi subito dopo l'introduzione.
