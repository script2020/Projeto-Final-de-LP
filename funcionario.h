/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funcionario.h
 * Author: Maria
 *
 * Created on 14 de dezembro de 2020, 18:09
 */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_FUNCIONARIOS 2000
#define TAM_NOME 200   
#define MIN_NUM_FUNCIONARIO 0
#define MAX_NUM_FUNCIONARIO 10000
#define MIN_DIA 0
#define MAX_DIA 31
#define MIN_MES 1
#define MAX_MES 12
#define MIN_ANO 1900
#define MAX_ANO 2021
#define MIN_TELEMOVEL 0 //minimo poe se zero??
#define MAX_TELEMOVEL 9
#define MIN_VENC_BASE 0
#define MAX_VENC_BASE 100 //pus um numero à sorte,VER ISSO
#define MIN_SUB_ALIMENTACAO 0
#define MAX_SUB_ALIMENTACAO 100 //pus um numero à sorte,VER ISSO
#define MIN_FILHOS 0
#define MAX_FILHOS 100   //pus um numero à sorte,VER ISSO

    
    
    
    

    
    typedef struct {
        int dia, mes, ano;
    } Data;

    typedef struct {
        int codigo, numero_telemovel, numero_filhos;
        char nome [TAM_NOME], cargo, estado_civil;
        Data data_entrada, data_saida, data_nascimento, tempo_empresa;
        float subsidio_alimentacao, vencimento_base;
        int registo;
    } Funcionario;
    
typedef struct {
        int registo;
        Funcionario funcionarios[MAX_FUNCIONARIOS];
    } Funcionarios;


    int criarFuncionario(Funcionario *funcionario, int * registo);
    void editarFuncionario(Funcionario *funcionario);
    void removerFuncionario(Funcionario *funcionario);
    int procurarFucnionario(Funcionario funcionario, int *registo);
    
  
    
    




#ifdef __cplusplus
}
#endif

#endif /* FUNCIONARIO_H */

