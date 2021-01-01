/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Gabriel
 *
 * Created on 9 de dezembro de 2020, 15:16
 */


#include <stdio.h>
#include <string.h>

#include "input.h"
#include "funcionario.h"

FILE *file;

/**
 * esta função premite gerir os funcionários
 */
void menu_funcionarios() {

    int op, registo = 0;
    Funcionario *funcionario_temp;
    int codigo_temp;


    do {//falta mostrar
        printf("GESTÃO DE FUNCIONÁRIOS\n");
        printf("-----------------\n");
        printf("1 - Inserir\n");
        printf("2 - Editar\n");
        printf("3 - Eliminar\n");
        printf("4 - Mostrar\n");
        printf("0 - Sair\n");
        printf("-----------------\n");

        printf("Insira a sua opção:\n");
        scanf("%d", &op);

        switch (op) {
            case 0:
                exit(0);
                break;
            case 1:
                criar_funcionario(funcionario_temp);
                fwrite(funcionario_temp, sizeof (Funcionario), 1, file);
                break;
            case 2:
                codigo_temp = obter_int(0, MAX_NUM_FUNCIONARIO, "Código: ");
                *funcionario_temp = procurar_funcionario(codigo_temp, file);
                if (funcionario_temp->codigo == -1) {
                    printf("Funcionario nao encontrado\n");
                    break;
                }
                editar_funcionario(funcionario_temp);
                break;
            case 3:
                codigo_temp = obter_int(0, MAX_NUM_FUNCIONARIO, "Código: ");
                *funcionario_temp = procurar_funcionario(codigo_temp, file);
                if (funcionario_temp->codigo == -1) {
                    printf("Funcionario nao encontrado\n");
                    break;
                }
                remover_funcionario(funcionario_temp);
                break;
            case 4://como faço o fscanf
                mostrar_funcionario(funcionario_temp);
                fscanf();
                break;
                
            default:
                printf("Opção inválida!");
                break;
        }
    } while (op != 0);

}


int main() {
    file = fopen("funcionario.txt", "a+b");

    menu_funcionarios();

    fclose(file);
    return 0;
}


