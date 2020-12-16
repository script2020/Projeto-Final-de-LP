/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>

#include "funcionario.h"
#include "input.h"

#define FILENAME "funcionarios.txt"

FILE *funcionario = fopen(FILENAME, "w"); //NAO SEI SE É ASSIM QUE SE FAZZZZZ HELPPPPPPPP
if (funcionario == NULL) {
exit(EXIT_FAILURE);
}
fprintf(funcionario, criarFuncionario(Funcionarios *funcionarios));



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
       //falta fazer as contas para o tempo que ele trabalha na esmpresa
        return funcionarios->registo++;
        
    }
    
    void editarFuncionario(Funcionario *funcionario) {
lerString(funcionario->nome,TAM_NOME,"\nNome do funcionário:\n" );
funcionario->data_nascimento.dia = obterInt(MIN_DIA, MAX_DIA, "\nDia de nascimento:\n");
funcionario->data_nascimento.mes = obterInt(MIN_MES, MAX_MES, "\nMês de nascimento:\n");
funcionario->data_nascimento.ano = obterInt(MIN_ANO, MAX_ANO, "\nAno de nascimento:\n");
}
  void apagarDadosFuncionario(Funcionario *funcionario) {
funcionario->codigo = 0;
strcpy(funcionario->nome, "");
funcionario->data_nascimento.dia =funcionario->data_nascimento.mes = funcionario->data_nascimento.ano = 0;
}
    
void removerFuncionario(Funcionarios *funcionarios){
    
   int codigo = procurarFuncionario(*funcionarios, obterInt(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO, "\nCódigo de funcionário:\n");
if (codigo != -1) {
   for (int i = codigo; i < funcionarios->registo - 1; i++) {
ufuncionarios->funcionarios[i] = funcionarios->funcionarios[i + 1]; //passar o funcionario que estava "acima" do que foi apagado  para o lugar do apagado
}
apagarDadosFuncionario(&funcionarios->funcionarios[i]);
funcionarios->registo--;
} else {
  printf("O funcionário não esxiste na lista!");
}
}
 
    
}
    fclose(funcionarios);
