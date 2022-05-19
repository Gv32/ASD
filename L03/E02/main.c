#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char **scelte;
    int num_scelte;
}livello;

int princ_molt(int pos, livello *val, char **sol, int k, int count) {
    int i;
    if (pos >= k) {
        for (i = 0; i < k; i++)
            printf("%s\n", sol[i]);
        printf("\n");
        return count+1;
    }
    for (i = 0; i < val[pos].num_scelte; i++) {
        strcpy(sol[pos],val[pos].scelte[i]);
        count = princ_molt(pos+1, val, sol, k, count);
    }
    return count;
}

int main() {
    FILE *fp_read;
    int n,i,j,total;
    char **sol;
    livello *val;
    if((fp_read=fopen("../brani.txt", "r"))==NULL)
        return -1;
    fscanf(fp_read,"%d",&n);
    val=malloc(n*sizeof(livello));
    if(val==NULL)
        return -1;
    for(i=0;i<n;i++) {
        fscanf(fp_read,"%d", &val[i].num_scelte);
        val[i].scelte = malloc(val[i].num_scelte * sizeof(char *));
        if(val[i].scelte==NULL)
            exit(1);
        for(j=0;j<val[i].num_scelte;j++){
            val[i].scelte[j]=malloc(255*sizeof(char));
            if(val[i].scelte[j]==NULL)
                exit(1);
            fscanf(fp_read,"%s", val[i].scelte[j]);
        }
    }
    sol=malloc(n*(sizeof(char*)));
    for(i=0;i<n;i++){
        sol[i]=malloc(255* sizeof(char));
    }
    total = princ_molt(0, val, sol, n, 0);
    printf("Totale playlist: %d",total);
    free(sol);
    for(i=0;i<n;i++){
        free(val[i].scelte);
    }
    free(val);
}