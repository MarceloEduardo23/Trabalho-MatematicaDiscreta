#include<stdio.h>


int Achar_coeficientes (long long int a, long long int b, long long int matriz[1000][3], int count)
{
    if(b == 0)
    {
        return count;
    }
    else
    {
        count += 1;
        matriz[count][0] = a / b; 
        return Achar_coeficientes(b, a % b, matriz, count);    
    }
}

void euclidesEST (long long int a, long long  int b, long long int *s, long long int *t)
{
   int ii, j;
   long long int matriz [1000][3] = { {0,1,0}, {0,0,1} };
  
    j = Achar_coeficientes (a, b, matriz, 1);  // Executa o algoritmo de Euclides
   
    
    for(ii = 1; ii < j; ii++) // Calcula os coeficientes de Bézout
    {
        matriz[ii + 1][1] =  matriz[ii - 1][1] - ( matriz[ii][1] * matriz[ii + 1][0] );
        matriz[ii + 1][2] =  matriz[ii - 1][2] - ( matriz[ii][2] * matriz[ii + 1][0] );
    }
   
   
     *s = matriz[j - 1][1]; // maior valor
     *t = matriz[j - 1][2]; // menor valor
   
    return;
}

int main ()
{
     long long int a, b, s, t;
    int temp, count;
    
    count = 1;
    
    printf("Digite A e B:\n");
    scanf("%lld%lld",&a,&b);

   if (a < b)
   {
   temp = a;
   a = b;
   b = temp; 
       
  euclidesEST ( a,  b,&s, &t); // retorna s e t;
       
       while ( t < 0)
        {
            t += a * count;
            count++;
        }

       printf("%lld",t);

   }
    else
   {
       euclidesEST ( a,  b,&s, &t); // retorna s e t;
       
        while ( s < 0)
        {
            s += b * count;
            count++;
        }
       printf("%lld", s); 
   } 
    
 return 0;
}