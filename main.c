#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"avioes.h"


char mod[40];
char pref[10];
char cia[20];

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
   
   /*  inicializarAvioes();  */
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
            if(hangar=adicionarAviao(hangar)){
                printf("Aviao adicionado com sucesso!!! \n");
            } else{
                printf("erro ao adicionar o aviao \n");
            }
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
    /* encerraAvioes(); */
    
    return 0;
}

