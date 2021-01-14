/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>

#include "irs.h"
#include "input.h"
#include "funcionario.h"

#define MAX_LINHA 320

double ler_tabela_nao_casado(double salario_iliquido, int num_filhos) {
    double tabela_coluna_0_anterior, tabela_coluna_1_anterior, tabela_coluna_2_anterior, tabela_coluna_3_anterior,
            tabela_coluna_4_anterior, tabela_coluna_5_anterior, tabela_coluna_6_anterior;
    double tabela_coluna_0, tabela_coluna_1, tabela_coluna_2, tabela_coluna_3,
            tabela_coluna_4, tabela_coluna_5, tabela_coluna_6;

    FILE *tabela = fopen("nao_casado.txt", "r");

    char linha[MAX_LINHA + 1];
    char *teste;
    teste = (char *) malloc(sizeof (char) * (MAX_LINHA + 1));

    teste = fgets(linha, MAX_LINHA, tabela);
    sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
            &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    while (teste != NULL) {
        if (salario_iliquido < tabela_coluna_0) {
            switch (num_filhos) {
                case 0:
                    return tabela_coluna_1;
                case 1:
                    return tabela_coluna_2;
                case 2:
                    return tabela_coluna_3;
                case 3:
                    return tabela_coluna_4;
                case 4:
                    return tabela_coluna_5;
                default:
                    return tabela_coluna_6;

            }
        }
        tabela_coluna_0_anterior = tabela_coluna_0;
        tabela_coluna_1_anterior = tabela_coluna_1;
        tabela_coluna_2_anterior = tabela_coluna_2;
        tabela_coluna_3_anterior = tabela_coluna_3;
        tabela_coluna_4_anterior = tabela_coluna_4;
        tabela_coluna_5_anterior = tabela_coluna_5;
        tabela_coluna_6_anterior = tabela_coluna_6;

        teste = fgets(linha, MAX_LINHA, tabela);
        sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
                &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    }

    switch (num_filhos) {//ler a linha de superiro a ...
        case 0:
            return tabela_coluna_1_anterior;
        case 1:
            return tabela_coluna_2_anterior;
        case 2:
            return tabela_coluna_3_anterior;
        case 3:
            return tabela_coluna_4_anterior;
        case 4:
            return tabela_coluna_5_anterior;
        default:
            return tabela_coluna_6_anterior;

    }
    fclose(tabela);
}

double alterar_tabela_nao_casado(double salario_iliquido, int num_filhos, double novo_valor) {
    double tabela_coluna_0_anterior, tabela_coluna_1_anterior, tabela_coluna_2_anterior, tabela_coluna_3_anterior,
            tabela_coluna_4_anterior, tabela_coluna_5_anterior, tabela_coluna_6_anterior;
    double tabela_coluna_0, tabela_coluna_1, tabela_coluna_2, tabela_coluna_3,
            tabela_coluna_4, tabela_coluna_5, tabela_coluna_6;

    FILE *tabela = fopen("nao_casado.txt", "r");
    FILE *nova_tabela = fopen("novo_nao_casado.txt", "w");

    char linha[MAX_LINHA + 1];
    char *teste;
    teste = (char *) malloc(sizeof (char) * (MAX_LINHA + 1));

    teste = fgets(linha, MAX_LINHA, tabela);
    sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
            &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    while (teste != NULL) {
        if (salario_iliquido < tabela_coluna_0) {
            switch (num_filhos) {
                case 0:
                    tabela_coluna_1 = novo_valor;
                    break;
                case 1:
                    tabela_coluna_2 = novo_valor;
                    break;
                case 2:
                    tabela_coluna_3 = novo_valor;
                    break;
                case 3:
                    tabela_coluna_4 = novo_valor;
                    break;
                case 4:
                    tabela_coluna_5 = novo_valor;
                    break;
                default:
                    tabela_coluna_6 = novo_valor;
                    break;
            }
        }

        fprintf(nova_tabela, "%lf;%lf;%lf;%lf;%lf;%lf;%lf\n", tabela_coluna_0,
                tabela_coluna_1, tabela_coluna_2, tabela_coluna_3, tabela_coluna_4, tabela_coluna_5, tabela_coluna_6);

        tabela_coluna_0_anterior = tabela_coluna_0;
        tabela_coluna_1_anterior = tabela_coluna_1;
        tabela_coluna_2_anterior = tabela_coluna_2;
        tabela_coluna_3_anterior = tabela_coluna_3;
        tabela_coluna_4_anterior = tabela_coluna_4;
        tabela_coluna_5_anterior = tabela_coluna_5;
        tabela_coluna_6_anterior = tabela_coluna_6;

        teste = fgets(linha, MAX_LINHA, tabela);
        sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
                &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    }

    switch (num_filhos) {
        case 0:
            tabela_coluna_1_anterior = novo_valor;
            break;
        case 1:
            tabela_coluna_2_anterior = novo_valor;
            break;
        case 2:
            tabela_coluna_3_anterior = novo_valor;
            break;
        case 3:
            tabela_coluna_4_anterior = novo_valor;
            break;
        case 4:
            tabela_coluna_5_anterior = novo_valor;
            break;
        default:
            tabela_coluna_6_anterior = novo_valor;
            break;
    }

    fprintf(nova_tabela, "%lf;%lf;%lf;%lf;%lf;%lf;%lf\n", tabela_coluna_0_anterior,
            tabela_coluna_1_anterior, tabela_coluna_2_anterior, tabela_coluna_3_anterior, tabela_coluna_4_anterior
            , tabela_coluna_5_anterior, tabela_coluna_6_anterior);
    fclose(tabela);
    fclose(nova_tabela);

    tabela = fopen("nao_casado.txt", "w");
    nova_tabela = fopen("temp_nao_casado.txt", "r");

    teste = fgets(linha, MAX_LINHA, nova_tabela);
    sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
            &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    while (teste != NULL) {
        fprintf(tabela, "%lf;%lf;%lf;%lf;%lf;%lf;%lf\n", tabela_coluna_0,
                tabela_coluna_1, tabela_coluna_2, tabela_coluna_3, tabela_coluna_4, tabela_coluna_5, tabela_coluna_6);

        tabela_coluna_0_anterior = tabela_coluna_0;
        tabela_coluna_1_anterior = tabela_coluna_1;
        tabela_coluna_2_anterior = tabela_coluna_2;
        tabela_coluna_3_anterior = tabela_coluna_3;
        tabela_coluna_4_anterior = tabela_coluna_4;
        tabela_coluna_5_anterior = tabela_coluna_5;
        tabela_coluna_6_anterior = tabela_coluna_6;

        teste = fgets(linha, MAX_LINHA, nova_tabela);
        sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
                &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);

    }
    fclose(tabela);
    fclose(nova_tabela);
}

double ler_tabela_casado_unico_titual(double salario_iliquido, int num_filhos) {
    double tabela_coluna_0_anterior, tabela_coluna_1_anterior, tabela_coluna_2_anterior, tabela_coluna_3_anterior,
            tabela_coluna_4_anterior, tabela_coluna_5_anterior, tabela_coluna_6_anterior;
    double tabela_coluna_0, tabela_coluna_1, tabela_coluna_2, tabela_coluna_3,
            tabela_coluna_4, tabela_coluna_5, tabela_coluna_6;

    FILE *tabela = fopen("casado_unico_titual.txt", "r");

    char linha[MAX_LINHA + 1];
    char *teste;
    teste = (char *) malloc(sizeof (char) * (MAX_LINHA + 1));

    teste = fgets(linha, MAX_LINHA, tabela);
    sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
            &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    while (teste != NULL) {
        if (salario_iliquido < tabela_coluna_0) {
            switch (num_filhos) {
                case 0:
                    return tabela_coluna_1;
                case 1:
                    return tabela_coluna_2;
                case 2:
                    return tabela_coluna_3;
                case 3:
                    return tabela_coluna_4;
                case 4:
                    return tabela_coluna_5;
                default:
                    return tabela_coluna_6;

            }
        }
        tabela_coluna_0_anterior = tabela_coluna_0;
        tabela_coluna_1_anterior = tabela_coluna_1;
        tabela_coluna_2_anterior = tabela_coluna_2;
        tabela_coluna_3_anterior = tabela_coluna_3;
        tabela_coluna_4_anterior = tabela_coluna_4;
        tabela_coluna_5_anterior = tabela_coluna_5;
        tabela_coluna_6_anterior = tabela_coluna_6;

        teste = fgets(linha, MAX_LINHA, tabela);
        sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
                &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    }

    switch (num_filhos) {//ler a linha de superiro a ...
        case 0:
            return tabela_coluna_1_anterior;
        case 1:
            return tabela_coluna_2_anterior;
        case 2:
            return tabela_coluna_3_anterior;
        case 3:
            return tabela_coluna_4_anterior;
        case 4:
            return tabela_coluna_5_anterior;
        default:
            return tabela_coluna_6_anterior;

    }
    fclose(tabela);
}

double alterar_tabela_casado_unico_titular(double salario_iliquido, int num_filhos, double novo_valor) {
    double tabela_coluna_0_anterior, tabela_coluna_1_anterior, tabela_coluna_2_anterior, tabela_coluna_3_anterior,
            tabela_coluna_4_anterior, tabela_coluna_5_anterior, tabela_coluna_6_anterior;
    double tabela_coluna_0, tabela_coluna_1, tabela_coluna_2, tabela_coluna_3,
            tabela_coluna_4, tabela_coluna_5, tabela_coluna_6;

    FILE *tabela = fopen("casado_unico_titual.txt", "r");
    FILE *nova_tabela = fopen("novo_casado_unico_titual.txt", "w");

    char linha[MAX_LINHA + 1];
    char *teste;
    teste = (char *) malloc(sizeof (char) * (MAX_LINHA + 1));

    teste = fgets(linha, MAX_LINHA, tabela);
    sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
            &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    while (teste != NULL) {
        if (salario_iliquido < tabela_coluna_0) {
            switch (num_filhos) {
                case 0:
                    tabela_coluna_1 = novo_valor;
                    break;
                case 1:
                    tabela_coluna_2 = novo_valor;
                    break;
                case 2:
                    tabela_coluna_3 = novo_valor;
                    break;
                case 3:
                    tabela_coluna_4 = novo_valor;
                    break;
                case 4:
                    tabela_coluna_5 = novo_valor;
                    break;
                default:
                    tabela_coluna_6 = novo_valor;
                    break;
            }
        }

        fprintf(nova_tabela, "%lf;%lf;%lf;%lf;%lf;%lf;%lf\n", tabela_coluna_0,
                tabela_coluna_1, tabela_coluna_2, tabela_coluna_3, tabela_coluna_4, tabela_coluna_5, tabela_coluna_6);

        tabela_coluna_0_anterior = tabela_coluna_0;
        tabela_coluna_1_anterior = tabela_coluna_1;
        tabela_coluna_2_anterior = tabela_coluna_2;
        tabela_coluna_3_anterior = tabela_coluna_3;
        tabela_coluna_4_anterior = tabela_coluna_4;
        tabela_coluna_5_anterior = tabela_coluna_5;
        tabela_coluna_6_anterior = tabela_coluna_6;

        teste = fgets(linha, MAX_LINHA, tabela);
        sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
                &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    }

    switch (num_filhos) {
        case 0:
            tabela_coluna_1_anterior = novo_valor;
            break;
        case 1:
            tabela_coluna_2_anterior = novo_valor;
            break;
        case 2:
            tabela_coluna_3_anterior = novo_valor;
            break;
        case 3:
            tabela_coluna_4_anterior = novo_valor;
            break;
        case 4:
            tabela_coluna_5_anterior = novo_valor;
            break;
        default:
            tabela_coluna_6_anterior = novo_valor;
            break;
    }

    fprintf(nova_tabela, "%lf;%lf;%lf;%lf;%lf;%lf;%lf\n", tabela_coluna_0_anterior,
            tabela_coluna_1_anterior, tabela_coluna_2_anterior, tabela_coluna_3_anterior, tabela_coluna_4_anterior
            , tabela_coluna_5_anterior, tabela_coluna_6_anterior);
    fclose(tabela);
    fclose(nova_tabela);

    tabela = fopen("casado_unico_titual.txt", "w");
    nova_tabela = fopen("temp_casado_unico_titual.txt", "r");

    teste = fgets(linha, MAX_LINHA, nova_tabela);
    sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
            &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    while (teste != NULL) {
        fprintf(tabela, "%lf;%lf;%lf;%lf;%lf;%lf;%lf\n", tabela_coluna_0,
                tabela_coluna_1, tabela_coluna_2, tabela_coluna_3, tabela_coluna_4, tabela_coluna_5, tabela_coluna_6);

        tabela_coluna_0_anterior = tabela_coluna_0;
        tabela_coluna_1_anterior = tabela_coluna_1;
        tabela_coluna_2_anterior = tabela_coluna_2;
        tabela_coluna_3_anterior = tabela_coluna_3;
        tabela_coluna_4_anterior = tabela_coluna_4;
        tabela_coluna_5_anterior = tabela_coluna_5;
        tabela_coluna_6_anterior = tabela_coluna_6;

        teste = fgets(linha, MAX_LINHA, nova_tabela);
        sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
                &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);

    }
    fclose(tabela);
    fclose(nova_tabela);
}

double ler_tabela_casado_dois_titulares(double salario_iliquido, int num_filhos) {
    double tabela_coluna_0_anterior, tabela_coluna_1_anterior, tabela_coluna_2_anterior, tabela_coluna_3_anterior,
            tabela_coluna_4_anterior, tabela_coluna_5_anterior, tabela_coluna_6_anterior;
    double tabela_coluna_0, tabela_coluna_1, tabela_coluna_2, tabela_coluna_3,
            tabela_coluna_4, tabela_coluna_5, tabela_coluna_6;

    FILE *tabela = fopen("casado_dois_titulares.txt", "r");

    char linha[MAX_LINHA + 1];
    char *teste;
    teste = (char *) malloc(sizeof (char) * (MAX_LINHA + 1));

    teste = fgets(linha, MAX_LINHA, tabela);
    sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
            &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    while (teste != NULL) {
        if (salario_iliquido < tabela_coluna_0) {
            switch (num_filhos) {
                case 0:
                    return tabela_coluna_1;
                case 1:
                    return tabela_coluna_2;
                case 2:
                    return tabela_coluna_3;
                case 3:
                    return tabela_coluna_4;
                case 4:
                    return tabela_coluna_5;
                default:
                    return tabela_coluna_6;

            }
        }
        tabela_coluna_0_anterior = tabela_coluna_0;
        tabela_coluna_1_anterior = tabela_coluna_1;
        tabela_coluna_2_anterior = tabela_coluna_2;
        tabela_coluna_3_anterior = tabela_coluna_3;
        tabela_coluna_4_anterior = tabela_coluna_4;
        tabela_coluna_5_anterior = tabela_coluna_5;
        tabela_coluna_6_anterior = tabela_coluna_6;

        teste = fgets(linha, MAX_LINHA, tabela);
        sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
                &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    }

    switch (num_filhos) {//ler a linha de superiro a ...
        case 0:
            return tabela_coluna_1_anterior;
        case 1:
            return tabela_coluna_2_anterior;
        case 2:
            return tabela_coluna_3_anterior;
        case 3:
            return tabela_coluna_4_anterior;
        case 4:
            return tabela_coluna_5_anterior;
        default:
            return tabela_coluna_6_anterior;

    }
    fclose(tabela);
}

double alterar_tabela_casado_dois_titulares(double salario_iliquido, int num_filhos, double novo_valor) {
    double tabela_coluna_0_anterior, tabela_coluna_1_anterior, tabela_coluna_2_anterior, tabela_coluna_3_anterior,
            tabela_coluna_4_anterior, tabela_coluna_5_anterior, tabela_coluna_6_anterior;
    double tabela_coluna_0, tabela_coluna_1, tabela_coluna_2, tabela_coluna_3,
            tabela_coluna_4, tabela_coluna_5, tabela_coluna_6;

    FILE *tabela = fopen("casado_dois_titulares.txt", "r");
    FILE *nova_tabela = fopen("novo_casado_dois_titulares.txt", "w");

    char linha[MAX_LINHA + 1];
    char *teste;
    teste = (char *) malloc(sizeof (char) * (MAX_LINHA + 1));

    teste = fgets(linha, MAX_LINHA, tabela);
    sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
            &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    while (teste != NULL) {
        if (salario_iliquido < tabela_coluna_0) {
            switch (num_filhos) {
                case 0:
                    tabela_coluna_1 = novo_valor;
                    break;
                case 1:
                    tabela_coluna_2 = novo_valor;
                    break;
                case 2:
                    tabela_coluna_3 = novo_valor;
                    break;
                case 3:
                    tabela_coluna_4 = novo_valor;
                    break;
                case 4:
                    tabela_coluna_5 = novo_valor;
                    break;
                default:
                    tabela_coluna_6 = novo_valor;
                    break;
            }
        }

        fprintf(nova_tabela, "%lf;%lf;%lf;%lf;%lf;%lf;%lf\n", tabela_coluna_0,
                tabela_coluna_1, tabela_coluna_2, tabela_coluna_3, tabela_coluna_4, tabela_coluna_5, tabela_coluna_6);

        tabela_coluna_0_anterior = tabela_coluna_0;
        tabela_coluna_1_anterior = tabela_coluna_1;
        tabela_coluna_2_anterior = tabela_coluna_2;
        tabela_coluna_3_anterior = tabela_coluna_3;
        tabela_coluna_4_anterior = tabela_coluna_4;
        tabela_coluna_5_anterior = tabela_coluna_5;
        tabela_coluna_6_anterior = tabela_coluna_6;

        teste = fgets(linha, MAX_LINHA, tabela);
        sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
                &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    }

    switch (num_filhos) {
        case 0:
            tabela_coluna_1_anterior = novo_valor;
            break;
        case 1:
            tabela_coluna_2_anterior = novo_valor;
            break;
        case 2:
            tabela_coluna_3_anterior = novo_valor;
            break;
        case 3:
            tabela_coluna_4_anterior = novo_valor;
            break;
        case 4:
            tabela_coluna_5_anterior = novo_valor;
            break;
        default:
            tabela_coluna_6_anterior = novo_valor;
            break;
    }

    fprintf(nova_tabela, "%lf;%lf;%lf;%lf;%lf;%lf;%lf\n", tabela_coluna_0_anterior,
            tabela_coluna_1_anterior, tabela_coluna_2_anterior, tabela_coluna_3_anterior, tabela_coluna_4_anterior
            , tabela_coluna_5_anterior, tabela_coluna_6_anterior);
    fclose(tabela);
    fclose(nova_tabela);

    tabela = fopen("casado_dois_titulares.txt", "w");
    nova_tabela = fopen("temp_casado_dois_titulares.txt", "r");

    teste = fgets(linha, MAX_LINHA, nova_tabela);
    sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
            &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);
    while (teste != NULL) {
        fprintf(tabela, "%lf;%lf;%lf;%lf;%lf;%lf;%lf\n", tabela_coluna_0,
                tabela_coluna_1, tabela_coluna_2, tabela_coluna_3, tabela_coluna_4, tabela_coluna_5, tabela_coluna_6);

        tabela_coluna_0_anterior = tabela_coluna_0;
        tabela_coluna_1_anterior = tabela_coluna_1;
        tabela_coluna_2_anterior = tabela_coluna_2;
        tabela_coluna_3_anterior = tabela_coluna_3;
        tabela_coluna_4_anterior = tabela_coluna_4;
        tabela_coluna_5_anterior = tabela_coluna_5;
        tabela_coluna_6_anterior = tabela_coluna_6;

        teste = fgets(linha, MAX_LINHA, nova_tabela);
        sscanf(linha, "%lf;%lf;%lf;%lf;%lf;%lf;%lf", &tabela_coluna_0,
                &tabela_coluna_1, &tabela_coluna_2, &tabela_coluna_3, &tabela_coluna_4, &tabela_coluna_5, &tabela_coluna_6);

    }
    fclose(tabela);
    fclose(nova_tabela);
}

void menu_tabela_irs() {

    int op, num_filhos;
    double salario_iliquido, novo_valor;


    do {
        printf("\t GESTÃO DE \n");
        printf("\tTABELAS IRS\n");
        printf("-----------------------\n");
        printf("0 - Sair\n");
        printf("Tabela não casado\n");
        printf("1 - Ler tabela\n");
        printf("2 - Editar tabela\n");
        printf("Tabela único titular\n");
        printf("3 - Ler tabela\n");
        printf("4 - Editar tabela\n");
        printf("Tabela dois titulares\n");
        printf("5 - Ler tabela\n");
        printf("6 - Editar tabela\n");
        printf("-----------------------\n");
        
        op = obter_int(0, 6, "Opção: ");
        switch (op) {
            case 0:
                break;
            case 1:
                ler_tabela_nao_casado(salario_iliquido, num_filhos);
                break;
            case 2:
                alterar_tabela_nao_casado(salario_iliquido, num_filhos, novo_valor);
                break;
            case 3:
                ler_tabela_casado_unico_titular(salario_iliquido, num_filhos);
                break;
            case 4:
                alterar_tabela_casado_unico_titular(salario_iliquido, num_filhos, novo_valor);
            case 5:
                ler_tabela_casado_dois_titulares(salario_iliquido, num_filhos);
                break;
            case 6:
                alterar_tabela_casado_dois_titulares(salario_iliquido, num_filhos, novo_valor);
                break;

        }
    } while (op != 0);
}