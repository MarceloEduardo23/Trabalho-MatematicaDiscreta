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
    *s = t1;
    *t = s1 - (a / b) * t1;

    return d; // Retorna o MDC
}

// Função para resolver a congruência ax ≡ b mod m
void resolver_congruencia(int a, int b, int m) {
    int s, t;
    int d = mdc_extendido(a, m, &s, &t);

    // Verifica se b é divisível pelo MDC
    if (b % d != 0) {
        printf("Não há solução.\n");
        return;
    }

    // Reduzindo a e m
    a /= d;
    b /= d;
    m /= d;

    // Encontrar o inverso de a mod m
    int inverso = (s * (b / d)) % m;
    if (inverso < 0) {
        inverso += m; // Garante que o inverso seja positivo
    }

    printf("Solução geral: x ≡ %d mod %d\n", inverso, m);
}

int main() {
    int a, b, m;

    printf("Digite os valores de a, b e m (ax ≡ b mod m): ");
    scanf("%d %d %d", &a, &b, &m);

    resolver_congruencia(a, b, m);

    return 0;
}