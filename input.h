/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   input.h
 * Author: Maria
 *
 * Created on 14 de dezembro de 2020, 18:10
 */

#ifndef INPUT_H
#define INPUT_H

#ifdef __cplusplus
extern "C" {
#endif


int obter_int(int minValor, int maxValor, char *msg);
float obter_float(float minValor, float maxValor, char *msg);
double obter_double(double minValor, double maxValor, char *msg);
char obter_char(char *msg);
void ler_string(char *string, unsigned int tamanho, char *msg);


#ifdef __cplusplus
}
#endif

#endif /* INPUT_H */

