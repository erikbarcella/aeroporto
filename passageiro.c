#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"passageiro.h"
int qtdPassageiros=0;

Passageiro * cria_passageiro(Passageiro *a) {
    return (NULL);
}

Passageiro * insere_passageiro(Passageiro * l, char *nome, int ida)
{
 Passageiro *aux, *novo =(Passageiro *) malloc(sizeof(Passageiro));
    if (novo)
    {
        strcpy(novo->nome, nome);
        novo->idade=ida;

        if (l == NULL) {
            novo->proximo = novo;
		    novo->anterior = novo;
            novo->id=1;
            qtdPassageiros++;
             l= novo;
        }
      
      
        else {
            aux=l;
            while (aux->proximo && novo->idade > aux->proximo->idade)
            {
                aux = aux->proximo;
                aux= aux->anterior;
                novo->proximo=aux->proximo;
                novo->anterior=aux->anterior;
                aux->proximo=novo;
                aux->anterior=novo;
                qtdPassageiros++;
                novo->id=qtdPassageiros;
            }
        }
    }
 return(novo);
}

void view_passageiro(Passageiro* a) {

    Passageiro* aux=a;
    if (a!=NULL) do
    {
        printf("id: %d - nome %s -idade %d - atual: %p \t-  prox: %p \t-  ant: %p \n",a->id, a->nome,a->idade, a,  a->proximo, a->anterior);
        a = a->proximo; //avanca no
    } while (aux!=a);
}

