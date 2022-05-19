typedef struct {
    int hp;
    int mp;
    int atk;
    int def;
    int mag;
    int spr;
}stat;

typedef struct {
    char nome[50];
    char tipologia[50];
    stat statistiche;
}Inventario;

Inventario *fileinsinv(Inventario *inv, int *n);
void stampainv(Inventario *inv, int n);
void ricercainv(Inventario *inv, int n);