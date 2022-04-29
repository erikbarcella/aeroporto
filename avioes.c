#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"avioes.h"


int qtdAviao=0;
int somaAviao=0;

Aviao * cria_aviao(Aviao *a) {
    return (NULL);
}

int qntdAviao() {
    return qtdAviao;
}

Aviao * set_aviao(Aviao*a, char *mod, char *prefix, char *cia) {
    
    Aviao* novo = (Aviao*) malloc (sizeof(Aviao));
    strcpy(novo->modelo, mod);
    strcpy(novo->prefixo, prefix);
    strcpy(novo->companhia, cia);
    

    if(a==NULL) {
        novo->proximo=novo; //ele recebe ele mesmo
        novo->id=1;
        somaAviao++;
        qtdAviao++;
    }
        else{
        novo->anterior=a;
        novo->proximo=a->proximo;
        a->proximo=novo;
        somaAviao++;
        qtdAviao++;
        novo->id=somaAviao;
    }
    
    return(novo);
}

void view_aviao(Aviao* a) {

    Aviao* aux=a;
    if (a!=NULL) do
    {
        printf("id: %d - modelo: %s -prefixo: %s - companhia aerea: %s \n",a->id, a->modelo,a->prefixo, a->companhia);
        a = a->proximo; //avanca no
    } while (aux!=a);
}

Aviao * delete_aviao(Aviao *lista, int valor){
	Aviao *comeco = lista;
	
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
        qtdAviao--;
		
	}while(comeco != lista);
	printf("Valor nao existe!\n\n");
	return (lista);
}
