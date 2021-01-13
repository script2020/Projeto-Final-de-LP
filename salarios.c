/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "salarios.txt"
#define STR_SIZE 100

/**
 * Esta função vai ler o ficheiro com as informações para processar o salário
 * 
 */
int lerFicheiro(){
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    if (fgets(str, STR_SIZE, fp) != NULL) {
        puts(str);
    }

    return 0;
}
