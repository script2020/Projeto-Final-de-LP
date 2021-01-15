/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"
#include "irs.h"
#include "salarios.h"
#include "funcionario.h"
#include "seg_social.h"



/**
 * Esta função vai ler o ficheiro com as informações para processar o salário
 * @param ficheiro
 */
int carregarFicheiro() {
    
    
    Salario salarios;
    Funcionario *funcionario;
    
    
    int mes;
    
    mes = obter_int(1, 12, "Indique o mês que prentende processar (1 a 12): ");

    switch (mes) {
        case 1:
            
        {
            FILE *fp = fopen("janeiro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            return 1;
        }
            break;
            
        case 2:
           
        {
            FILE *fp = fopen("janeiro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            return 1;
        }
            break;
        case 3:
        {
            FILE *fp = fopen("fevereiro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            return 1;
        }
            break;
        case 4:
        {
            FILE *fp = fopen("marco.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            return 1;
        }
            break;
        case 5:
        {
            FILE *fp = fopen("abril.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            return 1;
        }
            break;
        case 6:
        {
            
            FILE *fp = fopen("maio.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            return 1;
        }
            break;
        case 7:
        {
            FILE *fp = fopen("julho.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            return 1;
        }
            break;
        case 8:
        {
            FILE *fp = fopen("agosto.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
        }
            break;
        case 9:
        {
            FILE *fp = fopen("setembro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            return 1;
        }
            break;
        case 10:
        {
            FILE *fp = fopen("outubro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);

            return 1;
        }
            break;
        case 11:
        {
            FILE *fp = fopen("novembro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);

            return 1;
        }
            break;
        case 12:
        {
            FILE *fp = fopen("dezembro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &funcionario->codigo, &salarios.nDiasComp,
                    &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
        }
            break;

            return 1;
        default:
            puts("Opção Inválida");
            break;
    }


    return 0;
}

/**
 * Esta função vai calcular o salário base do funcionário
 * @param salarios
 */
float calcularSalarioBruto(Salario *salarios) {
    
    Funcionario *funcionario;
    float salFimSemana, salFimSemanaValorizacao, salFimSemanaFinal, vencBase;


    if (carregarFicheiro() == 1) {

        switch (funcionario->cargo) {
            case 0:
                vencBase = VENC_BASE_EMP_LIMP;
                break;
            case 1:
                vencBase = VENC_BASE_COST;
                break;
            case 2:
                vencBase = VENC_BASE_MOD;
                break;
            case 3:
                vencBase = VENC_BASE_EMP_ESC;
                break;
            case 4:
                vencBase = VENC_BASE_ENC_LINHA;
                break;
            case 5:
                vencBase = VENC_BASE_SOC_GER;
                break;
            default:
                printf("Opção inválida!");
                    
        }
        
       
        salFimSemana = salarios->nDiasFimSemana * (8 * vencBase);
        salFimSemanaValorizacao = salFimSemana * 0.5;
        salFimSemanaFinal = salFimSemana + salFimSemanaValorizacao;
        salarios->salBruto = ((salarios->nDiasComp * (8 * vencBase)) + (salarios->nDiasMeio * (4 * vencBase)) + salFimSemanaFinal);

        return salarios->salBruto;
    }
}

/**
 * Esta função vai calcular o subsídio de alimentação de cada funcionário
 * @param salarios
 */
float calcularSubsidioAlimentacao(Salario *salarios) {
    return salarios->subsidioAlimentacao = (salarios->nDiasComp * SUB_ALIMENTACAO + salarios->nDiasFimSemana * SUB_ALIMENTACAO);
}

/**
 * Esta função vai calcular o bonus do funcionario com base nos anos de serviço
 * na empresa, e no número de faltas
 * @param Salario *salarios
 */
float calcularBonus(Salario *salarios) {
    float bonusAnos, bonusFaltas;
    Funcionario *funcionario;
    
    calcular_tempo_empresa_saiu(funcionario);
    if (funcionario->saida == 0) {
        if (funcionario->tempo_empresa.ano >= 10) {
            bonusAnos = 0.1;
            salarios->valorBonus = calcularSalarioBruto(salarios) * bonusAnos;
        }

        if (salarios->nDiasFalta == 0) {
            bonusFaltas = 0.05;
            salarios->valorBonus = calcularSalarioBruto(salarios) * bonusFaltas;
        }

        return salarios->valorBonus;
    }
}

/**
 * Esta função vai calcular o valor iliquido(Base + Bonus) a receber pelo funcionário
 * @param *salarios
 */
float calcularValorIliquido(Salario *salarios) {

    salarios->valorIliquido = calcularSalarioBruto(salarios) + calcularBonus(salarios);

    return salarios->valorIliquido;
}

/**
 * Esta função vai calcular o valor liquido a receber pelo funcionário
 * @param *salarios
 */
float calcularIRS(Salario *salarios) {
    int titular;
    Funcionario *funcionario;

    titular = obter_int(1, 2, "Indique que tipo de titular é (1-unico; 2 - dois titulares)");

    if (titular == 1 && funcionario->estado_civil == 1) {
        ler_tabela_casado_unico_titular(calcularValorIliquido(salarios), funcionario->numero_filhos);
        return salarios->IRS = calcularSalarioBruto(salarios) * ler_tabela_casado_unico_titular(calcularValorIliquido(salarios), funcionario->numero_filhos);
    }

    if (titular == 2 && funcionario->estado_civil == 1) {
        ler_tabela_casado_dois_titulares(calcularValorIliquido(salarios), funcionario->numero_filhos);
    }

    if (funcionario->estado_civil == 3 || funcionario->estado_civil == 4 || funcionario->estado_civil == 0 || funcionario->estado_civil == 2) {
        ler_tabela_nao_casado(calcularValorIliquido(salarios), funcionario->numero_filhos);
    }

    return salarios->IRS = calcularSalarioBruto(salarios);
}
/**
 * Esta função vai calcular o valor liquido a receber pelo funcionário
 * @param *salarios
 */

float calcularSegurancaSocial(Salario *salarios) {
    
    Funcionario *funcionario;
    return salarios->SegurancaSocial = calcularSalarioBruto(&salarios) * ler_tabela_trabalhador_geral(funcionario->cargo);
}
float calcularValorLiquido(Salario *salarios) {

    return salarios->valorLiquido = calcularValorIliquido(salarios) + calcularIRS(salarios) + calcularSegurancaSocial(salarios);
}


void menuSalarios() {
    int op;
    Salario salarios;

    do {
        printf("\t GESTÃO DE \n");
        printf("\tSALARIOS\n");
        printf("-----------------------\n");
        printf("1 - Carregar ficheiro de processamento de salário\n");
        printf("2 - Processar os salários \n");
        printf("0 - Voltar\n");
        printf("-----------------------\n");

        op = obter_int(0, 4, "Opção: ");
        switch (op) {
            case 1:
                carregarFicheiro();
                break;
            case 2:
                calcularValorLiquido(&salarios);
                break;
        }
    } while (op != 0);
}

