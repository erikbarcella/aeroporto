#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct aviao Aviao;
struct aviao {
    Aviao *proximo;
    Aviao *anterior;
    char *modelo[40];
    char *prefixo[10];
    char *companhia[20];
};

Aviao * cria_aviao(Aviao *a) {
    return (NULL);
}

Aviao * set_aviao(Aviao*a, char *mod, char *prefix, char *cia) {
    Aviao* novo = (Aviao*) malloc (sizeof(Aviao));
    strcpy(novo->modelo, mod);
    strcpy(novo->prefixo, prefix);
    strcpy(novo->companhia, cia);

    if(a==NULL) novo->proximo=novo; //ele recebe ele mesmo
    else{
        novo->anterior=a;
        novo->proximo=a->proximo;
        a->proximo=novo;
    }
    return(novo);
}

void view_aviao(Aviao* a) {

    Aviao* aux=a;
    if (a!=NULL) do
    {
        printf("modelo %s -prefixo %s - companhia aerea %s- atual: %p \t-  prox: %p \t-  ant: %p \n", a->modelo,a->prefixo, a->companhia, a,  a->proximo, a->anterior);
        a = a->proximo; //avanca no
    } while (aux!=a);

}

