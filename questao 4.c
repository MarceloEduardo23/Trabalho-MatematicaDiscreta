#include <stdio.h>

long long mdc(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long mmc(long long a, long long b) {
    return (a / mdc(a, b)) * b;  // Usando a relação entre MMC e MDC
}

int main() {
    long long n1, n2;
    printf("Digite dois números: ");
    scanf("%lld %lld", &n1, &n2);
    
    // Calcular e exibir MDC
    long long res_mdc = mdc(n1, n2);
    printf("MDC de (%lld, %lld): = %lld\n", n1, n2, res_mdc);
    
    // Calcular e exibir MMC
    long long res_mmc = mmc(n1, n2);
    printf("MMC de (%lld, %lld): = %lld\n", n1, n2, res_mmc);
    
    return 0;
}
