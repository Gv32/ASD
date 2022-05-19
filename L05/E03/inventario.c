#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"

Inventario *fileinsinv(Inventario *inventario, int *nInventario){
    FILE *fin;
    int n;
    fin=fopen("../inventario.txt","r");
    fscanf(fin,"%d",&n);
    inventario=malloc(n* sizeof(Inventario));
    for(int i=0;i<n;i++){
        fscanf(fin,"%s %s %d %d %d %d %d %d",inventario[i].nome,inventario[i].tipologia,&inventario[i].statistiche.hp,&inventario[i].statistiche.mp,&inventario[i].statistiche.atk,&inventario[i].statistiche.def,&inventario[i].statistiche.mag,&inventario[i].statistiche.spr);
    }
    *nInventario=n;
    return inventario;
}

void stampainv(Inventario *inv, int n){
    for (int i = 0; i<n ; i++){
        printf("%s %s %d %d %d %d %d %d\n",inv[i].nome,inv[i].tipologia,inv[i].statistiche.hp,inv[i].statistiche.mp,inv[i].statistiche.atk,inv[i].statistiche.def,inv[i].statistiche.mag,inv[i].statistiche.spr);
    }
}

void ricercainv(Inventario *inv, int n){
    char nome[50];
    printf("Inserire il nome dell'oggetto\n");
    scanf("%s",nome);
    for (int i = 0; i<n ; i++) {
        if (strcmp(nome, inv[i].nome) == 0) {
            printf("%s %s %d %d %d %d %d %d\n", inv[i].nome, inv[i].tipologia, inv[i].statistiche.hp, inv[i].statistiche.mp,
                   inv[i].statistiche.atk, inv[i].statistiche.def, inv[i].statistiche.mag, inv[i].statistiche.spr);
        }
    }
}

