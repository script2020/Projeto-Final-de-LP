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

typedef struct {
    int nDiasComp, nDiasMeio, nDiasFimSemana,nDiasFalta;
    float salBase,valorBonus;
}Salario;

void carregarFicheiro();

float calSalBase();

float calBonus(Salario *salarios);

#endif /* SALARIOS_H */

