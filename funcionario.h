/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionario.h
 * Author: Gabriel
 *
 * Created on 9 de dezembro de 2020, 19:52
 */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#ifdef __cplusplus
extern "C" {
#endif
   
#define TAM_NOME 100
   
void criar_funcionario(Funcionario *funcionario, int *registo);
   
   typedef struct{
    int codigo,numero_telemovel,numero_filhos;
    int tempo_empresa;
    char nome[TAM_NOME],cargo,estado_civil;
    Data data_entrada,data_saida;
    float subsidio_alimentacao, vencimento_base;
}Funcionario;
   
typedef struct{
    int dia,mes,ano;
}Data;


#ifdef __cplusplus
}
#endif

#endif /* FUNCIONARIO_H */

