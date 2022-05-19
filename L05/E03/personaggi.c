#include "personaggi.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

nodo* newNode(nodo *successivo , pg val) {
    nodo* x = malloc(sizeof *x);
    if (x==NULL)
        return NULL;
    else {
        strcpy(x->val.codice,val.codice);
        strcpy(x->val.nome,val.nome);
        strcpy(x->val.classe,val.classe);
        x->val.statistiche.hp=val.statistiche.hp;
        x->val.statistiche.mp=val.statistiche.mp;
        x->val.statistiche.atk=val.statistiche.atk;
        x->val.statistiche.def=val.statistiche.def;
        x->val.statistiche.mag=val.statistiche.mag;
        x->val.statistiche.spr=val.statistiche.spr;
        for(int i=0;i<8;i++){
            x->val.vettEq[i]=NULL;
        }
        x->successivo = successivo;
    }
    return x;
}

nodo* fileins(nodo* h){
    FILE *fin;
    pg personaggio;
    char nomefile[30];
    printf("Inserire nome file\n");
    scanf("%s",nomefile);
    fin=fopen(nomefile,"r");
    while (!feof(fin)){
        fscanf(fin,"%s",personaggio.codice);
        fscanf(fin,"%s",personaggio.nome);
        fscanf(fin,"%s",personaggio.classe);
        fscanf(fin,"%d %d %d %d %d %d",&personaggio.statistiche.hp,&personaggio.statistiche.mp,&personaggio.statistiche.atk,&personaggio.statistiche.def,&personaggio.statistiche.mag,&personaggio.statistiche.spr);
        h = listInsTail(h,personaggio);
    }
    return h;
}

void Stampapg(nodo *personaggitesta){
    while(personaggitesta!=NULL) {
        printf("%s %s %s %d %d %d %d %d %d\n", personaggitesta->val.codice, personaggitesta->val.nome, personaggitesta->val.classe, personaggitesta->val.statistiche.hp, personaggitesta->val.statistiche.mp, personaggitesta->val.statistiche.atk, personaggitesta->val.statistiche.def, personaggitesta->val.statistiche.mag, personaggitesta->val.statistiche.spr);
        for(int i = 0;i < 8 ; i++){
            if(personaggitesta->val.vettEq[i]!=NULL){
                printf("|->%s %s %d %d %d %d %d %d\n",personaggitesta->val.vettEq[i]->nome,personaggitesta->val.vettEq[i]->tipologia,personaggitesta->val.vettEq[i]->statistiche.hp,personaggitesta->val.vettEq[i]->statistiche.mp,personaggitesta->val.vettEq[i]->statistiche.atk,personaggitesta->val.vettEq[i]->statistiche.def,personaggitesta->val.vettEq[i]->statistiche.mag,personaggitesta->val.vettEq[i]->statistiche.spr);
            }
        }
        personaggitesta=personaggitesta->successivo;
    }
    printf("\n");
}

void cntstat(nodo *personaggitesta){
    while(personaggitesta!=NULL) {
        int cnthp=0,cntmp=0,cntatk=0,cntdef=0,cntmag=0,cntspr=0;
        for(int i = 0;i < 8 ; i++){
            if(personaggitesta->val.vettEq[i]!=NULL){
                cnthp = cnthp + personaggitesta->val.vettEq[i]->statistiche.hp;
                cntmp = cntmp + personaggitesta->val.vettEq[i]->statistiche.mp;
                cntatk = cntatk + personaggitesta->val.vettEq[i]->statistiche.atk;
                cntdef = cntdef + personaggitesta->val.vettEq[i]->statistiche.def;
                cntmag = cntmag + personaggitesta->val.vettEq[i]->statistiche.mag;
                cntspr = cntspr + personaggitesta->val.vettEq[i]->statistiche.spr;
            }
        }
        if((cnthp+personaggitesta->val.statistiche.hp) < 0) cnthp = -personaggitesta->val.statistiche.hp;
        if((cntmp+personaggitesta->val.statistiche.mp) < 0) cntmp = -personaggitesta->val.statistiche.mp;
        if((cntatk+personaggitesta->val.statistiche.atk) < 0) cntatk = -personaggitesta->val.statistiche.atk;
        if((cntdef+personaggitesta->val.statistiche.def) < 0) cntdef = -personaggitesta->val.statistiche.def;
        if((cntmag+personaggitesta->val.statistiche.mag) < 0) cntmag = -personaggitesta->val.statistiche.mag;
        if((cntspr+personaggitesta->val.statistiche.spr) < 0) cntspr = -personaggitesta->val.statistiche.spr;
        printf("%s %s %s %d %d %d %d %d %d\n", personaggitesta->val.codice, personaggitesta->val.nome, personaggitesta->val.classe, personaggitesta->val.statistiche.hp + cnthp, personaggitesta->val.statistiche.mp + cntmp, personaggitesta->val.statistiche.atk + cntatk, personaggitesta->val.statistiche.def + cntdef, personaggitesta->val.statistiche.mag + cntmag, personaggitesta->val.statistiche.spr + cntspr);
        personaggitesta=personaggitesta->successivo;
    }
    printf("\n");
}

nodo* listInsTail(nodo* h,pg val) {
    nodo* x;
    if (h==NULL) {
        return newNode(NULL,val);
    }
    for(x=h; x->successivo!=NULL; x=x->successivo);
    x->successivo=newNode(NULL,val);
    return h;
}

void Ricerca(nodo *lista){
    char codicer[7];
    printf("Inserire il codice da ricercare\n");
    scanf("%s",codicer);
    if(lista != NULL){
        while(lista != NULL){
            if(strcmp(codicer,lista->val.codice)==0) {
                printf("%s %s %s %d %d %d %d %d %d\n", lista->val.codice,lista->val.nome,lista->val.classe,lista->val.statistiche.hp,lista->val.statistiche.mp,lista->val.statistiche.atk,lista->val.statistiche.def,lista->val.statistiche.mag,lista->val.statistiche.spr);
                for(int i = 0;i < 8 ; i++){
                    if(lista->val.vettEq[i]!=NULL){
                        printf("|->%s %s %d %d %d %d %d %d\n",lista->val.vettEq[i]->nome,lista->val.vettEq[i]->tipologia,lista->val.vettEq[i]->statistiche.hp,lista->val.vettEq[i]->statistiche.mp,lista->val.vettEq[i]->statistiche.atk,lista->val.vettEq[i]->statistiche.def,lista->val.vettEq[i]->statistiche.mag,lista->val.vettEq[i]->statistiche.spr);
                    }
                }
                return;
            }
            lista = lista -> successivo;
        }
        printf("Peronaggio non trovato\n");
    }
    else {
        printf("LISTA VUOTA \n");
    }
}

nodo* aggiungi(nodo *personaggitesta){
    pg tmp;
    printf("Inserire in ordine:\n"
           "codice nome classe hp mp atk def mag spr;");
    scanf("%s %s %s %d %d %d %d %d %d",tmp.codice,tmp.nome,tmp.classe,&tmp.statistiche.hp,&tmp.statistiche.mp,&tmp.statistiche.atk,&tmp.statistiche.def,&tmp.statistiche.mag,&tmp.statistiche.spr);
    personaggitesta = listInsTail(personaggitesta,tmp);
    return personaggitesta;
}

void cancellazione_per_codice(nodo* *hp) {
    nodo* h;
    nodo* x;
    nodo* p;
    h=*hp;
    char codice[7];
    printf("Inserire il codice dell'personaggio da eliminare\n");
    Stampapg(*hp);
    scanf("%s", codice);
    for (x=h, p=NULL; x!=NULL; p=x, x=x->successivo) {
        if (strcmp(x->val.codice, codice) == 0){
            if (h==x){
                *hp=h->successivo;
                free(h);
                printf("Personaggio eliminato\n");
            }
            else{
                p->successivo = x->successivo;
                free(x);
                printf("Personaggio eliminato\n");
            }
        }
    }
}

void newOggetto(nodo *h, Inventario *inv, int n){
    char codice[7];
    nodo *lista = h;
    char scelta[50];
    printf("Inserire il codice del personaggio\n");
    scanf("%s",codice);
    if(lista != NULL){
        while(lista != NULL){
            if(strcmp(codice,lista->val.codice)==0) {
                printf("Personaggio:\n%s %s %s %d %d %d %d %d %d\n\n", lista->val.codice,lista->val.nome,lista->val.classe,lista->val.statistiche.hp,lista->val.statistiche.mp,lista->val.statistiche.atk,lista->val.statistiche.def,lista->val.statistiche.mag,lista->val.statistiche.spr);
                printf("Inventario disponibile:\n\n");
                stampainv(inv,n);
                printf("\n");
                printf("Inserire il nome dell'equipaggiamento da aggiungere:\n");
                scanf("%s",scelta);
                for(int i = 0;i<n;i++){
                    if(strcmp(scelta,inv[i].nome)==0){
                        for (int j = 0; j < 8; ++j) {
                            if(lista->val.vettEq[j]==NULL){
                                lista->val.vettEq[j]=&inv[i];
                                break;
                            }
                        }
                        break;
                    }
                }
                return;
            }
            lista = lista -> successivo;
        }
        printf("Personaggio non trovato\n");
    }
}

void oldOggetto(nodo *h,Inventario *inv, int n){
    char codice[7];
    nodo *lista = h;
    char scelta[50];
    printf("Inserire il codice del personaggio:\n");
    scanf("%s",codice);
    while(lista != NULL){
        if(strcmp(codice,lista->val.codice)==0) {
            printf("Personaggio:\n%s %s %s %d %d %d %d %d %d\n\n", lista->val.codice,lista->val.nome,lista->val.classe,lista->val.statistiche.hp,lista->val.statistiche.mp,lista->val.statistiche.atk,lista->val.statistiche.def,lista->val.statistiche.mag,lista->val.statistiche.spr);
            for(int i = 0;i < 8 ; i++){
                if(lista->val.vettEq[i]!=NULL){
                    printf("|->%s %s %d %d %d %d %d %d\n",lista->val.vettEq[i]->nome,lista->val.vettEq[i]->tipologia,lista->val.vettEq[i]->statistiche.hp,lista->val.vettEq[i]->statistiche.mp,lista->val.vettEq[i]->statistiche.atk,lista->val.vettEq[i]->statistiche.def,lista->val.vettEq[i]->statistiche.mag,lista->val.vettEq[i]->statistiche.spr);
                }
            }
            printf("\n");
            printf("Inserire il nome dell'equipaggiamento da eliminare:\n");
            scanf("%s",scelta);
            for(int i = 0;i<n;i++) {
                if(strcmp(scelta,lista->val.vettEq[i]->nome)==0){
                    lista->val.vettEq[i]=NULL;
                    break;
                }
            }
            return;
        }
        lista = lista -> successivo;
    }
}