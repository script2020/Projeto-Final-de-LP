/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   salarios.h
 * Author: pedro
 *
 * Created on 13 de janeiro de 2021, 15:59
 */

#ifndef SALARIOS_H
#define SALARIOS_H

#define N_MESES 12

typedef struct {
    int nDiasComp, nDiasMeio, nDiasFimSemana, nDiasFalta;
    float salBruto, valorBonus, subsidioAlimentacao, valorIliquido, IRS, valorLiquido, SegurancaSocial;
} Salario;

typedef struct {
    Salario salarios[N_MESES];
    int mes;
}Salarios;


int carregarFicheiro();

float calcularSalarioBruto(Salario *salarios,Salarios *salario);

float calcularBonus(Salario *salarios,Salarios *salario);

float calcularSubsidioAlimentacao(Salario *salarios,Salarios *salario);

float calcularValorIliquido(Salario *salarios,Salarios *salario);

float calcularValorLiquido(Salario *salarios,Salarios *salario);

float calcularSegurancaSocial(Salario *salarios,Salarios *salario);

float calcularIRS(Salario *salarios,Salarios *salario);
#endif /* SALARIOS_H */

