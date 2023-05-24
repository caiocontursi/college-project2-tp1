#include <stdio.h>

float main (){
  float x, result,pot0, pot1;
  int n;
  
  do {
    printf("Informe o valor de x: ");
    scanf("%f", &x);

    if (x >= 1 || x < 0)
    {
      printf ("O valor absoluto de x deve ser menor que 1. Informe novamente.\n");
    }



  } while (x >= 1 || x < 0);

  do {
    printf ("Informe o valor de n: ");
    scanf ("%d", &n);

    if (n < 0)
    {
      printf("O valor de n deve ser maior ou igual a 0. Informe novamente.\n");
    }

  }while(n < 0);

  for ( int i = 0; i <= n; i++){
    pot0 =1;
    pot1 =1;
    for ( int i2 = 0; i2 <i ; i2++)
    {

      pot0 = pot0 * -1;
    }

    for ( int i3 = 0; i3 < 2 * i + 1; i3++)
    {
      pot1 = pot1 * x;
    }


    result += ((pot0)/ (2 * i + 1)) * (pot1);

  }
    printf("Resultado: %f", result);
}