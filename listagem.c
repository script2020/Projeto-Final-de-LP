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



void funcionario_dias_horas_trabalho_mes(Funcionario* funcionario_temp, Funcionario *lista_funcionarios){
    
    int tam_lista,dias_completos_totais,dias_semi_completos_totais;
    FILE *file;
    int horas_mes, dias_trabalho_mes;
    Salario *salario;
    
    funcionario_temp->codigo = obter_int(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO,
                "Código do funcionário: ");
    procurar_funcionario(funcionario_temp->codigo,lista_funcionarios,tam_lista,file);
    if (funcionario_temp.codigo == -1) {
        printf("Funcionário não encontrado\n");
    } 
    salario->nDiasComp = dias_completos_totais;
    
    
    printf("O funcionário trabalhou ");
    printf("%d dias completos este mês", dias_completos_totais);
    
    
}


void funcionario_mais_bonus(Funcionario *funcionario_temp, Funcionario *lista_funcionarios){
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
            if (lista_funcionarios->salarios.valorBonus[i] < lista_funcionarios->salarios.valorBonus[j]) {
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
    
    


void funcionario_horas_extras(Funcionario* funcionario){
    
}

void menu_listagem(){
    
    int op;
    Funcionario funcionario_temp;
    Funcionario *lista_funcionarios;
    
    do{
        printf("-----------\n");
        printf("0 - Sair\n");
        printf("1 - Listar bónus\n");
        printf("2 - ");
        
        op = obter_int(0, 5,"Opção");
        
        switch(op){
            case 0:
                break;
            case 1:
            funcionario_mais_bonus(&funcionario_temp ,lista_funcionarios);
                    
        }
        
        
    }while(op != 0);
    
    
}






