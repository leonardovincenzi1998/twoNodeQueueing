# 📊 Analisi di un Sistema a Coda Distribuito
### Progetto n. 8: Rete a due nodi con feedback ritardato

![OMNeT++](https://img.shields.io/badge/Simulatore-OMNeT%2B%2B-blue)
![Language](https://img.shields.io/badge/Linguaggio-C%2B%2B-orange)

## 1. Introduzione e Abstract

Il presente progetto si pone l’obiettivo di analizzare le prestazioni di un **sistema a coda distribuito**, modellando una rete a due nodi con meccanismi di feedback ritardato. La simulazione è realizzata mediante il framework **OMNeT++**.

L'analisi si concentra sulla risposta del sistema sotto carico e sulla gestione differenziata dell'utenza.



---

## 📚 Modello di Riferimento

Il lavoro si basa su una variante specifica del sistema descritto nella seguente letteratura scientifica:

> **Articolo:** *"Response times in a two-node queueing network with feedback"*
>
> **Autori:** R.D. van der Mei et al.

---

## ⚙️ Specifiche del Progetto (Variante n. 8)

A differenza del modello originale, che prevede un nodo *Processor Sharing (PS)* e un nodo *FCFS* generico, la variante oggetto di questo studio introduce complessità specifiche legate alla gestione dell'utenza.

### Differenze Chiave:

* **👥 Tipologie di Utenti:**
    Il sistema gestisce due distinte classi di utenti, denominate `U1` e `U2`.

* **⚡ Priorità:**
    Tali utenti sono caratterizzati da **diverse priorità di servizio**, influenzando l'ordine di schedulazione e processamento.

* **🔀 Instradamento (Routing):**
    Sono definiti instradamenti specifici all’interno della rete per ciascuna tipologia di utente (es. probabilità di feedback o percorso tra i nodi).

---

## 📈 Obiettivi della Simulazione

La simulazione mira a stimare misure di prestazione critiche (KPI) per valutare l'efficienza del sistema:

1.  Lunghezza media della coda (per tutti i serventi) relativa a tutti gli utenti e alle singole tipologie di utenti.
2.  Tempo di soggiorno nel sistema relativo a tutti gli utenti e alle singole tipologie di utenti.
3.  Stima del tempo massimo (minimo) di permanenza nel sistema degli utenti per tipologia.
4.  Stima della percentuale di utenti che superano una determinata soglia critica di permanenza.

---

## 🛠️ Tecnologie Utilizzate

* **OMNeT++:** Framework di simulazione a eventi discreti.
* **C++:** Logica dei moduli e gestione dei messaggi.
* **Python:** Notebook per elaborazione risultati.
