/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "funcionario.h"
#include "seg_social.h"

#define MAX_LINHA 2

/**
 * Esta função le o valor que o funcionario/empresa tem de pagar à seg social
 * @param cargo
 * @return 
 */
double ler_tabela_trabalhador_geral(int cargo) {

    double tabela_coluna_0, tabela_coluna_1;
    Funcionario *funcionario_tabela;

    FILE *tabela = fopen("trabalhador_geral.txt", "r");

    char linha[MAX_LINHA + 1];
    char *teste;
    teste = (char *) malloc(sizeof (char) * (MAX_LINHA + 1));

    teste = fgets(linha, MAX_LINHA, tabela);
    sscanf(linha, "%lf;%lf;", &tabela_coluna_0,
            &tabela_coluna_1);
    while (teste != NULL) {
        if (funcionario_tabela->cargo == 0 || funcionario_tabela->cargo == 1 || 
            funcionario_tabela->cargo == 2 || funcionario_tabela->cargo == 3 ||
            funcionario_tabela->cargo == 4 || funcionario_tabela->cargo == 5) {

                return tabela_coluna_1;      
            }
        }
    funcionario_tabela->ent_empregadora_seg_social = tabela_coluna_0;

        teste = fgets(linha, MAX_LINHA, tabela);
        sscanf(linha, "%lf;%lf;", &tabela_coluna_0,
               &tabela_coluna_1);


    fclose(tabela);
}

/**
 * Esta função premite alterar os valores das taxas da seg social
 * 
 * @param cargo
 * @param novo_valor
 * @return 
 */
double alterar_tabela_trabalhador_geral(int cargo, double novo_valor) {
    
    double tabela_coluna_0, tabela_coluna_1,tabela_coluna_0_anterior, tabela_coluna_1_anterior;
    Funcionario *funcionario_tabela;

    FILE *tabela = fopen("trabalhador_geral.txt", "r");
    FILE *nova_tabela = fopen("novo_trabalhador_geral.txt", "w");

    char linha[MAX_LINHA + 1];
    char *teste;
    teste = (char *) malloc(sizeof (char) * (MAX_LINHA + 1));

    teste = fgets(linha, MAX_LINHA, tabela);
    sscanf(linha, "%lf;%lf;", &tabela_coluna_0,
            &tabela_coluna_1);
    while (teste != NULL) {
        if (funcionario_tabela->cargo == 0 || funcionario_tabela->cargo == 1 ||
            funcionario_tabela->cargo == 2 || funcionario_tabela->cargo == 3 ||
            funcionario_tabela->cargo == 4 || funcionario_tabela->cargo == 5) {

            return tabela_coluna_1;
        }
        funcionario_tabela->ent_empregadora_seg_social = tabela_coluna_0;
    }
    teste = fgets(linha, MAX_LINHA, tabela);
    sscanf(linha, "%lf;%lf;", &tabela_coluna_0,
            &tabela_coluna_1);

        tabela_coluna_0_anterior = tabela_coluna_0;
        tabela_coluna_1_anterior = tabela_coluna_1;

        teste = fgets(linha, MAX_LINHA, tabela);
        sscanf(linha, "%lf;%lf;", &tabela_coluna_0,
                &tabela_coluna_1);

    switch (cargo) {
        case 0:
            tabela_coluna_0_anterior = novo_valor;
            break;
        case 1:
            tabela_coluna_1_anterior = novo_valor;
            break;

    }

    fprintf(nova_tabela, "%lf;%lf;\n", tabela_coluna_0_anterior,
            tabela_coluna_1_anterior);
    fclose(tabela);
    fclose(nova_tabela);

    tabela = fopen("trabalhador_geral.txt", "w");
    nova_tabela = fopen("temp_trabalhador_geral.txt", "r");

    teste = fgets(linha, MAX_LINHA, nova_tabela);
    sscanf(linha, "%lf;%lf;", &tabela_coluna_0,
            &tabela_coluna_1);
    while (teste != NULL) {
        fprintf(tabela, "%lf;%lf;\n", tabela_coluna_0,
                tabela_coluna_1);

        teste = fgets(linha, MAX_LINHA, nova_tabela);
        sscanf(linha, "%lf;%lf;", &tabela_coluna_0,
                &tabela_coluna_1);

    }
    fclose(tabela);
    fclose(nova_tabela);
}



void menu_tabela_seg_social(){
    
    int op,cargo;
    double novo_valor;
    
    do{
        printf("\tGESTAO DA TABELA\n");
        printf("\tSEGURANÇA SOCIAL\n");
        printf("------------------------------------\n");
        printf("0 - Sair\n");
        printf("Trabalhador geral\n");
        printf("1 - Ler tabela\n");
        printf("2 - Editar tabela\n");
        printf("-------------------------------------\n");

        op = obter_int(0, 2, "Opção: ");
        
        switch(op){
            case 0:
                break;
            case 1:
                ler_tabela_trabalhador_geral(cargo);
                break;
            case 3:
                printf("Que valor pertender alterar?\n");
                novo_valor = obter_double(0, 100, "Valor: ");
                alterar_tabela_trabalhador_geral(cargo,novo_valor);
                break;
        }
                
    }while (op != 0);
    
}