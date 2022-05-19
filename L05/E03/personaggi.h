#include "inventario.h"

typedef struct{
    char codice[7];
    char nome[50];
    char classe[50];
    stat statistiche;
    Inventario *vettEq[8];
}pg;

typedef struct{
    pg val;
    struct nodo* successivo;
} nodo;

void Stampapg(nodo *testa);
nodo *listInsTail(nodo *testa,pg val);
nodo *fileins(nodo *testa);
void Ricerca(nodo *testa);
nodo *aggiungi(nodo *testa);
void cancellazione_per_codice(nodo* *hp);
void newOggetto(nodo *testa, Inventario *inv, int n);
void oldOggetto(nodo *testa, Inventario *inv, int n);
void cntstat(nodo *testa);