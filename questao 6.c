#include <stdio.h>

int euclidesEST ( long long int a, long long int b, long long int matriz[1000][3], int count)
{
    if(b == 0)
    {
        return count;
    }
    else
    {
        count += 1;
        matriz[count][0] = a / b; 
        return euclidesEST(b, a % b, matriz, count);    
    }
}

int main()
{
   long long int a, b, ii, j;
   long long int matriz [1000][3] = { {0,1,0}, {0,0,1} };
  
    printf("Digite A e B:\n");
    scanf("%lld%lld", &a, &b);
    
    j = euclidesEST(a, b, matriz, 1);  // Executa o algoritmo de Euclides
   
    // Calcula os coeficientes de Bézout
    for(ii = 1; ii < j; ii++)
    {
        matriz[ii + 1][1] =  matriz[ii - 1][1] - ( matriz[ii][1] * matriz[ii + 1][0] );
        matriz[ii + 1][2] =  matriz[ii - 1][2] - ( matriz[ii][2] * matriz[ii + 1][0] );
    }
   
   
    printf("%lld * (%lld) + %lld * (%lld)", a, matriz[j - 1][1], b, matriz[j - 1][2]);
   
    return 0;
}