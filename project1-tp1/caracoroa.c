// Jogo de cara ou coroa. Segunda questão do trabalho de Técnicas de Programação I, primeiro período 2023.

#include <stdio.h>

int main() {
    int numjogos, contador, resultado;

while(1) {

    do {
        printf("Insira o numero de jogos: ");
        scanf("%d", &numjogos);

            if(1 > numjogos || numjogos > 10000)
            {
                printf("ERRO! O numero de jogos deve estar entre 1 e 10000\n");
            }
            else {
                break;
            }
    } while(1 <= numjogos || numjogos <= 10000);

    int vitmaria = 0, vitjoao = 0;

        for(contador = 1; contador <= numjogos; contador++) {
            scanf("%d", &resultado);

                if(resultado != 0 && resultado != 1) {
                    printf("Jogo abortado! Digite somente 1 ou 0 \n");
                    return main();
                }
                else 
                {
                    if(resultado == 0)
                        vitmaria++;

                    if(resultado == 1)
                        vitjoao++;
                }  
        }
        printf("Maria ganhou %d vez(es) e Joao ganhou %d vez(es)! \n", vitmaria, vitjoao);
}}