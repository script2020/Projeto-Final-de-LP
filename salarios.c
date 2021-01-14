/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <input.h>
#include <salarios.h>
#include <funcionario.h>

#define FILENAME "janeiro_2021.txt"

/**
 * Esta função vai ler o ficheiro com as informações para processar o salário
 * @param ficheiro
 */
void carregarFicheiro(){
    Salario salarios;
    int mes;
    
    mes = obter_int(1, 12,"Indique o mês que prentende processar");

    switch (mes) {
        case 1:
            FILE *fp = fopen("janeiro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 2:
            FILE *fp = fopen("janeiro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 3:
            FILE *fp = fopen("fevereiro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 4:
            FILE *fp = fopen("marco.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 5:
            FILE *fp = fopen("abril.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 6:
            FILE *fp = fopen("maio.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 7:
            FILE *fp = fopen("julho.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 8:
            FILE *fp = fopen("agosto.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 9:
            FILE *fp = fopen("setembro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 10:
            FILE *fp = fopen("outubro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 11:
            FILE *fp = fopen("novembro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        case 12:
            FILE *fp = fopen("dezembro.txt", "r");
            if (fp == NULL) {
                exit(EXIT_FAILURE);
            }

            //só está a ler uma linha
            fscanf(fp, "%d %d %d %d %d", &Funcionario.codigo, &salarios.nDiasComp, &salarios.nDiasMeio, &salarios.nDiasFimSemana, &salarios.nDiasFalta);
            fclose(fp);
            break;
        default:
            puts("Opção Inválida");
            break;
    }
    
}

/**
 * Esta função vai calcular o salário base do funcionário
 * @param
 */
float calSalBase(){
    Salario salarios;
    
    float salFimSemana,salFimSemanaValorizacao,salFimSemanaFinal;
    
    salFimSemana = salarios.nDiasFimSemana * (8 * 2.65);
    salFimSemanaValorizacao = salFimSemana *0.5;
    salFimSemanaFinal = salFimSemana + salFimSemanaValorizacao;
    salarios.salBase = ((salarios.nDiasComp * (8 * 2.65)) + (salarios.nDiasMeio * (4 * 2.65)) + salFimSemanaFinal);

    return salarios.salBase;
}

/**
 * Esta função vai calcular o bonus do funcionario com base nos anos de serviço
 * na empresa, e no número de faltas
 * @param Salario *salarios
 */
float calBonus(Salario *salarios){
    int anosServico;
    float bonusAnos,bonusFaltas;
    
    anosServico = Funcionario.data_entrada - Funcionario.data_saida;
    
    if(anosServico >= 10){
        bonusAnos = 0.1;
    }
    
    if(salarios.nDiasFalta == 0){
        bonusFaltas = 0.05;
    }
    
    salarios.valorBonus = calSalBase() * bonusAnos + calSalBase() * bonusFaltas;
    
    return salarios.valorBonus;
}

