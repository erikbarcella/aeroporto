#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct aviao Aviao;
struct aviao {
    Aviao *proximo;
    Aviao *anterior;
    char modelo[40];
    char prefixo[10];
    char companhia[20];
    };

//assinaturas
Aviao * cria_aviao(Aviao *a);
Aviao * set_aviao(Aviao*a, char *mod, char *prefix, char *cia);
void view_aviao(Aviao* a);
int salvar_arq (Aviao *lista);
int qntdAviao();
Aviao *inicializarAvioes();








