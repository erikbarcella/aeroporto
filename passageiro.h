#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct No{
    struct No *prox;
    struct No *ant;
    char nome[80];
    int idade;
    int id;
};
typedef struct No Passageiro;

/*registro do tipo Lista contento dois ponteiros do tipo nó para controlar a lista*/
struct Lista{
    struct No *inicio; /*aponta para o elemento do início da lista*/
    struct No *fim; /*aponta para o elemento do fim da lista*/
};
typedef struct Lista Lista;

Lista* cria_lista();
void insere_lista(Lista *li);
void imprime_lista_inicio_ao_fim(Lista *li);
void imprime_lista_fim_ao_inicio(Lista *li);
void remover_passageiro(Lista *li);
void find_lista(Lista *l, int idade);

