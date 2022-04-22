#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"avioes.h"

int menu () {
    int op=0;
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


int main () {

    printf("----- Inicio do Programa -----\n");

    Aviao * hangar = cria_aviao(hangar);
 
    hangar= set_aviao(hangar,"boeing777", "azl2", "azul");
    hangar= set_aviao(hangar,"boeing176", "kf5", "khalifaairlines");
    hangar= set_aviao(hangar,"boeing196", "gol3", "gol");

    int op=0;
    op=menu();

    do {
    switch (op) {
        case 1:
            printf("[1] Listar todos os avioes em Solo \n");
            view_aviao(hangar);
            op=menu();
            break;
        case 2:
            printf("[2] Adicionar aviao em solo\n");

            op=menu();
            break;
        case 3:
            printf("[3] Remover aviao em solo\n");
            
            op=menu();
            break;
        case 4:
            printf("[4] Listar todos os Passageiros\n");
            
            op=menu();
            break;
        case 5:
            printf("[5] Adicionar um Passageiro\n");
            
            op=menu();
            break;
        case 6:
            printf("[6] Remover um Passageiro\n");
            
            op=menu();
            break;
        case 7:
            printf("[7] Pesquisar Passageiro (Idade)\n");
            
            op=menu();
            break;
        default:
            printf("Selecione uma opcao valida \n");
            op=menu();
            break;
        }    
    } while (op!=0);
    
    return 0;
}

