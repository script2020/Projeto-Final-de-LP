/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   seg_social.h
 * Author: Maria
 *
 * Created on 13 de janeiro de 2021, 18:32
 */

#ifndef SEG_SOCIAL_H
#define SEG_SOCIAL_H

#ifdef __cplusplus
extern "C" {
#endif

    void menu_tabela_seg_social();
    double ler_tabela_trabalhador_geral(int cargo);
    double alterar_tabela_trabalhador_geral(int cargo, double novo_valor);


#ifdef __cplusplus
}
#endif

#endif /* SEG_SOCIAL_H */

