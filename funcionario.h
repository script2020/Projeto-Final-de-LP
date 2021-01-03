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



#define  MAX_FUNCIONARIOS  2000
#define  TAM_NOME  200   
#define  MIN_NUM_FUNCIONARIO  0
#define  MAX_NUM_FUNCIONARIO  10000
#define  MIN_DIA  0
#define  MAX_DIA  31
#define  MIN_MES  1
#define  MAX_MES  12
#define  MIN_ANO  1900
#define  MAX_ANO  2021
#define  MIN_TELEMOVEL  0 
#define  MAX_TELEMOVEL  9
#define  MIN_VENC_BASE  0
#define  MAX_VENC_BASE  10
#define  MIN_SUB_ALIMENTACAO  0
#define  MAX_SUB_ALIMENTACAO  100  
#define  MIN_FILHOS  0
#define  MAX_FILHOS  100  
#define  MIN_CARGO 0
#define  MAX_CARGO 6
#define VENC_BASE_EMP_LIMP 2.65
#define VENC_BASE_COST 2.90
#define VENC_BASE_SOC_GER 3.13
#define VENC_BASE_ENC_LINHA 3.44
#define VENC_BASE_EMP_ESC 4.16
#define VENC_BASE_MOD  6.25
    
typedef enum {
    casado, solteiro, viuvo, divorciada
}Estado_civil;

typedef enum {
    empregada_limpeza,
    costureira,
    modelista,
    empregada_escritorio,
    encarregada_linha,
    socio_gerente
}Cargo;

typedef struct  {
    int tm_sec; //representa os segundos de 0 a 59
    int tm_min; //representa os minutos de 0 a 59
    int tm_hour; //representa as horas de 0 a 24
    int tm_mday; //dia do mês de 1 a 31
    int tm_mon; //representa os meses do ano de 0 a 11
    int tm_year; //representa o ano a partir de 1900
    int tm_wday; //dia da semana de 0 (domingo) até 6 (sábado)
    int tm_yday; // dia do ano de 1 a 365
    int tm_isdst; //indica horário de verão se for diferente de zero
}Time;
    
typedef struct {
    int dia, mes, ano;
}Data;

typedef enum {
    false , true
}Bool;

typedef struct {
    int codigo, numero_telemovel, numero_filhos ;
    char nome [TAM_NOME];
    Cargo cargo;
    Estado_civil estado_civil;
    Data data_entrada, data_saida, data_nascimento, tempo_empresa;
    float subsidio_alimentacao, vencimento_base;
    int registo; 
    Bool eliminado;
}Funcionario;

  
void criar_funcionario(Funcionario * funcionario);
void editar_funcionario(Funcionario * funcionario);
void remover_funcionario(Funcionario * funcionario);
void mostrar_funcionario(Funcionario *funcionario);
Bool esta_removido(Funcionario *funcionario);
void criar_Data(Data* data, int dia, int mes, int ano);
Funcionario procurar_funcionario(int codigo, FILE *file);



#ifdef __cplusplus
}
#endif

#endif /* FUNCIONARIO_H */

