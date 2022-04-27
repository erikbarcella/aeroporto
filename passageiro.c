#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"passageiro.h"
int qtdPassageiros=0;


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
    Passageiro *novo =(Passageiro*) malloc(sizeof(Passageiro)); /*a cada inserção alocamos dinamicamente um espaço para um novo nó*/
    /*o número a ser inserido será armazenado em novo->num*/

    fflush(stdin);
    printf("Digite o nome do passageiro: \n"); 
	gets(novo->nome);
    printf("Digite a idade do passageiro: \n");
    scanf("%d", &novo->idade);
    qtdPassageiros++;
    novo->id=qtdPassageiros;

    if(li->inicio == NULL){ /*caso a lista estiver vazia o elemento a ser inserido será o primeiro e último elemento da lista*/
        /*como será o único elemento da lista, novo->prox e novo->ant apontam para null*/
        novo->prox = NULL;
        novo->ant = NULL;
        li->inicio = novo; /*aqui fazemos com que inicio aponte para o mesmo endereço que novo aponta*/
        li->fim = novo; /*aqui fazemos com que fim aponte para o mesmo endereço que novo aponta*/
        
    }else{ /*caso a lista não esteja vazia*/
        aux = li->inicio; /*aux aponta para o endereço que inicio aponta*/
        /*enquanto ainda houverem elementos na lista e o novo número for maior que aux->num,
         ou seja enquanto não for encontrado um número maior que o número inserido*/
        while(aux != NULL && novo->idade > aux->idade){
            aux = aux->prox; /*aux aponta para o próximo elemento da lista*/
             /*isso é feito para encontrar o ponto exato para o número ser inserido*/
        }
        /*caso não existam números maiores ou iguais ao novo número , ele será inserido no início da lista*/
        if(aux == li->inicio){
            novo->prox = li->inicio; /*novo->prox apontara para o atual inicio, que depois será o segundo elemento*/
            novo->ant = NULL; /*como novo será o primeiro da lista, seu ponteiro ant deverá apontar para null*/
            li->inicio->ant = novo; /*o inicio atual(que depois será o segunda da lista) em ant, apontara para o endereço de novo*/
            li->inicio = novo; /*inicio aponta para novo*/
        /*caso todos elementos da lista sejam menores que o número a ser inserido, ele será inserido no fim*/
        }else if(aux == NULL){
            li->fim->prox = novo; /*o fim atual (que depois será o penultimo da lista) em prox, apontará para novo*/
            novo->ant = li->fim; /*novo -> ant aponta para o endereço do fim atual.*/
            li->fim = novo; /*fim aponta para novo*/
            li->fim->prox = NULL; /*todo ultimo elemento da lista  em prox aponta para null*/
        }else{  /*caso novo seja inserido no meio da lista, ele será inserido antes de aux*/
            novo->prox = aux; /*novo será inserido antes do aux atual, então novo->prox aponta para o aux atual*/
            aux->ant->prox = novo; /*o número que estava antes de aux em prox aponta para novo*/
            novo->ant = aux->ant; /*novo-> ant aponta para o nó anterior a aux atual*/
            aux->ant = novo; /*aux atual será o elemento seguinte a novo, portanto em ant apontará para novo*/
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
            /*impressão do elemento que aux aponta*/
            printf("idade %d- nome %s -id: %d- atual: %p \t-  prox: %p \t-  ant: %p \n",aux->idade, aux->nome, aux->id, aux, aux->prox, aux->ant);
            /*aux aponta para o próximo elemento da lista, que será o endereço contido no ponteiro prox.*/
            aux = aux->prox;
            /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos
             a serem impressos*/
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
            /*impressão do elemento que aux aponta*/
            printf("idade %d- nome %s -id: %d \n",aux->idade, aux->nome, aux->id);
            /*aux aponta para o elemento anterior da lista, que será o endereço contido no ponteiro ant.*/
            aux = aux->ant;
            /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos
                a serem impressos*/
        }while(aux != NULL);
    }
}

void remover_passageiro(Lista *li){
    int numero, achou; /*a variável achou será utilizada como um contador de números removidos*/
    if(li->inicio == NULL){ /*caso a lista esteja vazia*/
        printf("Lista Vazia!! \n");
    }else{  /*caso a lista não esteja vazia*/
        printf("Digite o id do passageiro a ser removido: \n"); 
		scanf("%d", &numero);
        aux =  li->inicio; /*utilizando o ponteiro aux,  fazemos com ele aponte para o mesmo endereço que inicio aponta*/
        achou = 0;
        do{
            if(aux->id == numero){ /*caso aux-> num seja igual ao número a ser removido*/
                achou = achou + 1; /*incrementamos achou*/
                if(aux ==  li->inicio){ /*se o elemento a ser removido for o primeiro da lista*/
                    li->inicio = aux ->prox; /*inicio apontará para o segundo elemento da lista ou para NULL caso o elemento
                                                            removido seja o único elemento da lista*/
                    if( li->inicio != NULL){ /*caso inicio tenha não recebido null na linha anterior*/
                         li->inicio->ant = NULL; /*ant de inicio também apontará para null*/
                    }
                    free(aux);  /*desalocamos o espaço para onde aux apontava*/
                    aux =  li->inicio; /*aux aponta para o inicio da lista*/
                }else if(aux == li->fim){ /*se o elemento a ser removido for o ultimo da lista*/
                                li->fim =  li->fim->ant; /*fim apontará para o elemento anterior a ele*/
                                li->fim->prox = NULL; /*fim no atributo prox apontará para null*/
                                free(aux); /*desalocamos o espaço para onde aux apontava*/
                                aux = NULL; /*como era o últmo elemento da lista, aux recebe NULL*/
                        }else{ /*se o elemento a ser removido não for nem o primeiro nem o último da lista */
                                aux->ant->prox = aux->prox; /*o elemento anterior ao que iremos remover, em prox, apontara para
                                                                                   o endereço do próximo elemento depois de aux */
                                aux->prox->ant = aux->ant;  /*o elemento seguinte ao que iremos remover, em ant,  apontará para
                                                                                  o endereço do elemento anterior a aux */
                                aux2 = aux->prox; /*aux2 aponta para o elemento depois de aux*/
                                free(aux); /*desalocamos o espaço para onde aux apontava*/
                                aux = aux2; /*aux aponta para onde aux2 apontava*/
                        }
        }else{ /*caso aux-> num não seja igual ao número a ser removido*/
                    aux = aux -> prox; /*aux aponta para o próximo elemento da lista*/
        }
        /*essa operação será feita até aux ser diferente de NULL, ou seja, não houverem mais elementos a serem pesquisados*/
        }while(aux != NULL);

                /*impressão do resultado*/
                if(achou ==  0){
                    printf("Passageiro nao encontrado!");
                }else{
                    printf("Passageiro removido com sucesso");
                    qtdPassageiros-=achou;
                }
    }
}

void find_lista(Lista * l)
{
   int idade, achou;
    if(l->inicio == NULL){ /*caso a lista esteja vazia*/
        printf("Lista Vazia!! \n");
    }else{ 
        printf("Digite a idade do passageiro a ser localizado: \n"); 
		scanf("%d", &idade);
        aux =  l->inicio;
        achou = 0;
        do
        {
            if(aux->idade == idade){
                achou=achou+1;
                printf("idade %d- nome %s -id: %d \n",aux->idade, aux->nome, aux->id);
            }
        } while (aux!=NULL);
        printf("foram localizados %d passageiros \n", achou);
    }
}
