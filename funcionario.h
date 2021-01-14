/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funcionario.h
 * Author: Maria
 *
 * Created on 30 de dezembro de 2020, 13:36
 */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_FUNCIONARIOS  2000
#define TAM_NOME  200   
#define MIN_NUM_FUNCIONARIO  0
#define MAX_NUM_FUNCIONARIO  10000
#define MIN_DIA  0
#define MAX_DIA  31
#define MIN_MES  1
#define MAX_MES  12
#define MIN_ANO  1900
#define MAX_ANO  2021
#define MIN_TELEMOVEL  0 
#define MAX_TELEMOVEL  999999999
#define SUB_ALIMENTACAO 4.30
#define MIN_FILHOS  0
#define MAX_FILHOS  100  
#define VENC_BASE_EMP_LIMP 2.65
#define VENC_BASE_COST 2.90
#define VENC_BASE_SOC_GER 3.13
#define VENC_BASE_ENC_LINHA 3.44
#define VENC_BASE_EMP_ESC 4.16
#define VENC_BASE_MOD  6.25
#define MIN_PREFIXO 0
#define MAX_PREFIXO 9999
#define MAX_ESTADO_CIVIL 5
#define MIN_ESTADO_CIVIL 0

    typedef enum {
        casado, solteiro, divorciado, viuvo, separado
    } Estado_civil;

    typedef enum {
        empregada_limpeza,
        costureira,
        modelista,
        empregada_escritorio,
        encarregada_linha,
        socio_gerente
    } Cargo;

    typedef struct {
        int tm_sec; //representa os segundos de 0 a 59
        int tm_min; //representa os minutos de 0 a 59
        int tm_hour; //representa as horas de 0 a 24
        int tm_mday; //dia do mês de 1 a 31
        int tm_mon; //representa os meses do ano de 0 a 11
        int tm_year; //representa o ano a partir de 1900
        int tm_wday; //dia da semana de 0 (domingo) até 6 (sábado)
        int tm_yday; // dia do ano de 1 a 365
        int tm_isdst; //indica horário de verão se for diferente de zero
    } tm;

    typedef struct {
        int dia, mes, ano;
    } Data;

    typedef enum {
        false, true
    } Bool;

    typedef struct {
        Bool eliminado;
        int codigo, numero_telemovel, numero_filhos, indicativo_numero_telemovel, saida;
        char nome [TAM_NOME];
        Cargo cargo;
        Estado_civil estado_civil;
        Data data_entrada, data_saida, data_nascimento, tempo_empresa, data_entrada_temp, data_saida_temp;
        float subsidio_alimentacao, vencimento_base, ent_empregadora_seg_social;
        tm data_atual, data_atual_temp;

    } Funcionario;

    void criar_funcionario(Funcionario *funcionario, Funcionario *lista_funcionarios, int tam_lista, FILE *file);
    void editar_funcionario(Funcionario * funcionario);
    void remover_funcionario(Funcionario * funcionario);
    void mostrar_funcionario(Funcionario *funcionario);
    Bool esta_removido(Funcionario *funcionario);
    void criar_Data(Data* data, int dia, int mes, int ano);
    void calcular_tempo_empresa_saiu(Funcionario *funcionario);
    void time_now();
    void calcurar_tempo_empresa(Funcionario *funcionario);
    Funcionario procurar_funcionario(int codigo, Funcionario *lista_funcionarios, int tam_lista, FILE *file);
    void menu_funcionario(Funcionario *lista_funcionarios, int tam_lista, FILE *file);


#ifdef __cplusplus
}
#endif

#endif /* FUNCIONARIO_H */

