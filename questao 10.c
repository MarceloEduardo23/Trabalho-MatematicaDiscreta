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

// Função para encontrar o inverso modular
int inverso_modular(int a, int m) {
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) {
            return i;
        }
    }
    return -1; // Inverso não encontrado
}

// Função para resolver o sistema de congruências
int teorema_chines_do_resto(int a[], int m[], int n) {
    // Verifica se os módulos são coprimos
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!coprimos(m[i], m[j])) {
                printf("Os módulos não são coprimos.\n");
                return -1;
            }
        }
    }

    int M = 1; // Produto total dos módulos
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }

    int x = 0; // Solução

    // Calcula a solução
    for (int i = 0; i < n; i++) {
        int M_i = M / m[i];
        int inv = inverso_modular(M_i, m[i]);

        if (inv == -1) {
            printf("Inverso não encontrado para m[%d].\n", i);
            return -1;
        }

        x = (x + a[i] * M_i * inv) % M;
    }

    return (x + M) % M; // Garante que x seja positivo
}

int main() {
    int n;

    printf("Digite o número de congruências: ");
    scanf("%d", &n);

    int a[n], m[n];

    printf("Digite os valores de a e m para cada congruência:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
        printf("m[%d]: ", i);
        scanf("%d", &m[i]);
    }

    int solução = teorema_chines_do_resto(a, m, n);

    if (solução != -1) {
        printf("A solução única é: x ≡ %d mod %d\n", solução, m[0] * m[1] * m[2]); // Produto dos módulos
    }

    return 0;
}