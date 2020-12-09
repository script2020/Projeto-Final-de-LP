/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funcionario.h"
/*
 * 
 */
#define TAM_NOME 100

typedef struct{
    int dia,mes,ano;
}Data;

typedef struct{
    int codigo,numero_telemovel,numero_filhos;
    int tempo_empresa;
    char nome[TAM_NOME],cargo,estado_civil;
    Data data_entrada,data_saida;
    float subsidio_alimentacao, vencimento_base;
}Funcionario;

void menuPrincipal(){
    int op;
    
    do{
        puts("TÊXTEIS LDA");
        puts("-----------------");
        puts("1 - Gestão de Funcionários");
        puts("0 - Sair");
        puts("-----------------");
        
        puts("Insira a sua opção:");
        scanf("%d", &op);

        switch (op) {
            case 0:
                exit(0);
                break;
            case 1:
                menuFuncionarios();
                break;
            default:
                puts("Opção inválida!");
                break;
        }
    }while(op!=0);
    
}    

void menuFuncionarios(){
    int op,registo = 0;
    
    Funcionario funcionario;
    do{
        puts("GESTÃO DE FUNCIONÁRIOS");
        puts("-----------------");
        puts("1 - Inserir");
        puts("2 - Editar");
        puts("3 - Eliminar");
        puts("0 - Sair");
        puts("-----------------");
        
        puts("Insira a sua opção:");
        scanf("%d", &op);

        switch (op) {
            case 0:
                exit(0);
                break;
            case 1:
                criar_funcionario(&funcionario,&registo);
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                puts("Opção inválida!");
                break;
        }
    }while(op!=0);
    
}    
