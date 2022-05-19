#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int giorno;
    int mese;
    int anno;
}data;

typedef struct {
    char codice[6];
    char nome[50];
    char cognome[50];
    data data_nascita;
    char via[50];
    char citta[50];
    int cap;
} item;

typedef struct{
    item val;
    struct nodo* successivo;
} nodo;

nodo* newNode(nodo *successivo , item val) {
    nodo* x = malloc(sizeof *x);
    if (x==NULL)
        return NULL;
    else {
        strcpy(x->val.codice,val.codice);
        strcpy(x->val.nome,val.nome);
        strcpy(x->val.cognome,val.cognome);
        x->val.data_nascita.giorno=val.data_nascita.giorno;
        x->val.data_nascita.mese=val.data_nascita.mese;
        x->val.data_nascita.anno=val.data_nascita.anno;
        strcpy(x->val.via,val.via);
        strcpy(x->val.citta,val.citta);
        x->val.cap = val.cap;
        x->successivo = successivo
                ; }
    return x;
}

nodo* inserimento_ordinato(nodo* h, item elemento) {
    nodo* x;
    nodo* p;
    if (h==NULL || h->val.data_nascita.anno < elemento.data_nascita.anno)
        return newNode(h, elemento);
    for (x=h->successivo, p=h;
         x!=NULL && x->val.data_nascita.anno > elemento.data_nascita.anno;
         p=x, x=x->successivo);
    p->successivo = newNode(x, elemento);
    return h;
}

void StampaLista(nodo *h) {
    while(h!=NULL) {
        printf("%s %s %s %d/%d/%d %s %s %d\n", h->val.codice, h->val.nome, h->val.cognome, h->val.data_nascita.giorno,h->val.data_nascita.mese,h->val.data_nascita.anno, h->val.via, h->val.citta, h->val.cap);
        h=h->successivo;
    }
    printf("\n");
}

void scrivi_file(nodo* h){
    nodo* x;
    x=h;
    FILE *fout;
    char nomefile[50];
    printf("Inserire il nome del file in cui salvare la lista\n");
    scanf("%s",nomefile);
    fout= fopen(nomefile, "w");
    while(x != NULL){
        fprintf(fout,"%s %s %s %d/%d/%d %s %s %d\n",x->val.codice, x->val.nome,x->val.cognome,x->val.data_nascita.giorno, x->val.data_nascita.mese, x->val.data_nascita.anno, x->val.via, x->val.citta, x->val.cap);
        x=x->successivo;
    }
    fclose(fout);
}

nodo* ricerca(nodo *lista, char *codice){
    if(lista != NULL){
        while(lista != NULL){
            if(strcmp(codice,lista->val.codice)==0) {
                return lista;
            }
            lista = lista -> successivo;
        }
        printf("Elemento non trovato\n");
    }
    else {
        printf("LISTA VUOTA \n");
    }
}

nodo* cancellazione_per_codice(nodo* *hp,char *codice) {
    nodo* h;
    nodo* x;
    nodo* p;
    h=*hp;
    for (x=h, p=NULL; x!=NULL; p=x, x=x->successivo) {
        if (strcmp(x->val.codice, codice) == 0){
            if (h==x){
                *hp=h->successivo;
                return x;
            }
            else{
                p->successivo = x->successivo;
                return x;
            }
        }
    }
}

nodo* intervalli(nodo* *hp, data d1, data d2){
    nodo* x;
    nodo* h;
    nodo* p;
    h=*hp;
    for (x=h, p=NULL; x!=NULL; p=x, x=x->successivo) {
        if (d1.anno < x->val.data_nascita.anno &&  x->val.data_nascita.anno< d2.anno){
            if (h==x){
                *hp=h->successivo;
                return x;
            }
            else{
                p->successivo = x->successivo;
                return x;
            }
        }
        if(d1.anno == x->val.data_nascita.anno){
            if(d1.mese < x->val.data_nascita.mese){
                if (h==x){
                    *hp=h->successivo;
                    return x;
                }
                else{
                    p->successivo = x->successivo;
                    return x;
                }
            }
        }
        if(d2.anno == x->val.data_nascita.anno){
            if(d2.mese > x->val.data_nascita.mese){
                if (h==x){
                    *hp=h->successivo;
                    return x;
                }
                else{
                    p->successivo = x->successivo;
                    return x;
                }
            }
        }
        if(d1.mese == x->val.data_nascita.mese){
            if(d1.giorno < x->val.data_nascita.giorno){
                if (h==x){
                    *hp=h->successivo;
                    return x;
                }
                else{
                    p->successivo = x->successivo;
                    return x;
                }
            }
        }
        if(d2.mese == x->val.data_nascita.mese){
            if(d2.giorno > x->val.data_nascita.giorno){
                if (h==x){
                    *hp=h->successivo;
                    return x;
                }
                else{
                    p->successivo = x->successivo;
                    return x;
                }
            }
        }
    }
    return NULL;
}

int main() {
    FILE *fin;
    char nomefile[50];
    char codicer[6];
    nodo* canc= malloc(sizeof (nodo*));
    item tmp;
    data d1,d2;
    int scelta;
    int continua = 0;
    nodo *trovato;
    nodo *lista=NULL;
    while(continua == 0){
        printf("Inserire:\n-1 per terminare il ciclo\n1 per aprire un file e leggerlo\n2 per salvare la lista su un file\n3 per visualizzare la lista\n4 per inserire manualmente i dati relativi a una persona\n"
               "5 per ricercare tramite codice\n6 per eliminare tramite codice\n7 per eliminare tramite un intervallo di date\n");
        scanf("%d", &scelta);
        switch(scelta) {
            case -1:
                continua = 1;
                break;
            case 1:
                printf("Inserire il nome del file da cui prendere i dati\n");
                scanf("%s",nomefile);
                if((fin= fopen(nomefile, "r"))==NULL){
                    printf("Errore apertura file\n");
                    break;
                }
                while(!feof(fin)){
                    fscanf(fin,"%s %s %s %d/%d/%d %s %s %d",tmp.codice,tmp.nome,tmp.cognome,&tmp.data_nascita.giorno,&tmp.data_nascita.mese,&tmp.data_nascita.anno,tmp.via,tmp.citta,&tmp.cap);
                    lista = inserimento_ordinato(lista,tmp);
                }
                fclose(fin);
                break;
            case 2:
                scrivi_file(lista);
                break;
            case 3:
                StampaLista(lista);
                break;
            case 4:
                printf("Inserire in ordine: codice, nome, cognome, data di nascita in formato gg/mm/aaaa, via, citta, cap\n");
                scanf("%s %s %s %d/%d/%d %s %s %d",tmp.codice,tmp.nome,tmp.cognome,&tmp.data_nascita.giorno,&tmp.data_nascita.mese,&tmp.data_nascita.anno,tmp.via,tmp.citta,&tmp.cap);
                lista = inserimento_ordinato(lista,tmp);
                break;
            case 5:
                printf("Inserire il codice da ricercare:\n");
                scanf("%s",codicer);
                trovato = ricerca(lista,codicer);
                printf("%s %s %s %d/%d/%d %s %s %d\n", trovato->val.codice, trovato->val.nome, trovato->val.cognome, trovato->val.data_nascita.giorno,trovato->val.data_nascita.mese,trovato->val.data_nascita.anno, trovato->val.via, trovato->val.citta, trovato->val.cap);
                break;
            case 6:
                printf("Inserire il codice da cancellare:\n");
                scanf("%s",codicer);
                trovato = cancellazione_per_codice(&lista,codicer);
                printf("%s %s %s %d/%d/%d %s %s %d\n", trovato->val.codice, trovato->val.nome, trovato->val.cognome, trovato->val.data_nascita.giorno,trovato->val.data_nascita.mese,trovato->val.data_nascita.anno, trovato->val.via, trovato->val.citta, trovato->val.cap);
                free(trovato);
                break;
            case 7:
                printf("Inserire la data 1:\n");
                scanf("%d/%d/%d", &d1.giorno, &d1.mese, &d1.anno);
                printf("Inserire la data 2:\n");
                scanf("%d/%d/%d", &d2.giorno, &d2.mese, &d2.anno);
                while (canc!=NULL){
                    canc=intervalli(&lista,d1,d2);
                    if(canc!=NULL){
                        printf("L'elemento cancellato e': %s %s %s %d/%d/%d %s %s %d\n", canc->val.codice, canc->val.nome, canc->val.cognome, canc->val.data_nascita.giorno,canc->val.data_nascita.mese,canc->val.data_nascita.anno, canc->val.via, canc->val.citta, canc->val.cap);
                        free(canc);
                    }
                }
                break;
        }
    }
}