#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para calcular o MDC
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para verificar se dois números são coprimos
int coprimos(int a, int b) {
    return mdc(a, b) == 1;
}

// Função para resolver o sistema de congruências
int teorema_chines_do_resto(int a1, int m1, int a2, int m2, int a3, int m3) {
    // Verifica se os módulos são coprimos
    if (!coprimos(m1, m2) || !coprimos(m1, m3) || !coprimos(m2, m3)) {
        printf("Os módulos não são coprimos.\n");
        return -1;
    }

    int M = m1 * m2 * m3; // Produto dos módulos
    int M1 = M / m1;
    int M2 = M / m2;
    int M3 = M / m3;

    // Calcula os inversos
    int inv1 = 0, inv2 = 0, inv3 = 0;
    for (int i = 1; i < m1; i++) {
        if ((M1 * i) % m1 == 1) {
            inv1 = i;
            break;
        }
    }
    for (int i = 1; i < m2; i++) {
        if ((M2 * i) % m2 == 1) {
            inv2 = i;
            break;
        }
    }
    for (int i = 1; i < m3; i++) {
        if ((M3 * i) % m3 == 1) {
            inv3 = i;
            break;
        }
    }

    // Calcula a solução
    int x = (a1 * M1 * inv1 + a2 * M2 * inv2 + a3 * M3 * inv3) % M;
    
    return (x + M) % M; // Garantir que x seja positivo
}

int main() {
    int a1, m1, a2, m2, a3, m3;

    printf("Digite os valores de a1, m1, a2, m2, a3, m3: ");
    scanf("%d %d %d %d %d %d", &a1, &m1, &a2, &m2, &a3, &m3);

    int solução = teorema_chines_do_resto(a1, m1, a2, m2, a3, m3);

    if (solução != -1) {
        printf("A solução única é: x ≡ %d mod %d\n", solução, m1 * m2 * m3);
    }

    return 0;
}