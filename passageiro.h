#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct passageiro Passageiro;
struct passageiro {
    Passageiro *proximo;
    Passageiro *anterior;
    char nome[80];
    int idade;
    int id;
    };


Passageiro * cria_passageiro(Passageiro *a);
Passageiro * insere_passageiro(Passageiro * l, char *nome, int ida);
void view_passageiro(Passageiro* a);
