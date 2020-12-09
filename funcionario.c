/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"
/*
 * 
 */

void criar_funcionario(Funcionario *funcionario, int *registo) {
    printf("\nNome do funcionário:\n");
    scanf(" %s", &funcionario->nome);
    printf("\nNúmero de funcionário:\n");
    scanf(" %d", &funcionario->codigo);
    printf("\nNnúmero de telemóvel do funcionário:\n");
    scanf(" %d", &funcionario->numero_telemovel);
    printf("\nCargo:\n");
    printf("\nEL ou el - Empregado/a de limpeza.\n");
    printf("\nC ou c - Costureira.\n");
    printf("\nM ou m - modelista.\n");
    printf("\nEE ou ee- Empregado/a de escritório.\n");
    printf("\nECL ou ecl - Encerregado/a de linha.\n");
    printf("\nSG ou sg - Sócio/a gerente.\n");
    printf("\nResposta:\n");
    scanf(" %c", &funcionario->cargo);
    printf("\nNúmero de filhos:\n");
    scanf(" %d", &funcionario->numero_filhos);
    printf("\nVencimento base(valor/hora):\n");
    scanf(" %f", &funcionario->vencimento_base);
    printf("\nSubsídio de alimentação:\n");
    scanf(" %f", &funcionario->subsidio_alimentacao);
    printf("\nEstado civil:\n");
    printf("\nS ou s - Solteiro/a.\n");
    printf("\nC ou c - Casado/a.\n");
    printf("\nD ou d - Divorciado/a");
    printf("\nV ou v - Viúvo/a");
    printf("\nS ou s - Separado/a\n");
    scanf(" %c", &funcionario->estado_civil);
    printf("\nTempo de trabalho na esmpreza:\n");
    printf("\nDia:\n");
    scanf(" %d", &Data->dia);
    printf("\nMês:\n");
    scanf(" %d", &Data->mes);
    printf("\nAno:\n");
    scanf(" %d", &Data->ano);
    printf("\nData de entrada na empresa:\n");
    printf("\nDia:\n");
    scanf(" %d", &Data->dia);
    printf("\nMês:\n");
    scanf(" %d", &Data->mes);
    printf("\nAno:\n");
    scanf(" %d", &Data->ano);
    printf("\nData de saida da empresa:\n");//ele pode nao ter saido,ter isso em conta
    printf("\nDia:\n");
    scanf(" %d", &Data->dia);
    printf("\nMês:\n");
    scanf(" %d", &Data->mes);
    printf("\nAno:\n");
    scanf(" %d", &Data->ano);
    printf("\n\n");

    (*registo)++;
}
