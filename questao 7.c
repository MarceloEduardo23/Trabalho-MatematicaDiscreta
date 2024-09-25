#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para calcular o MDC e encontrar o inverso de a mod b
int mdc_extendido(int a, int b, int *s) {
    if (b == 0) {
        *s = 1; // Coeficiente para a
        return a; // Retorna o MDC
    }

    int s1;
    int d = mdc_extendido(b, a % b, &s1);

    // Atualiza o coeficiente
    *s = s1 - (a / b) * (d / b);
    return d; // Retorna o MDC
}

int inverso_modular(int a, int b) {
    int s;
    int d = mdc_extendido(a, b, &s);

    // O inverso existe se o MDC é 1
    if (d != 1) {
        printf("O inverso não existe, pois MDC(%d, %d) = %d\n", a, b, d);
        return -1; // Inverso não existe
    }

    // O resultado deve ser positivo
    return (s % b + b) % b;
}

int main() {
    int a, b;

    printf("Digite dois inteiros (a e b): ");
    scanf("%d %d", &a, &b);

    int inverso = inverso_modular(a, b);

    if (inverso != -1) {
        printf("O inverso de %d mod %d é: %d\n", a, b, inverso);
    }

    return 0;
}