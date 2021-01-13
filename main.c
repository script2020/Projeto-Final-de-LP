 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Maria
 *
 * Created on 30 de dezembro de 2020, 13:36
 */

#include <stdio.h>
#include <stdlib.h>


#include "funcionario.h"
#include "input.h"
#include "time.h"
#include "irs.h"

FILE *file;

//APRENDER A FAZER DEBUG

/**
 * Esta função premite gerir os funcionários
 * 
 * @param lista_funcionarios
 * @param tam_lista
 */
void menu_funcionarios(Funcionario *lista_funcionarios, int tam_lista) {

    int op;
    Funcionario *funcionario_temp;
    int codigo_temp;

    do {
        printf("\t GESTÃO DE \n");
        printf("\tFUNCIONÁRIOS\n");
        printf("-----------------------\n");
        printf("0 - Sair\n");
        printf("1 - Inserir\n");
        printf("2 - Editar\n");
        printf("3 - Eliminar\n");
        printf("4 - Mostrar\n");
        printf("-----------------------\n");

        op = obter_int(0, 4, "Opção: ");
        switch (op) {
            case 0:
                break;
            case 1:


                criar_funcionario(funcionario_temp, lista_funcionarios, tam_lista, file);
                //POR PARA SE ELE JA FOI CRIADO??
                break;
            case 2:
                codigo_temp = obter_int(0, MAX_NUM_FUNCIONARIO, "Código: ");
                *funcionario_temp = procurar_funcionario(codigo_temp, lista_funcionarios, tam_lista, file);

                if (funcionario_temp->codigo == -1) {
                    printf("Funcionario não encontrado\n");
                    break;
                }
                editar_funcionario(funcionario_temp);

                break;
            case 3:
                codigo_temp = obter_int(0, MAX_NUM_FUNCIONARIO, "Código: ");
                *funcionario_temp = procurar_funcionario(codigo_temp, lista_funcionarios, tam_lista, file);
                if (funcionario_temp->codigo == -1) {
                    printf("Funcionário não encontrado\n");
                    break;
                }
                remover_funcionario(funcionario_temp);
                break;
            case 4:
                codigo_temp = obter_int(0, MAX_NUM_FUNCIONARIO, "Código: ");
                *funcionario_temp = procurar_funcionario(codigo_temp, lista_funcionarios, tam_lista, file);
                if (funcionario_temp->codigo == -1) {
                    printf("Funcionario não encontrado\n");
                    break;
                }
                mostrar_funcionario(funcionario_temp);
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (op != 0);

}

int main() {
    file = fopen("funcionario.bin", "a+b");
    Funcionario *lista_funcionarios;
    int tam_lista = 0, escolha;
/*

    printf("\tMENU\n");
    printf("-------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Tabela IRS\n");
    printf("2 - Tabela segurança social\n");
    printf("3 - Gestão de funcionarios\n");
    printf("4 - Gestão de salarios\n");
    printf("-------------------------------\n");

    escolha = obter_int(0, 4, "Opção: ");
    switch (escolha) {
        case 0:
            break;
        case 1:
            printf("%.2lf", ler_tabela_nao_casado(736, 1));
            break;
        case 2:

            break;
        case 3:
*/
            menu_funcionarios(lista_funcionarios, tam_lista);
/*
            break;

        case 4:

            break;
    }
*/


    fclose(file);
    return 0;
}
