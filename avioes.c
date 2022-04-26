#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"avioes.h"

FILE *arq_aviao;
int qtdAviao=0;

Aviao * cria_aviao(Aviao *a) {
    return (NULL);
}

int qntdAviao() {
    return qtdAviao;
}

//arrumar funcao
Aviao *inicializarAvioes(Aviao *l) {

    arq_aviao=fopen("avioes.bin", "r+b");
    if (arq_aviao==NULL)
    {
        printf("ERRO \n");
        system("pause");
        exit(1);
    }
    if (ftell(arq_aviao)!=0) {

        while (!feof(arq_aviao)) {

        Aviao *storage=(Aviao*)malloc(sizeof(Aviao));
        fread(storage,sizeof(Aviao), 1, arq_aviao);
        l=set_aviao(storage, storage->modelo, storage->prefixo, storage->companhia);
        }
    }
    fclose(arq_aviao);
    return l;
}


Aviao * set_aviao(Aviao*a, char *mod, char *prefix, char *cia) {
    Aviao* novo = (Aviao*) malloc (sizeof(Aviao));
    strcpy(novo->modelo, mod);
    strcpy(novo->prefixo, prefix);
    strcpy(novo->companhia, cia);
    

    if(a==NULL) {
        novo->proximo=novo; //ele recebe ele mesmo
        novo->id=1;
        qtdAviao++;
    }
        else{
        novo->anterior=a;
        novo->proximo=a->proximo;
        a->proximo=novo;
        qtdAviao++;
        novo->id=qtdAviao;
    }
    
    return(novo);
}

void view_aviao(Aviao* a) {

    Aviao* aux=a;
    if (a!=NULL) do
    {
        printf("id: %d - modelo %s -prefixo %s - companhia aerea %s- atual: %p \t-  prox: %p \t-  ant: %p \n",a->id, a->modelo,a->prefixo, a->companhia, a,  a->proximo, a->anterior);
        a = a->proximo; //avanca no
    } while (aux!=a);
}


int salvar_arq (Aviao *lista) {
   arq_aviao=fopen("avioes.bin", "r+b");
   int total_gravado=fwrite(lista,sizeof(Aviao),qtdAviao,arq_aviao);
    if (total_gravado!=qtdAviao)
    {
        printf("Erro na escrita do arquivo \n");
        system("pause");
        exit(1);
        return 0;
    }
    fclose(arq_aviao);
    return 1;
}

Aviao * delete_aviao(Aviao *lista, int valor){
	Aviao *comeco = lista;
	system("cls");
	
	do{
		if(comeco->id == valor && comeco->proximo != comeco){ // achou o valor e existe mais de um n�
			comeco->proximo->anterior = comeco->anterior;
			comeco->anterior->proximo = comeco->proximo;
			return (comeco->anterior);
		}
		
		else if(comeco->id == valor && comeco->proximo == comeco){ // achou o valor, mas s� existe um n�
			return (NULL); 
		}
		
		else comeco = comeco->proximo;
		
	}while(comeco != lista);
	
	printf("Valor nao existe!\n\n");
	return (lista);
}
