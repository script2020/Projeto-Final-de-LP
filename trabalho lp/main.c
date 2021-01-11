/* 
 * File:   main.c
 * Author: joana
 *
 * Created on 6 de janeiro de 2021, 22:57
 */

#include <stdio.h>
#include <stdlib.h>
#define salarioBaseEmpregado 40
#define salarioBaseChefe 60
#define salarioBaseAdministrador 80
#define subsidioAlimentacaoEmpregado 5
#define subsidioAlimentacaoChefeAdminstrador 7.5
#define taxaIRS1 0.1
#define taxaIRS2 0.2
#define taxaIRS3 0.3
#define segurancaSocialAdminstradorFuncionario 0.09
#define segurancaSocialAdminstradorEmpresa 0.21
#define segurancaSocialOutrosFuncionario 0.11
#define segurancaSocialOutrosEmpresa 0.2375
#define bonusmais20dias 0.05
#define bonusmais17dias 0.02
#define bonusmenos17dias 0


int main() {
    char cargo,opcao1;
    float bonus,salarioBruto,subsidioAlimentacao,irs,segurancaSocialFuncionario,segurancaSocialPatrao,valorLiquido,EncargoTotal,ValorBonus;
    int codigo,dias,erro=0;
    
    while(opcao1!='n'){
      printf("insira o código: ");
      scanf("%d",&codigo);
      
      printf("pretende continuar o calculo do vencimento: ");
      scanf(" %c",&opcao1);
      
      if(opcao1=='N' || opcao1=='n'){
          break;
      }
      
      puts("Cargo:");
      puts("º-------------------------º");
      puts("|     C-Chefe             |");
      puts("|     E-Empregado         |");
      puts("|     A-Administrador     |");
      puts("º-------------------------º");
      printf("insira opção: ");
      scanf(" %c",&cargo);
      
      printf("pretende continuar o calculo do vencimento: ");
      scanf(" %c",&opcao1);
     
      if(opcao1=='N' || opcao1=='n'){
          break;
      }

      printf("insira o número de dias que trabalhou: ");
      scanf("%d",&dias);
      
      printf("pretende continuar o calculo do vencimento: ");
      scanf(" %c",&opcao1);
      
      if(opcao1=='N' || opcao1=='n'){
          break;
      }

      if(dias<1 || dias>31){
        puts("o num está errado! introduza novamente!");
        printf("insira o número de dias que trabalhou: ");
        scanf("%d",&dias);
      }
             
       if(dias>20) {
           bonus= bonusmais20dias;
           
       } else if (dias>17){
           bonus= bonusmais17dias;
       }else{
           bonus=bonusmenos17dias;
       }
    
    while(erro!=1){
        switch(cargo){
            case 'E':
            case 'e': printf("Empregado\n");
                      salarioBruto = salarioBaseEmpregado*dias;
                      subsidioAlimentacao = subsidioAlimentacaoEmpregado*dias;
                      segurancaSocialFuncionario = segurancaSocialOutrosFuncionario*salarioBruto;
                      segurancaSocialPatrao = segurancaSocialOutrosEmpresa*salarioBruto;
                      ValorBonus= salarioBruto*bonus;
                      erro=1;
                      break;
            case 'C':
            case 'c': printf("Chefe\n");
                      salarioBruto = salarioBaseChefe*dias;
                      subsidioAlimentacao = subsidioAlimentacaoChefeAdminstrador*dias;
                      segurancaSocialFuncionario = segurancaSocialOutrosFuncionario*salarioBruto;
                      segurancaSocialPatrao = segurancaSocialOutrosEmpresa*salarioBruto;
                      ValorBonus= salarioBruto*bonus;
                      erro=1;
                      break;
            case 'A':
            case 'a': printf("Administrador\n");
                      salarioBruto = salarioBaseAdministrador*dias;
                      subsidioAlimentacao = subsidioAlimentacaoChefeAdminstrador*dias;
                      segurancaSocialFuncionario = segurancaSocialAdminstradorFuncionario*salarioBruto;
                      segurancaSocialPatrao = segurancaSocialAdminstradorEmpresa*salarioBruto;
                      ValorBonus= salarioBruto*bonus;
                      erro=1;
                      break;
            default:
                printf("cargo inválido!\tSelecione uma opção válida!\t(A,E ou C)\n");
                scanf(" %c",&cargo);
                erro=0;
        }
    }
            
    if(salarioBruto < 1000){
        irs=taxaIRS1*salarioBruto;
    }else if(salarioBruto>=1000 && salarioBruto<2500){
        irs=taxaIRS2*salarioBruto;
    }else{
        irs=taxaIRS3*salarioBruto;
    }
    
    valorLiquido=(salarioBruto+subsidioAlimentacao+ValorBonus)-(irs+segurancaSocialFuncionario);
    EncargoTotal=salarioBruto+irs+segurancaSocialPatrao+subsidioAlimentacao+ValorBonus;
    
    printf("O seu vencimento base é: %.2f€\n",salarioBruto);
    printf("O seu subsidio de alimentação é: %.2f€\n",subsidioAlimentacao);
    printf("Para IRS foram retidos: %.2f€\n",irs);
    printf("valor total a entregar à Segurança Socia: %.2f\n",segurancaSocialFuncionario+segurancaSocialPatrao);
    printf("valor líquido a receber pelo funcionário: %.2f\n",valorLiquido);
    printf("Encargo total com salários, subsídios e impostos que a empresa terá: %.2f\n)",EncargoTotal);
    
    printf("Deseja fazer o cálculo de outro funcionario?: \n");
    scanf(" %c",&opcao1);
        
    }
    printf("Obrigado por ter usado o nosso programa");
             
    return(0);
    
}
