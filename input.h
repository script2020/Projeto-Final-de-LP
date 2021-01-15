/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   input.h
 * Author: Maria
 *
 * Created on 30 de dezembro de 2020, 13:42
 */

#ifndef INPUT_H
#define INPUT_H

#ifdef __cplusplus
extern "C" {
#endif
    
    void clean_input_buffer();
    int obter_int(int min_valor, int max_valor, char *msg);
    float obter_float(float min_valor, float max_valor, char *msg);
    double obter_double(double min_valor, double max_valor, char *msg);
    char obter_char(char *msg);
    void ler_string(char *string, unsigned int tamanho, char *msg);
    

#ifdef __cplusplus
}
#endif

#endif /* INPUT_H */

