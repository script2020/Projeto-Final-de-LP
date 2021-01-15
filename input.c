/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <string.h>

#define VALOR_INVALIDO "O valor inserido é inválido."

void clean_input_buffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int obter_int(int min_valor, int max_valor, char *msg) {
    int valor;
    printf(msg);
    while (scanf(" %d", &valor) != 1 || valor < min_valor || valor > max_valor) {
        puts(VALOR_INVALIDO);

        clean_input_buffer();

        printf(msg);
    }

    clean_input_buffer();

    return valor;
}

float obter_float(float min_valor, float max_valor, char *msg) {
    float valor;
    printf(msg);
    while (scanf(" %f", &valor) != 1 || valor < min_valor || valor > max_valor) {
        puts(VALOR_INVALIDO);

        clean_input_buffer();

        printf(msg);
    }

    clean_input_buffer();

    return valor;
}

double obter_double(double min_valor, double max_valor, char *msg) {
    double valor;
    printf(msg);
    while (scanf(" %lf", &valor) != 1 || valor < min_valor || valor > max_valor) {
        puts(VALOR_INVALIDO);

        clean_input_buffer();

        printf(msg);
    }

    clean_input_buffer();

    return valor;
}

void ler_string(char *string, unsigned int tamanho, char *msg) {
    printf(msg);
    if (fgets(string, tamanho, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            clean_input_buffer();
        }
    }
}
