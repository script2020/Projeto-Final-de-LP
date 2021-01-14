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
#include <string.h>

#include "funcionario.h"
#include "input.h"
#include "time.h"
#include "irs.h"
#include "seg_social.h"


//APRENDER A FAZER DEBUG

int main() {
    
    FILE *file;
    Funcionario *lista_funcionarios;
    int tam_lista = 0, escolha = 0;

    printf("\tMENU\n");
    printf("-------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Gestão das tabelas IRS\n");
    printf("2 - Tabela segurança social\n");
    printf("3 - Gestão de funcionarios\n");
    printf("4 - Gestão de salarios\n");
    printf("-------------------------------\n");

    escolha = obter_int(0, 4, "Opção: ");
    switch (escolha) {
        case 0:
            break;
        case 1:
            menu_tabela_irs();
            break;
        case 2:
            menu_tabela_seg_social();
            break;
        case 3:
            menu_funcionario(lista_funcionarios, tam_lista, file);
            break;

        case 4:

            break;
    }
    return 0;
}
