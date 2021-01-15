/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>

#include "input.h"
#include "funcionario.h"
#include "listagem.h"
#include "salarios.h"




void funcionario_listar_bonus(Funcionario *funcionario_temp, Funcionario *lista_funcionarios){
    Salario *salario;
    int tam_lista,valor_temp;
    FILE *file;
  
    funcionario_temp->codigo = obter_int(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO,
            "Código do funcionário: ");
    procurar_funcionario(funcionario_temp->codigo, lista_funcionarios, tam_lista, file);
    if (funcionario_temp->codigo == -1) {
        printf("Funcionário não encontrado\n");
    } 
   
    for (int i = 0; i < tam_lista; ++i) {
        for (int j = i + 1; j < tam_lista; ++j) {
            if (lista_funcionarios[i] < lista_funcionarios->salarios.valorBonus[j]) {
                valor_temp = lista_funcionarios->salarios.valorBonus[i];
                lista_funcionarios->salarios.valorBonus[i] = lista_funcionarios->salarios.valorBonus[j];
                lista_funcionarios->salarios.valorBonus[j] = valor_temp;
            }
        }
    }
    for (int i = 0; i < tam_lista; ++i) {
        printf("%d\n", lista_funcionarios->salarios.valorBonus[i]);
    }
}

void funcionario_mais_anos(Funcionario *funcionario_temp, Funcionario *lista_funcionarios){
    
    int tam_lista,valor_temp,  maior = 0;
    FILE *file;
    funcionario_temp->codigo = obter_int(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO,
            "Código do funcionário: ");
    procurar_funcionario(funcionario_temp->codigo, lista_funcionarios, tam_lista, file);
    if (funcionario_temp->codigo == -1) {
        printf("Funcionário não encontrado\n");
    }

    for (int i = 0; i < tam_lista; ++i) {
        for (int j = i + 1; j < tam_lista; ++j) {
            if (lista_funcionarios[i] < lista_funcionarios->tempo_empresa.ano[j]) {
                valor_temp = lista_funcionarios->tempo_empresa.ano[i];
                lista_funcionarios->tempo_empresa.ano[i] = lista_funcionarios->tempo_empresa.ano[j];
                lista_funcionarios->tempo_empresa.ano[j] = valor_temp;
            }
        }
    }
    for (int i = 0; i < tam_lista; ++i) {
        printf("Nome: %s\nAnos de trabalho: %d\n",lista_funcionarios->nome[i] 
                lista_funcionarios->tempo_empresa.ano[i]);
    }
}


void menu_listagem(){
    
    int op;
    Funcionario funcionario_temp;
    Funcionario *lista_funcionarios;
    
    do{
        printf("MENU LISTAGENS\n");
        printf("-----------------------\n");
        printf("0 - Sair\n");
        printf("1 - Listar bónus\n");
        printf("2 - Funcionário que trabalhou mais anos\n");
        printf("-----------------------\n");
        op = obter_int(0, 5,"Opção");
        
        switch(op){
            case 0:
                break;
            case 1:
            funcionario_listar_bonus(&funcionario_temp ,lista_funcionarios);
            case 2:
            funcionario_mais_anos(&funcionario_temp, lista_funcionarios);
            
        }
        
        
    }while(op != 0);
    
    
}






