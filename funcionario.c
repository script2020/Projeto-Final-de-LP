/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>

#include "funcionario.h"
#include "input.h"
#include "time.h"

/**
 * Esta função cria uma data
 * 
 * @param data
 * @param dia
 * @param mes
 * @param ano
 */

void criar_Data(Data* data, int dia, int mes, int ano) {

    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

}

/**
 * Esta funçao indica o dia,mes,ano
 */
void tempo_hoje() {
    
    //armazena data e hora  
    struct tm *data_hora_atual;

    //armazenar o tempo em segundos 
    time_t segundos;

    //obtendo o tempo em segundos
    time(&segundos);

    //Converte os segundos para o tempo local
    data_hora_atual = localtime(&segundos);

    //Acessando dados convertidos para a struct data_hora_atual  
    printf("\nDia..........: %d\n", data_hora_atual->tm_mday);

    //para retornar o mês corretamente devemos adicionar +1 
    printf("\nMes..........: %d\n", data_hora_atual->tm_mon + 1);

    //para retornar o ano corretamente devemos adicionar 1900 
    printf("\nAno..........: %d\n\n", data_hora_atual->tm_year + 1900);

    printf("\nHora ........: %d:", data_hora_atual->tm_hour); //hora   
    printf("%d:", data_hora_atual->tm_min); //minuto
    printf("%d\n", data_hora_atual->tm_sec); //segundo  

    printf("\nData ........: %d/", data_hora_atual->tm_mday);
    printf("%d/", data_hora_atual->tm_mon + 1); //mês
    printf("%d\n\n", data_hora_atual->tm_year + 1900); //ano

}
void calcurar_tempo_empresa(Funcionario *funcionario){
    
    struct tm *data_hora_atual;
    int  year_today = data_hora_atual->tm_year + 1900;
    
    funcionario->tempo_empresa.dia = year_today - funcionario->data_entrada.ano;
    
}


/**
 * esta função cria um funcionáro
 * 
 * @param funcionario
 * 
 */
void criar_funcionario(Funcionario *funcionario) {
    funcionario->eliminado = false;
    ler_string(funcionario->nome, TAM_NOME, "Nome: ");
    funcionario->codigo = obter_int(0, MAX_NUM_FUNCIONARIO, "Código: ");
    funcionario->cargo = obter_char("Cargo: ");
    printf("\nData de entrada:\n");
    funcionario->data_entrada.dia = obter_int(MIN_DIA, MAX_DIA, "Dia: ");
    funcionario->data_entrada.mes = obter_int(MIN_MES, MAX_MES, "Mês: ");
    funcionario->data_entrada.ano = obter_int(MIN_ANO, MAX_ANO, "Ano: ");
    printf("\nData de nascimento:\n");
    funcionario->data_nascimento.dia = obter_int(MIN_DIA, MAX_DIA, "Dia: ");
    funcionario->data_nascimento.mes = obter_int(MIN_MES, MAX_MES, "Mês: ");
    funcionario->data_nascimento.ano = obter_int(MIN_ANO, MAX_ANO, "Ano: ");
    funcionario->estado_civil = obter_char("Estado civíl: "); 
    funcionario->numero_filhos = obter_int(MIN_FILHOS,MAX_FILHOS,"Número de filhos: ");
    funcionario->numero_telemovel = obter_int(MIN_TELEMOVEL,MAX_TELEMOVEL,"Número de telemóvel: ");    
    funcionario->subsidio_alimentacao = obter_float(MIN_SUB_ALIMENTACAO, MAX_SUB_ALIMENTACAO, "Subsídio de alimentação: ");
    funcionario ->vencimento_base = obter_float(MIN_VENC_BASE, MAX_VENC_BASE, "Vencimento Base: ");
}
/**
 * Esta função mostra um funcionário
 * 
 * @param funcionario
 */
void mostrar_funcionario(Funcionario *funcionario) {
    printf("Nome: %s\n", funcionario->nome);
    printf("Código: %d\n", funcionario->codigo);
    printf("Cargo: %d\n",funcionario->cargo);
    printf("Data de entrada:");
    printf("Dia: %d\n ",funcionario->data_entrada.dia);
    printf("Mês: %d\n ", funcionario->data_entrada.mes);
    printf("Ano: %d\n ", funcionario->data_entrada.ano);
    printf("Data de nascimento:\n");
    printf("Dia: %d\n ", funcionario->data_nascimento.dia);
    printf("Mês: %d\n ", funcionario->data_nascimento.mes);
    printf("Ano: %d\n ", funcionario->data_nascimento.ano);
    printf("Estato civíl: %c\n",funcionario->estado_civil);
    printf("Número de filhos: %d\n",funcionario->numero_filhos);
    printf("Número de telemóvel: %d\n",funcionario->numero_telemovel);
    printf("Subsídio de alimentação: %f\n",funcionario->subsidio_alimentacao);
    printf("Vencimento base: %f\n",funcionario->vencimento_base);
    printf("Tempo na empresa:\n");
    printf("Anos: %d", funcionario->tempo_empresa);
    
    
}

/**
 * Esta função remove um funcionário
 * 
 * @param funcionario
 */
void remover_funcionario(Funcionario *funcionario) {
    funcionario->eliminado = true;
}


/**
 * Esta função edita um funcionário
 * 
 * @param funcionario
 */
void editar_funcionario(Funcionario *funcionario) {
    int escolha;
    
    while (true) {
        printf("-----------------------\n");
        printf("0 - Sair\n");
        printf("1 - Nome\n");
        printf("2 - Codigo\n");
        printf("3 - Cargo\n");
        printf("Data de entrada\n");
        printf("4 - Dia\n");
        printf("5 - Mês\n");
        printf("6 - Ano\n");
        printf("Data de nascimento\n");
        printf("7 - Dia\n");
        printf("8 - Mês\n");
        printf("9 - Ano\n");
        printf("Data de saída\n");
        printf("10 - Dia\n");
        printf("11 - Mês\n");
        printf("12 - Ano\n");
        printf("13 - Estado civíl\n");
        printf("14 -Subsídito de alimentação\n");
        printf("15 - vencimento base\n");
        printf("-----------------------\n");
        escolha = obter_int(0, 15, "Escolha:");
        switch (escolha) {
            case 0:
                return;
            case 1:
                ler_string(funcionario->nome, TAM_NOME, "Nome: ");
                break;
            case 2:
                funcionario->codigo = obter_int(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO, "Código: ");
                break;
            case 3:
                funcionario->cargo = obter_char("Cargo:");
            case 4:
                funcionario->data_entrada.dia = obter_int(MIN_DIA, MAX_DIA, "Dia de entrada:");
                break;
            case 5:
                funcionario->data_entrada.mes = obter_int(MIN_MES, MAX_MES, "Mês de entrada:");
                break;
            case 6:
                funcionario->data_entrada.ano = obter_int(MIN_ANO, MAX_ANO, "Ano de entrada:");
            case 7:
                funcionario->data_nascimento.dia = obter_int(MIN_DIA, MAX_DIA, "Dia de nascimento:");
                break;
            case 8:
                funcionario->data_nascimento.mes = obter_int(MIN_MES, MAX_MES, "Mês de nascimento:");
                break;
            case 9:
                funcionario->data_nascimento.ano = obter_int(MIN_ANO, MAX_ANO, "Ano de nascimento:");
            case 10:
                funcionario->data_saida.dia = obter_int(MIN_DIA, MAX_DIA, "Dia de saida:");
                break;
            case 11:
                funcionario->data_saida.mes = obter_int(MIN_MES, MAX_MES, "Mês de saida:");
                break;
            case 12:
                funcionario->data_saida.ano = obter_int(MIN_ANO, MAX_ANO, "Ano de saida:");
                break;
            case 13:
                funcionario->estado_civil = obter_char("Estado cívil:");
                break;
            case 14:
                funcionario->subsidio_alimentacao = obter_float(MIN_SUB_ALIMENTACAO, MAX_SUB_ALIMENTACAO, "Subsídio de alimentação");
                break;
            case 15:
                funcionario ->vencimento_base = obter_float(MIN_VENC_BASE, MAX_VENC_BASE, "Vencimento Base:");
                break; 
}
    }
}

/**
 * Esta função indica se o funcionario foi removido
 * 
 * @param funcionario
 * @return 
 */
Bool esta_removido(Funcionario *funcionario) {

    return funcionario->eliminado;
}

/**
 * esta função procura o funcionario
 * 
 * @param codigo
 * @param file
 * @return 
 */
Funcionario procurar_funcionario(int codigo, FILE *file) {
    Funcionario funcionario_temp;
    Funcionario funcionario_nao_encontrado;
    funcionario_nao_encontrado.codigo = -1;
    int leitura;
    fseek(file, 0, SEEK_SET);
    while (1) {
        leitura = fread(&funcionario_temp, sizeof (Funcionario), 1, file);
        if (leitura == 0) {
            return funcionario_nao_encontrado;
        }
        if (funcionario_temp.codigo == codigo) {
            return funcionario_temp;
        }
    }
}

