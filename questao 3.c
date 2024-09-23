#include <stdio.h>

void fatores_primos ( int n, int base)
{
    if ( n <= 1)
    {
        //printf("Nao existe");
        return ;
    } 
    if ( n % base == 0)
    {
        printf("%d ", base);
        fatores_primos( n / base, base);
    } 
    else 
    {
        fatores_primos(n, base+1);
    }
}

int main()
{
    int n, res;
    scanf("%d", &n);
    res = 2;
    
    
    printf("Os fatores primos de %d sao : ", n);
    
    fatores_primos(n, res);
    
    return 0;
}