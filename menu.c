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

typedef struct{
    int dia,mes,ano;
}Data;

typedef struct{
    int codigo,nTelemovel;
    Data dataNas;
    char nome[50],estadoCivil[50];
}Aluno;


void menuPrincipal(){
    int op,registo = 0;
    
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
                insFunc();
                break;
            case 2:
                editFunc();
                break;
            case 3:
                eliFunc();
                break;
            default:
                puts("Opção inválida!");
                break;
        }
    }while(op!=0);
    
}    
