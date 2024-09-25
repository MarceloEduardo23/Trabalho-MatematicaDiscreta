#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para calcular o MDC e os coeficientes s e t
int mdc_extendido(int a, int b, int *s, int *t) {
    if (b == 0) {
        *s = 1; // Coeficiente para a
        *t = 0; // Coeficiente para b
        return a; // Retorna o MDC
    }
    
    int s1, t1;
    int d = mdc_extendido(b, a % b, &s1, &t1);
    
    // Atualiza os coeficientes
    *s = t1; // s = t1
    *t = s1 - (a / b) * t1; // t = s1 - (a / b) * t1

    return d; // Retorna o MDC
}

int main() {
    int a, b, s, t;

    printf("Digite dois inteiros (a e b): ");
    scanf("%d %d", &a, &b);

    int mdc = mdc_extendido(a, b, &s, &t);

    printf("MDC(%d, %d) = %d\n", a, b, mdc);
    printf("Coeficientes: s = %d, t = %d\n", s, t);

    return 0;
}