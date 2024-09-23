#include <stdio.h>
#include <math.h>
#include <time.h>

int primo(int n) {
    
    int limite = (int) sqrt(n);
    
    for (int div = 3; div <= limite; div += 2) {
        if (n % div == 0) return 0; // não é primo
    }
    return 1; // é primo
}

int main() {
    int n = 2, cont = 1, primo_atual = 2;
    n++;
    time_t tempo_inicial = time(NULL);
    printf("PROGRAMA SENDO EXECUTADO, AGUARDE 60 SEGUNDOS!\n");

    while (difftime(time(NULL), tempo_inicial) < 60) {
        if (primo(n)) {
            primo_atual = n;
            cont++;
        }
        
        n+=2;
    }

    printf("Numeros de primos encontrados: %d\nUltimo primo encontrado: %d\n", cont, primo_atual);
    return 0;
}
