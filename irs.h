/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   irs.h
 * Author: Maria
 *
 * Created on 12 de janeiro de 2021, 15:22
 */

#ifndef IRS_H
#define IRS_H

#ifdef __cplusplus
extern "C" {
#endif
  
    double ler_tabela_nao_casado(double salario_iliquido, int num_filhos);
    void alterar_tabela_nao_casado(double salario_iliquido, int num_filhos,double novo_valor);
    double ler_tabela_casado_unico_titular(double salario_iliquido, int num_filhos);
    void alterar_tabela_casado_unico_titular(double salario_iliquido, int num_filhos, double novo_valor);
    double ler_tabela_casado_dois_titulares(double salario_iliquido, int num_filhos);
    void alterar_tabela_casado_dois_titulares(double salario_iliquido, int num_filhos, double novo_valor);
    void menu_tabela_irs();

#ifdef __cplusplus
}
#endif

#endif /* IRS_H */

