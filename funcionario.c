/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>

#include "funcionario.h"
#include "input.h"
#include "time.h"
#include "irs.h"

//bugs que detetei -> o dia e o mes de entrada (em mostrar_funcionario)aparece sempre 0,consequentemente o tempo de empresa dá mal

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
 * Esta função indica da data de hoje
 */
void time_now() {
    time_t t = time(NULL);
    struct tm data_atual = *localtime(&t);

    printf("Data de hoje: %.2d-%.2d-%d\n", data_atual.tm_mday, data_atual.tm_mon + 1, data_atual.tm_year + 1900);

}

/**
 * Esta função calcula o tempo na empresa do funcionario
 * 
 * @param funcionario
 * 
 */
void calcurar_tempo_empresa(Funcionario *funcionario) {
    int x;
    time_t t = time(NULL);
    struct tm data_atual = *localtime(&t);

    if (funcionario->data_entrada.mes > funcionario->data_atual.tm_mon) {
        funcionario->data_entrada.mes = funcionario->data_entrada_temp.mes;
        funcionario->data_atual.tm_mon + 1 = funcionario->data_atual_temp.tm_mon + 1;

        x = funcionario->data_entrada_temp.mes;
        funcionario->data_entrada_temp.mes = funcionario->data_atual_temp.tm_mon;
        funcionario->data_atual_temp.tm_mon = x;

        funcionario->tempo_empresa.ano = funcionario->data_atual_temp.tm_year + 1900 - funcionario->data_entrada.ano;
        funcionario->tempo_empresa.mes = funcionario->data_atual_temp.tm_mon + 1 - funcionario->data_entrada.mes;
        funcionario->tempo_empresa.dia = funcionario->data_atual_temp.tm_mday - funcionario->data_entrada.dia;

    }
    if (funcionario->data_entrada.dia > funcionario->data_saida.dia) {
        funcionario->data_entrada.dia = funcionario->data_entrada_temp.dia;
        funcionario->data_saida.dia = funcionario->data_saida_temp.dia;

        x = funcionario->data_entrada_temp.dia;
        funcionario->data_entrada_temp.dia = funcionario->data_atual_temp.tm_mday;
        funcionario->data_atual_temp.tm_mday = x;

        funcionario->tempo_empresa.ano = funcionario->data_atual_temp.tm_year + 1900 - funcionario->data_entrada.ano;
        funcionario->tempo_empresa.mes = funcionario->data_atual_temp.tm_mon + 1 - funcionario->data_entrada.mes;
        funcionario->tempo_empresa.dia = funcionario->data_atual_temp.tm_mday - funcionario->data_entrada.dia;
    }
    funcionario->tempo_empresa.ano = funcionario->data_atual.tm_year + 1900 - funcionario->data_entrada.ano;
    funcionario->tempo_empresa.mes = funcionario->data_atual.tm_mon + 1 - funcionario->data_entrada.mes;
    funcionario->tempo_empresa.dia = funcionario->data_atual.tm_mday - funcionario->data_entrada.dia;
    
    printf("Anos empresa: %d\n", funcionario->tempo_empresa.ano);
    printf("Meses empresa: %d\n", funcionario->tempo_empresa.mes);
    printf("Dias empresa: %d\n", funcionario->tempo_empresa.dia);

}

/**
 * Esta função cria um funcionáro
 * 
 * @param funcionario
 * 
 */
void criar_funcionario(Funcionario *funcionario, Funcionario *lista_funcionarios, int tam_lista, FILE *file) {

    int opcao_cargo, opcao_estado_civil, x, opcao = 0;

/*
    funcionario->eliminado = false;
*/
/*
    printf("Guardar em memoria ou em ficheiro?\n");
    printf("0 - Memória\n");
    printf("1 - Ficheiro\n");
    opcao = obter_int(0, 1, "Escolha: ");
*/

    funcionario->codigo = obter_int(MIN_NUM_FUNCIONARIO, MAX_NUM_FUNCIONARIO, "Código: ");
    ler_string(funcionario->nome, TAM_NOME, "Nome: ");
    printf("----------------------------------\n");
    printf("OPÇÕES DE CARGO:\n");
    printf("0 - Empregado(a) de limpeza\n");
    printf("1 - Costureiro/(a)\n");
    printf("2 - Modelista\n");
    printf("3 - Empregado(a) de escritório\n");
    printf("4 - Encarregado(a) de linha\n");
    printf("5 - Sócio(a) gerente\n");
    printf("----------------------------------\n");
    opcao_cargo = obter_int(0, 5, "Cargo: ");
    switch (opcao_cargo) {
        case 0:
            funcionario->cargo = empregada_limpeza;
            break;
        case 1:
            funcionario->cargo = costureira;
            break;
        case 2:
            funcionario->cargo = modelista;
            break;
        case 3:
            funcionario->cargo = empregada_escritorio;
            break;
        case 4:
            funcionario->cargo = encarregada_linha;
            break;
        case 5:
            funcionario->cargo = socio_gerente;
            break;
        default:
            printf("Opção inválida.");

    }
    printf("Data de entrada\n");
    funcionario->data_entrada.dia = obter_int(MIN_DIA, MAX_DIA, "Dia: ");
    funcionario->data_entrada.mes = obter_int(MIN_MES, MAX_MES, "Mês: ");
    funcionario->data_entrada.ano = obter_int(MIN_ANO, MAX_ANO, "Ano: ");
    printf("O funcionario saiu da empresa?\n");
    printf("0 - Não\n");
    printf("1 - Sim\n");
    funcionario->saida = obter_int(0, 1, "Escolha: ");
    if (funcionario->saida == 1) {
        printf("Data de saída\n");
        funcionario->data_saida.dia = obter_int(MIN_DIA, MAX_DIA, "Dia: ");
        funcionario->data_saida.mes = obter_int(MIN_MES, MAX_MES, "Mês: ");
        funcionario->data_saida.ano = obter_int(MIN_ANO, MAX_ANO, "Ano: ");
        printf("Tempo na empresa\n");
        if (funcionario->data_entrada.mes > funcionario->data_saida.mes) {
            funcionario->data_entrada.mes = funcionario->data_entrada_temp.mes;
            funcionario->data_saida.mes = funcionario->data_saida_temp.mes;

            x = funcionario->data_entrada_temp.mes;
            funcionario->data_entrada_temp.mes = funcionario->data_saida_temp.mes;
            funcionario->data_saida_temp.mes = x;

            funcionario->tempo_empresa.ano = funcionario->data_saida.ano - funcionario->data_entrada.ano;
            funcionario->tempo_empresa.mes = funcionario->data_saida.mes - funcionario->data_entrada.mes;
            funcionario->tempo_empresa.dia = funcionario->data_saida.dia - funcionario->data_entrada.dia;

        }
        if (funcionario->data_entrada.dia > funcionario->data_saida.dia) {
            funcionario->data_entrada.dia = funcionario->data_entrada_temp.dia;
            funcionario->data_saida.dia = funcionario->data_saida_temp.dia;

            x = funcionario->data_entrada_temp.dia;
            funcionario->data_entrada_temp.dia = funcionario->data_saida_temp.dia;
            funcionario->data_saida_temp.dia = x;

            funcionario->tempo_empresa.ano = funcionario->data_saida.ano - funcionario->data_entrada.ano;
            funcionario->tempo_empresa.mes = funcionario->data_saida.mes - funcionario->data_entrada.mes;
            funcionario->tempo_empresa.dia = funcionario->data_saida.dia - funcionario->data_entrada.dia;
        }

        printf("Anos: %d\n", funcionario->tempo_empresa.ano);
        printf("Meses: %d\n", funcionario->tempo_empresa.mes);
        printf("Dias: %d\n", funcionario->tempo_empresa.dia);
    }
    time_now();
    calcurar_tempo_empresa(funcionario);
    printf("\nData de nascimento\n");
    funcionario->data_nascimento.dia = obter_int(MIN_DIA, MAX_DIA, "Dia: ");
    funcionario->data_nascimento.mes = obter_int(MIN_MES, MAX_MES, "Mês: ");
    funcionario->data_nascimento.ano = obter_int(MIN_ANO, MAX_ANO, "Ano: ");
    printf("----------------------------\n");
    printf("OPÇÕES DE ESTADO CIVÍL:\n");
    printf("0 - Solteiro(a)\n");
    printf("1 - Casado(a)\n");
    printf("2 - Divoiciado(a)\n");
    printf("3 - Viúvo(a)\n");
    printf("4 - Separado(a)\n");
    printf("----------------------------\n");
    opcao_estado_civil = obter_int(0, 4, "Estado civíl: ");
    switch (opcao_estado_civil) {
        case 0:
            funcionario->estado_civil = solteiro;
            break;
        case 1:
            funcionario->estado_civil = casado;
            break;
        case 2:
            funcionario->estado_civil = divorciado;
            break;
        case 3:
            funcionario->estado_civil = viuvo;
            break;
        case 4:
            funcionario->estado_civil = separado;
            break;
        default:
            printf("Opção inválida.");

    }
    funcionario->numero_filhos = obter_int(MIN_FILHOS, MAX_FILHOS, "Número de filhos: ");
    printf("Indicativo do número de telemóvel(Portugal -> +351)\n");
    funcionario->indicativo_numero_telemovel = obter_int(MIN_PREFIXO, MAX_PREFIXO, "Indicativo: ");
    funcionario->numero_telemovel = obter_int(MIN_TELEMOVEL, MAX_TELEMOVEL, "Número de telemóvel: ");

    switch (funcionario->cargo) {
        case 0:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_EMP_LIMP);
            break;
        case 1:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_COST);
            break;
        case 2:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_MOD);
            break;
        case 3:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_EMP_ESC);
            break;
        case 4:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_ENC_LINHA);
            break;
        case 5:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_SOC_GER);
            break;
        default:
            printf("Opção inválida.\n");

    }
    funcionario->subsidio_alimentacao = printf("Subsídio de alimentação: %.2f€\n", SUB_ALIMENTACAO);

/*
    if (opcao == 0) {//guardar em memoria
        tam_laista += 1;

        lista_funcionarios = (Funcionario*) realloc(lista_funcionarios, tam_lista * sizeof (Funcionario)); //guardar mais espaço
        lista_funcionarios[tam_lista - 1] = *funcionario;
    } else {
        fseek(file, 0, SEEK_END); //escreve no fim do ficheiro
        fwrite(funcionario, sizeof (Funcionario), 1, file);

    }
*/

}

/**
 * Esta função mostra um funcionário
 * 
 * @param funcionario
 */
void mostrar_funcionario(Funcionario *funcionario) {
    int x;

    printf("Nome: %s\n", funcionario->nome);
    printf("Código: %d\n", funcionario->codigo);
    if (funcionario->cargo == 0) {
        printf("Cargo: Empregado(a) de limpeza\n");
    }
    if (funcionario->cargo == 1) {
        printf("Cargo: Costureiro/(a)\n");
    }
    if (funcionario->cargo == 2) {
        printf("Cargo: Modelista\n");
    }
    if (funcionario->cargo == 3) {
        printf("Cargo: Empregado(a) de escritório\n");
    }
    if (funcionario->cargo == 4) {
        printf("Cargo: Encarregado(a) de linha\n");
    }
    if (funcionario->cargo == 5) {
        printf("Cargo: Sócio(a) gerente\n");
    }
    if (funcionario->saida == 1) {
        printf("Data de saída\n");
        printf("Dia: %d\n", funcionario->data_saida.dia);
        printf("Mês: %d\n", funcionario->data_saida.mes);
        printf("Ano: %d\n", funcionario->data_saida.ano);
        printf("Tempo na empresa\n");
        if (funcionario->data_entrada.mes > funcionario->data_saida.mes) {
            funcionario->data_entrada.mes = funcionario->data_entrada_temp.mes;
            funcionario->data_saida.mes = funcionario->data_saida_temp.mes;

            x = funcionario->data_entrada_temp.mes;
            funcionario->data_entrada_temp.mes = funcionario->data_saida_temp.mes;
            funcionario->data_saida_temp.mes = x;

            funcionario->tempo_empresa.ano = funcionario->data_saida.ano - funcionario->data_entrada.ano;
            funcionario->tempo_empresa.mes = funcionario->data_saida.mes - funcionario->data_entrada.mes;
            funcionario->tempo_empresa.dia = funcionario->data_saida.dia - funcionario->data_entrada.dia;

        }
        if (funcionario->data_entrada.dia > funcionario->data_saida.dia) {
            funcionario->data_entrada.dia = funcionario->data_entrada_temp.dia;
            funcionario->data_saida.dia = funcionario->data_saida_temp.dia;

            x = funcionario->data_entrada_temp.dia;
            funcionario->data_entrada_temp.dia = funcionario->data_saida_temp.dia;
            funcionario->data_saida_temp.dia = x;

            funcionario->tempo_empresa.ano = funcionario->data_saida.ano - funcionario->data_entrada.ano;
            funcionario->tempo_empresa.mes = funcionario->data_saida.mes - funcionario->data_entrada.mes;
            funcionario->tempo_empresa.dia = funcionario->data_saida.dia - funcionario->data_entrada.dia;
        }
    }
    printf("Data de entrada\n");
    printf("Dia: %d\n", funcionario->data_entrada.dia);
    printf("Mês: %d\n", funcionario->data_entrada.mes);
    printf("Ano: %d\n", funcionario->data_entrada.ano);
    if (funcionario->data_entrada.mes > funcionario->data_saida.mes) {
        funcionario->data_entrada.mes = funcionario->data_entrada_temp.mes;
        funcionario->data_saida.mes = funcionario->data_saida_temp.mes;

        x = funcionario->data_entrada_temp.mes;
        funcionario->data_entrada_temp.mes = funcionario->data_saida_temp.mes;
        funcionario->data_saida_temp.mes = x;

        funcionario->tempo_empresa.ano = funcionario->data_saida.ano - funcionario->data_entrada.ano;
        funcionario->tempo_empresa.mes = funcionario->data_saida.mes - funcionario->data_entrada.mes;
        funcionario->tempo_empresa.dia = funcionario->data_saida.dia - funcionario->data_entrada.dia;

    }
    if (funcionario->data_entrada.dia > funcionario->data_saida.dia) {
        funcionario->data_entrada.dia = funcionario->data_entrada_temp.dia;
        funcionario->data_saida.dia = funcionario->data_saida_temp.dia;

        x = funcionario->data_entrada_temp.dia;
        funcionario->data_entrada_temp.dia = funcionario->data_saida_temp.dia;
        funcionario->data_saida_temp.dia = x;

        funcionario->tempo_empresa.ano = funcionario->data_saida.ano - funcionario->data_entrada.ano;
        funcionario->tempo_empresa.mes = funcionario->data_saida.mes - funcionario->data_entrada.mes;
        funcionario->tempo_empresa.dia = funcionario->data_saida.dia - funcionario->data_entrada.dia;
    }

    printf("Tempo na empresa\n");
    printf("Anos: %d\n", funcionario->tempo_empresa.ano);
    printf("Meses: %d\n", funcionario->tempo_empresa.mes);
    printf("Dias: %d\n", funcionario->tempo_empresa.dia);
    printf("Data de nascimento\n");
    printf("Dia: %d\n", funcionario->data_nascimento.dia);
    printf("Mês: %d\n", funcionario->data_nascimento.mes);
    printf("Ano: %d\n", funcionario->data_nascimento.ano);
    if (funcionario->estado_civil == 0) {
        printf("Estado civíl: Solteiro(a)\n");
    }
    if (funcionario->estado_civil == 1) {
        printf("Estado civíl: Casado(a)\n");
    }
    if (funcionario->estado_civil == 2) {
        printf("Estado civíl: Divoiciado(a)\n");
    }
    if (funcionario->estado_civil == 3) {
        printf("Estado civíl: Viúvo(a)\n");
    }
    if (funcionario->estado_civil == 4) {
        printf("Estado civíl: Separado(a)\n");
    }
    printf("Número de filhos: %d\n", funcionario->numero_filhos);
    printf("Indicativo numero de telemovel: %d\n", funcionario->indicativo_numero_telemovel);
    printf("Número de telemóvel: %d\n", funcionario->numero_telemovel);
    printf("Subsídio de alimentação: %.2f\n", funcionario->subsidio_alimentacao);

    switch (funcionario->cargo) {
        case 0:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_EMP_LIMP);
            break;
        case 1:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_COST);
            break;
        case 2:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_MOD);
            break;
        case 3:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_EMP_ESC);
            break;
        case 4:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_ENC_LINHA);
            break;
        case 5:
            printf("Vencimento Base: %.2f€\n", VENC_BASE_SOC_GER);
            break;
        default:
            printf("Opção inválida.\n");

    }



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
    int escolha, opcao_cargo;

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
        printf("14 - Indicativo número de telemóvel\n");
        printf("15 - Número de telemóvel\n");
        printf("16 -Subsídito de alimentação\n");
        printf("17 - vencimento base\n");
        printf("-----------------------\n");
        escolha = obter_int(0, 18, "Escolha: ");
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
                printf("----------------------------------\n");
                printf("OPÇÕES DE CARGO:\n");
                printf("0 - Empregado(a) de limpeza\n");
                printf("1 - Costureiro/(a)\n");
                printf("2 - Modelista\n");
                printf("3 - Empregado(a) de escritório\n");
                printf("4 - Encarregado(a) de linha\n");
                printf("5 - Sócio(a) gerente\n");
                printf("----------------------------------\n");
                opcao_cargo = obter_int(0, 6, "Cargo: ");
                switch (opcao_cargo) {
                    case 0:
                        funcionario->cargo = empregada_limpeza;
                        break;
                    case 1:
                        funcionario->cargo = costureira;
                        break;
                    case 2:
                        funcionario->cargo = modelista;
                        break;
                    case 3:
                        funcionario->cargo = empregada_escritorio;
                        break;
                    case 4:
                        funcionario->cargo = encarregada_linha;
                        break;
                    case 5:
                        funcionario->cargo = socio_gerente;
                        break;
                    default:
                        printf("Opção inválida.");

                }
                break;
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
                printf("----------------------------\n");
                printf("OPÇÕES DE ESTADO CIVÍL:\n");
                printf("0 - Solteiro(a)\n");
                printf("1 - Casado(a)\n");
                printf("2 - Divoiciado(a)\n");
                printf("3 - Viúvo(a)\n");
                printf("4 - Separado(a)\n");
                printf("----------------------------\n");
                funcionario->estado_civil = obter_int(MIN_ESTADO_CIVIL, MAX_ESTADO_CIVIL, "Estado civíl: ");
                break;
            case 14:
                funcionario->indicativo_numero_telemovel = obter_int(MIN_PREFIXO, MAX_PREFIXO, "Indicativo número de telemóvel:");
                break;
            case 15:
                funcionario->numero_telemovel = obter_int(MIN_TELEMOVEL, MAX_TELEMOVEL, "Número de telemóvel: ");
                break;
            case 16:
                funcionario->subsidio_alimentacao = printf("Subsídio de alimentação: %.2f\n", SUB_ALIMENTACAO);
                break;
            case 17:
                switch (funcionario->cargo) {
                    case 0:
                        printf("Vencimento Base: %.2f€\n", VENC_BASE_EMP_LIMP);
                        break;
                    case 1:
                        printf("Vencimento Base: %.2f€\n", VENC_BASE_COST);
                        break;
                    case 2:
                        printf("Vencimento Base: %.2f€\n", VENC_BASE_MOD);
                        break;
                    case 3:
                        printf("Vencimento Base: %.2f€\n", VENC_BASE_EMP_ESC);
                        break;
                    case 4:
                        printf("Vencimento Base: %.2f€\n", VENC_BASE_ENC_LINHA);
                        break;
                    case 5:
                        printf("Vencimento Base: %.2f€\n", VENC_BASE_SOC_GER);
                        break;
                    default:
                        printf("Opção inválida.\n");

                }
                break;
            default:
                printf("Opção inválida.\n");

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
Funcionario procurar_funcionario(int codigo, Funcionario *lista_funcionarios, int tam_lista, FILE *file) {
    Funcionario funcionario_temp;
    Funcionario funcionario_nao_encontrado;
    funcionario_nao_encontrado.codigo = -1;
    int leitura;

    fseek(file, 0, SEEK_SET);
    while (1) {
        leitura = fread(&funcionario_temp, sizeof (Funcionario), 1, file);
        if (leitura == 0) {
            break;
        }
        if (funcionario_temp.codigo == codigo) {
            return funcionario_temp;
        }
    }
    for (int i = 0; i < tam_lista; i++) {
        if (lista_funcionarios[i].codigo == codigo) {
            return lista_funcionarios[i];
        }
    }
    return funcionario_nao_encontrado;
}


