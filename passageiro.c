#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"passageiro.h"
int qtdPassageiros=0;
int qntdPassageiros=0;


Lista* cria_lista(){
    /*alocação do ponteiro li para controlar a lista*/
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        /*Se a lista está inicialmente vazia, inicio e fim apontam para NULL */
        li->fim = NULL;
        li->inicio = NULL;
    }
    return li;
}


Passageiro *aux;
Passageiro *aux2;
Passageiro *anterior;

void insere_lista(Lista *li){
    Passageiro *novo =(Passageiro*) malloc(sizeof(Passageiro)); 
    fflush(stdin);
    printf("Digite o nome do passageiro: \n"); 
	gets(novo->nome);
    printf("Digite a idade do passageiro: \n");
    scanf("%d", &novo->idade);
    qtdPassageiros++;
    qntdPassageiros++;
    novo->id=qntdPassageiros;

    if(li->inicio == NULL){ 
        novo->prox = NULL;
        novo->ant = NULL;
        li->inicio = novo; 
        li->fim = novo; 
        
    }else{ 
        aux = li->inicio; 
       
        
        while(aux != NULL && novo->idade > aux->idade){
            aux = aux->prox; 
        }
        
        if(aux == li->inicio){
            novo->prox = li->inicio; 
            novo->ant = NULL; 
            li->inicio->ant = novo; 
            li->inicio = novo; 

        }else if(aux == NULL){
            li->fim->prox = novo;
            novo->ant = li->fim; 
            li->fim = novo; 
            li->fim->prox = NULL; 
        }else{ 
            novo->prox = aux; 
            aux->ant->prox = novo; 
            novo->ant = aux->ant; 
            aux->ant = novo; 
        }
    }
    printf("\nPassageiro inserido na lista!");
}	

void imprime_lista_inicio_ao_fim(Lista *li){
    /*caso a lista esteja vazia*/
    if( li->inicio == NULL){
        printf("Lista Vazia!! \n");
    /*caso a lista não esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        aux =  li->inicio;
        do{
           
            printf("idade %d- nome %s -id: %d- atual: %p \t-  prox: %p \t-  ant: %p \n",aux->idade, aux->nome, aux->id, aux, aux->prox, aux->ant);
            aux = aux->prox;
        }while(aux != NULL);
    }
}

void imprime_lista_fim_ao_inicio(Lista *li){
    /*caso a lista esteja vazia*/
    if( li->inicio == NULL){
        printf("\nLista Vazia!!");
    /*caso a lista não esteja vazia*/
    }else{
        /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que fim aponta*/
        aux =  li->fim;
        do{
            printf("idade %d- nome %s -id: %d \n",aux->idade, aux->nome, aux->id);
            aux = aux->ant;
        }while(aux != NULL);
    }
}

void remover_passageiro(Lista *li){

    int numero, achou; 
    if(li->inicio == NULL){ /*caso a lista esteja vazia*/
        printf("Lista Vazia!! \n");
    }else{  /*caso a lista não esteja vazia*/
        printf("Digite o id do passageiro a ser removido: \n"); 
		scanf("%d", &numero);
        aux =  li->inicio; /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        achou = 0;
        do{
            if(aux->id == numero){ 
                achou = achou + 1; 
                if(aux ==  li->inicio){ 
                    li->inicio = aux ->prox; 
                                                            
                    if( li->inicio != NULL){
                         li->inicio->ant = NULL; 
                    }
                    free(aux); 
                    aux =  li->inicio; 
                }else if(aux == li->fim){ 
                                li->fim =  li->fim->ant; 
                                li->fim->prox = NULL; 
                                free(aux); 
                                aux = NULL; 
                        }else{ 
                                aux->ant->prox = aux->prox; 
                                                                                  
                                aux->prox->ant = aux->ant;  
                                aux2 = aux->prox;
                                free(aux); 
                                aux = aux2; 
                        }
        }else{ 
            aux = aux -> prox;
        }
        }while(aux != NULL);

                if(achou ==  0){
                    printf("Passageiro nao encontrado!");
                }else{
                    printf("Passageiro removido com sucesso");
                    qtdPassageiros-=achou;
                }
    }
}


void find_lista(Lista *l, int idade) {

    if(l->inicio == NULL){ /*caso a lista esteja vazia*/
        printf("\nLista Vazia!!");
    }else{
        aux=l->inicio;
        do
        {
            aux=aux->prox;
            if (aux->idade==idade)
            {
                printf("idade %d- nome: %s -id: %d \n",aux->idade, aux->nome, aux->id);
            } 
        } while (aux!=l->fim);
    }
}



