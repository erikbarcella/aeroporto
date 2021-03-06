#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"avioes.h"
#include"passageiro.h"


char mod[40];
char pref[10];
char cia[20];
int idade;

int menu () {
    int op;
    printf("-------------------------------------------------------- \n");
    printf("Sistema de Controle de Aeroporto de Litoral Norte de RS \n");
    printf("-------------------------------------------------------- \n");
    printf("[1] Listar todos os avioes em Solo \n");
    printf("[2] Adicionar aviao em solo\n");
    printf("[3] Remover aviao em solo\n");
    printf("[4] Listar todos os Passageiros\n");
    printf("[5] Adicionar um Passageiro\n");
    printf("[6] Remover um Passageiro\n");
    printf("[7] Pesquisar Passageiro (Idade)\n");
    printf("[0] Sair & Salvar Dados\n");
    printf("-------------------------------------------------------- \n");
    printf("Selecione a opcao desejada: \n");
    scanf("%d", &op);
    return op;
}

Aviao *adicionarAviao(Aviao* n) {
    fflush(stdin);
    printf("Informe o nome do modelo: \n");
    gets(mod);
    printf("Informe o prefixo: \n");
    gets(pref);
    printf("Informe o nome da companhia aerea: \n");
    gets(cia);
    if (n= set_aviao(n, mod, pref, cia)){
        return n;
    } else
        return 0;
}


int main () {

    printf("----- Inicio do Programa -----\n");
    
    Aviao * hangar = cria_aviao(hangar);
    Lista *p=cria_lista(p);

    int op=1;
    int del=0;
   
    while (op!=0) {
       
        op=menu();
        int aux=op;
            switch (aux) {
            case 1:
                printf("[1] Listar todos os avioes em Solo \n");
                view_aviao(hangar);
                break;
            case 2:
                printf("[2] Adicionar aviao em solo\n");
                if(hangar=adicionarAviao(hangar)){
                    printf("Aviao adicionado com sucesso!!! \n");
                } else{
                    printf("erro ao adicionar o aviao \n");
                }
                break;
            case 3:
                printf("[3] Remover aviao em solo\n");
                view_aviao(hangar);
                printf("Informe o id do aviao que deseja remover: \n");
                scanf("%d", &del);
                if(hangar=delete_aviao(hangar,del)) {
                    printf("Aviao removido com  sucesso \n");
                } else
                    printf("Falha ao remover aviao \n");
                break;
            case 4:
                printf("[4] Listar todos os Passageiros\n");
                imprime_lista_fim_ao_inicio(p);
                break;
            case 5:
                printf("[5] Adicionar um Passageiro\n");
                insere_lista(p);
                break;
            case 6:
                printf("[6] Remover um Passageiro\n");
                imprime_lista_fim_ao_inicio(p);
                remover_passageiro(p);
                break;
            case 7:
                printf("[7] Pesquisar Passageiro (Idade)\n");
                printf("Informe a idade do passageiro a ser localizado: \n");
                scanf("%d", &idade);
                find_lista(p, idade);
                break;
            default:
                printf("Selecione uma opcao valida \n");
                break;
            }   
    } 

    return 0;
}

