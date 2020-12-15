/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>

#include "funcionario.h"
#include "input.h"

int procurarFuncionario(Funcionarios funcionarios, int codigo) {

    for (int i = 0; i < funcionarios.registo; i++) {
        if (funcionarios.funcionarios[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

//devemos defenir as mensagens como constantes?tipo #define MSG_NUM_FUNCIONARIO "\nNúmero de funcionário:\n" ???

int criarFuncionario(Funcionarios *funcionarios) { //esta a dar erro e nao sei pq help

    int codigo;
    if (procurarFuncionario(*funcionarios, codigo) == -1) {

        lerString(funcionarios->funcionarios[funcionarios->registo].nome, TAM_NOME, "\nNome do funcionário:\n");
        funcionarios->funcionarios[funcionarios->registo].codigo =
                obterInt(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO, "\nCódigo de funcionário:\n");
        funcionarios->funcionarios[funcionarios->registo].cargo =
                obterChar("\nCargo de funcionário:\n");
        funcionarios->funcionarios[funcionarios->registo].numero_telemovel =
                obterInt(MIN_TELEMOVEL, MAX_TELEMOVEL, "\nNnúmero de telemóvel do funcionário:\n");
        funcionarios->funcionarios[funcionarios->registo].numero_filhos =
                obterInt(MIN_FILHOS, MAX_FILHOS, "\nNúmero de filhos:\n");
        funcionarios->funcionarios[funcionarios->registo].estado_civil =
                obterChar("\nEstado civil:\n"); //falta por S ou s - Solteiro/a. etc...
        funcionarios->funcionarios[funcionarios->registo].data_nascimento.dia =
                obterInt(MIN_DIA, MAX_DIA, "\nDia de nascimento:\n");
        funcionarios->funcionarios[funcionarios->registo].data_nascimento.mes =
                obterInt(MIN_MES, MAX_MES, "\nMês de nascimento:\n");
        funcionarios->funcionarios[funcionarios->registo].data_nascimento.ano =
                obterInt(MIN_ANO, MAX_ANO, "\nAno de nascimento:\n");
        funcionarios->funcionarios[funcionarios->registo].vencimento_base =
                obterFloat(MIN_VENC_BASE, MAX_VENC_BASE, "\nVencimento base(valor/hora):\n");
        funcionarios->funcionarios[funcionarios->registo].subsidio_alimentacao =
                obterFloat(MIN_SUB_ALIMENTACAO, MAX_SUB_ALIMENTACAO, "\nSubsídio de alimentação:\n");
        funcionarios->funcionarios[funcionarios->registo].data_entrada.dia =
                obterInt(MIN_DIA, MAX_DIA, "\nDia de entrada:\n");
        funcionarios->funcionarios[funcionarios->registo].data_entrada.mes =
                obterInt(MIN_MES, MAX_MES, "\nMês de entrada:\n");
        funcionarios->funcionarios[funcionarios->registo].data_entrada.ano =
                obterInt(MIN_ANO, MAX_ANO, "\nAno de entrada\n");
        funcionarios->funcionarios[funcionarios->registo].data_saida.dia = //ele pode no ter saido 
                obterInt(MIN_DIA, MAX_DIA, "\nDia de saida:\n");
        funcionarios->funcionarios[funcionarios->registo].data_saida.mes =
                obterInt(MIN_MES, MAX_MES, "\nMês de saida:\n");
        funcionarios->funcionarios[funcionarios->registo].data_saida.ano =
                obterInt(MIN_ANO, MAX_ANO, "\nAno de saida\n");
        //fazer as perguntas melhor no tempo de esmpresa
        funcionarios->funcionarios[funcionarios->registo].tempo_empresa.ano =
                obterInt(MIN_ANOS_TRABALHO, MAX_ANOS_TRABALHO, "\nAnos de trabalho na esmpresa:\n");
        funcionarios->funcionarios[funcionarios->registo].tempo_empresa.mes =
                obterInt(MIN_MES, MAX_MES, "\nMeses de trabalho na esmpresa:\n");
        funcionarios->funcionarios[funcionarios->registo].tempo_empresa.dia =
                obterInt(MIN_DIA, MAX_DIA, "\nDias de trabalho na esmpresa:\n");

        return funcionarios->registo++;
    }
    
