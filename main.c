#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"avioes.h"
#include"passageiro.h"


char mod[40];
char pref[10];
char cia[20];
char nome[80];
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

Passageiro * adicionarPassageiro(Passageiro *n){
    fflush(stdin);
    printf("Informe o nome do passageiro: \n");
    gets(nome);
    printf("Informe a idade do passageiro: \n");
    scanf("%d", &idade);
    if(n=insere_passageiro(n, nome, idade)){
        return n;
    } else
        return 0;
}


int main () {

    printf("----- Inicio do Programa -----\n");
    
    Aviao * hangar = cria_aviao(hangar);
    if(hangar=inicializarAvioes(hangar)){
        printf("----- arquivos carregados -----\n");
    } else{
        printf("arquivos nao carregados \n");
    }; 
    Passageiro *lista = cria_passageiro(lista);

    int op=1;
    int del;
   
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
                if (hangar=delete_aviao(hangar, del))
                {
                    printf("Aviao removido com  sucesso \n");
                } else
                    printf("Falha ao remover aviao \n");
                break;
            case 4:
                printf("[4] Listar todos os Passageiros\n");
                view_passageiro(lista);
                break;
            case 5:
                printf("[5] Adicionar um Passageiro\n");
                if(lista=adicionarPassageiro(lista)){
                    printf("Passageiro adicionado com sucesso!!! \n");
                } else{
                    printf("erro ao adicionar o passageiro\n");
                }
                break;
            case 6:
                printf("[6] Remover um Passageiro\n");
                break;
            case 7:
                printf("[7] Pesquisar Passageiro (Idade)\n");
                break;
            case 8:
                printf("qtd aviao %d \n", qntdAviao());
            default:
                printf("Selecione uma opcao valida \n");
                break;
            }   
    } 

  //salvar arquivos
    if (salvar_arq(hangar))  {
        printf("Arquivos salvos com sucesso!! \n");
    } else  {
    printf("Erro ao salvar os arquivos \n");
    }
    return 0;
}

