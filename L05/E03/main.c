#include "personaggi.h"
#include <stdio.h>

int main() {
    int scelta,x=1,n;
    nodo *personaggitesta = NULL;
    Inventario *inv = NULL;
    inv = fileinsinv(inv,&n);
    while (x==1){
        printf("Inserire:\n1 per caricare in una lista i personaggi da file\n"
               "2 per stampare la lista dei personaggi e relativo inventario\n"
               "3 per aggiungere un personaggio\n4 per eliminare un personaggio\n"
               "5 per ricercare un personaggio tramite codice\n"
               "6 per aggiungere un oggetto all' equipaggiamento di un personaggio\n"
               "7 per eliminare un oggetto dall'equipaggiamento di un personaggio\n"
               "8 vedere le statistiche di un personaggio in base all'inventario\n9 per concludere\n");
        scanf("%d",&scelta);
        switch(scelta){
            case 1:
                personaggitesta=fileins(personaggitesta);
                break;
            case 2:
                Stampapg(personaggitesta);
                break;
            case 3:
                personaggitesta = aggiungi(personaggitesta);
                break;
            case 4:
                cancellazione_per_codice(&personaggitesta);
                break;
            case 5:
                Ricerca(personaggitesta);
                break;
            case 6:
                newOggetto(personaggitesta,inv,n);
                break;
            case 7:
                oldOggetto(personaggitesta,inv,n);
                break;
            case 8:
                cntstat(personaggitesta);
                break;
            case 9:
                x = -1;
                break;
        }
    }
}