#include <stdio.h>

void lerfuncionarios (char *funcao, int *anos, int *horascontratadas, int *horasdetrabalho ){  
    
    while(1) {

        printf("- Função: ");
        scanf("%c", &*funcao);
        
    if (*funcao != 'a' && *funcao != 'A' && *funcao != 'p' && *funcao != 'P' && *funcao != 'g' && *funcao != 'G')

        printf("Funções inexistentes. Selecione apenas entre A/a (analista), P/p (progamador), G/g (gerente). \n");
    else 
    
        break;
    }
        
 
    
    
    
    do
    {
        printf ("- Anos de experiência:\n");
        scanf("%d", &*anos);
        
      if (*anos < 0 )
        {
            printf("Erro, os anos de experiência devem ser maior ou igual a zero\n");
        }

    } while(*anos < 0);

    do 
    {
        printf ("- Horas contratadas:\n");
        scanf("%d", &horascontratadas);
        
     if (*horascontratadas < 0)
        {
            printf("Atenção, as horas contratadas devem ser maior que 0.\n");
        }

    }while(*horascontratadas < 0);
  
    do
    {
        printf ("- Horas de trabalho: \n");
        scanf("%d", &*horasdetrabalho);
        if(*horasdetrabalho < 0)
        {
            printf("Atenção, As horas de trabalho devem sem maior ou igual a zero.\n");
        }

    }while(*horasdetrabalho < 0);
}
 
 float calcularsalario (char funcao, int anos, int horascontratadas, int horasdetrabalho, float *descontoINSS, float *descontoImp, float *salariobruto, int *horaextra )
 {  float valorhora, salarioliquido, porcentImp, porcent;
    porcent = 0;
    porcentImp = 0;
    horaextra = 0;
    if(horasdetrabalho > horascontratadas)
    {
        if (*horaextra <= 13)
        {
            porcent=0.23;
        
        }else if (*horaextra >= 13 && *horaextra <= 22)
        {
            porcent=0.37;
        
        }else if (*horaextra > 22)
        {
            porcent=0.56;
        }

           
    }
  
    if (anos <= 2){
        if(funcao == 'p' || funcao == 'P')
    {
        valorhora = 25; 
    }
    else if (funcao == 'a' || funcao == 'A')
    {
        valorhora = 45;
    }else if (funcao == 'g'|| funcao == 'G')
    {
        valorhora = 85;
    }
    }else if (anos >= 3 && anos <= 5 ){
        if (funcao == 'p'|| funcao == 'P') 
        {
            valorhora = 30;
        }else if (funcao == 'a'|| funcao == 'A')
        {
            valorhora = 55;
        }else if (funcao == 'g'|| funcao == 'G')
        {
            valorhora = 102;
        }
      }else if (anos > 5)
      {      
        if (funcao == 'p' || funcao == 'P')
        {
            valorhora = 38;
        }else if(funcao == 'a'||funcao == 'A')
        {
            valorhora = 70;
        }else if (funcao == 'g' || funcao == 'G')
        {
            valorhora = 130;
        }
    }
    
     
     if (*salariobruto > 1500 && *salariobruto <= 2700)
     {
        porcentImp = 0.15;
     }else if (*salariobruto > 2700 && *salariobruto <= 4200)
     {
        porcentImp = 0.20;
     }else if (*salariobruto > 4200)
     {
        porcentImp = 0.30;
     }

*salariobruto = valorhora * horasdetrabalho;
*salariobruto = *salariobruto + *horaextra * valorhora * porcent;
*horaextra = (horasdetrabalho - horascontratadas);  
salarioliquido = *salariobruto - *descontoINSS - *descontoImp;
*descontoImp = (*salariobruto - *descontoINSS) * porcentImp;
*descontoINSS = *salariobruto * 0.11;

return salarioliquido;
 }
void imprimirfolhadepagamento (float salariobruto, int horaextra, float descontoINSS, float descontoImp, float salarioliquido){
        printf ("salario bruto(R$):%2.f \n", salariobruto);
    do
    {
        printf("horas excedentes(h):%f\n", horaextra);
    } while (horaextra > 0);
    
        printf("Dessconto INSS(R$):%.2f\n", descontoINSS);
        printf("Desconto IR(R$):%.2f\n",descontoINSS);
        printf("salário líquido(R$):%.2f\n", salarioliquido);


}


int main ()
{   char funcaofuncionario;
    float descontoINSS, descontoImp, salariobruto, salarioliquido;
    int numfuncionarios, anosexperiencia, horascontratadasmes, horasdetrabalhoMes, horaextra, i;
        numfuncionarios = 0;
        
        do
        {
            printf("Quantidade: ");
            scanf("%d", &numfuncionarios);
            
            if(numfuncionarios <= 0)
            {
                printf("ATENÇÃO: a quantidade de funcionários deve ser maior que zero. Informe novamente.\n");
            }

        } while(numfuncionarios <= 0);
        
        for (i = 1; i <= numfuncionarios; i++)
        {   
            printf("============================================================\n");
            printf("Funcionário %d\n", i);
            
            lerfuncionarios (&funcaofuncionario, &anosexperiencia, &horascontratadasmes, &horasdetrabalhoMes);
            salarioliquido = calcularsalario (funcaofuncionario, anosexperiencia, horascontratadasmes, horasdetrabalhoMes, &descontoINSS, &descontoImp, &salariobruto, &horaextra);
            printf("Folha de pagamento do Func. %d\n", i);
            imprimirfolhadepagamento(salariobruto, salarioliquido, descontoINSS, descontoImp, horaextra);
        }
    
}