#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"avioes.h"

FILE *arq_aviao;
int qtdAviao=0;


Aviao * cria_aviao(Aviao *a) {
    return (NULL);
}


//arrumar funcao
int inicializarAvioes() {
    arq_aviao=fopen("aviao.dat", "r+b");
    if (arq_aviao==NULL)
    {
        printf("ERRO \n");
        system("pause");
        exit(1);
    }
   
   fseek(arq_aviao, 0, SEEK_END);
   int qtd_bytes=ftell(arq_aviao);
   qtdAviao=((qtd_bytes/sizeof(Aviao)));
   fseek(arq_aviao,0,SEEK_SET);

    int total_lido=fread(/*local para guardar os dados*/,sizeof(Aviao),qtdAviao,arq_aviao);

    if (total_lido!=qtdAviao)
    {
        printf("Erro na leitura do arquivo \n");
        system("pause");
        exit(1);
    }
    return 1;
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

//arrumar funcao
/* int encerraAvioes() {
    fseek(arq_aviao, 0, SEEK_SET);
    int total_gravado=fwrite(hangar,sizeof(Aviao),qtdAviao,arq_aviao);
    if (total_gravado!=qtdAviao)
    {
        printf("Erro na escrita do arquivo \n");
        system("pause");
        exit(1);
    }

    void free_lista(Aviao ** pl)
    {
      while (*pl != NULL)
      {
           Aviao * t = (*pl)->proximo;
           *pl = NULL;
           free(*pl);
           *pl = t;
      }
    }
   
   fclose(arq_aviao);
   return 1;
} */