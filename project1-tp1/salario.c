#include <stdio.h>

void lerfuncionarios(char *funçao, int *anos, int *horascontratadas,
                     int *horasdetrabalho) {
  do {
    printf("- Função: ");
    fflush(stdin);
    scanf(" %c", &*funçao);

    if (*funçao != 'a' && *funçao != 'A' && *funçao != 'p' && *funçao != 'P' &&
        *funçao != 'g' && *funçao != 'G') {
      printf("Selecione apenas entre A/a (analista), P/p (progamador), G/g "
             "(gerente).\n");
    }

  } while (*funçao != 'a' && *funçao != 'A' && *funçao != 'p' &&
           *funçao != 'P' && *funçao != 'g' && *funçao != 'G');

  do {
    printf("- Anos de experiência: ");
    scanf("%d", &*anos);

    if (*anos < 0) {
      printf(
          "ATENÇÃO! Os anos de experiência devem ser maior ou igual a zero. \n");
    }

  } while (*anos < 0);

  do {
    printf("- Horas contratadas: ");
    scanf("%d", &*horascontratadas);

    if (*horascontratadas < 0) {
      printf("ATENÇÃO! As horas contratadas devem ser maior que zero.\n");
    }

  } while (*horascontratadas < 0);

  do {
    printf("- Horas de trabalho: ");
    scanf("%d", &*horasdetrabalho);

    if (*horasdetrabalho < 0) {
      printf(
          "ATENÇÃO! As horas de trabalho devem sem maior ou igual a zero.\n");
    }

  } while (*horasdetrabalho < 0);
}

float calcularsalario(char funçao, int anos, int horascontratadas,
                      int horasdetrabalho, float *descontoINSS,
                      float *descontoImp, float *salariobruto, int *horaextra) {
  float valorhora, salarioliquido, porcentImp, porcent;
  porcent = 0;
  porcentImp = 0;
  *horaextra = 0;

  if (horasdetrabalho > horascontratadas) {
    *horaextra = horasdetrabalho - horascontratadas;

    if (*horaextra <= 13) {
      porcent = 0.23;

    } else if (*horaextra > 13 && *horaextra <= 22) {
      porcent = 0.37;

    } else if (*horaextra > 22) {
      porcent = 0.56;
    }

    
  }

  if (anos <= 2) {
    if (funçao == 'p' || funçao == 'P') {
      valorhora = 25;
    } else if (funçao == 'a' || funçao == 'A') {
      valorhora = 45;
    } else if (funçao == 'g' || funçao == 'G') {
      valorhora = 85;
    }
  } else if (anos >= 3 && anos <= 5) {
    if (funçao == 'p' || funçao == 'P') {
      valorhora = 30;
    } else if (funçao == 'a' || funçao == 'A') {
      valorhora = 55;
    } else if (funçao == 'g' || funçao == 'G') {
      valorhora = 102;
    }
  } else if (anos > 5) {
    if (funçao == 'p' || funçao == 'P') {
      valorhora = 38;
    } else if (funçao == 'a' || funçao == 'A') {
      valorhora = 70;
    } else if (funçao == 'g' || funçao == 'G') {
      valorhora = 130;
    }
  }

  *salariobruto = valorhora * horasdetrabalho;
  *salariobruto = *salariobruto + *horaextra * valorhora * porcent;

  if (*salariobruto > 1500 && *salariobruto <= 2700) {
    porcentImp = 0.15;
  } else if (*salariobruto > 2700 && *salariobruto <= 4200) {
    porcentImp = 0.20;
  } else if (*salariobruto > 4200) {
    porcentImp = 0.30;
  }

    *descontoINSS = *salariobruto * 0.11;
    *descontoImp = (*salariobruto - *descontoINSS) * porcentImp;


  salarioliquido = *salariobruto - *descontoINSS - *descontoImp;

  return salarioliquido;
}

void imprimirfolhadepagamento(float salariobruto, int horaextra,
                              float descontoINSS, float descontoImp,
                              float salarioliquido) {
  printf("salario bruto(R$):%.2f \n", salariobruto);

    if (horaextra) {
        printf("horas excedentes(h):%d\n", horaextra);
    }


  printf("Desconto INSS(R$):%.2f\n", descontoINSS);
  printf("Desconto IR(R$):%.2f\n", descontoImp);
  printf("salário líquido(R$):%.2f\n", salarioliquido);
}

int main() {
  char funçaofuncionario;
  float descontoINSS, descontoImp, salariobruto, salarioliquido;
  int numfuncionarios, anosexperiencia, horascontratadasmes, horasdetrabalhoMes,
      horaextra, i;
  numfuncionarios = 0;

  do {
    printf("Número de funcionarios: ");
    scanf("%d", &numfuncionarios);

    if (numfuncionarios <= 0) {
      printf("ATENÇÃO: a quantidade de funcionários deve ser maior que zero."
             "Informe novamente.\n");
    }

  } while (numfuncionarios <= 0);

  for (i = 1; i <= numfuncionarios; i++) {
    printf("=============================\n");
    printf("Funcionário %d\n", i);

    lerfuncionarios(&funçaofuncionario, &anosexperiencia, &horascontratadasmes,
                    &horasdetrabalhoMes);
    salarioliquido =
        calcularsalario(funçaofuncionario, anosexperiencia, horascontratadasmes,
                        horasdetrabalhoMes, &descontoINSS, &descontoImp,
                        &salariobruto, &horaextra);

    printf("folha de pagamento do funcionário: %d\n", i);
    imprimirfolhadepagamento(salariobruto, horaextra, descontoINSS, descontoImp,
                             salarioliquido);
  }
}