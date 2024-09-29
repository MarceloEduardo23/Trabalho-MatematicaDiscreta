#include<stdio.h>

int mdc (long long int a,  long long int b) // bom e velho euclidson
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return mdc(b,a % b);
    }
}

void troca (long long int *a, long long  int *b)
{
    long long int temp;

        temp = *a;
        *a = *b;
        *b = temp;
}

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

        return Achar_coeficientes (b, a % b, matriz, count);    
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

int inverso (long long int a, long long int b)
{
    long long int s, t;
    int  count;
    
    count = 1;
   
   if (a < b)
   {
        troca(&a,&b); // realiza a troca para grantir que o euclidson rode 
       
        euclidesEST ( a,  b, &s, &t); // retorna s e t;
       
                while ( t < 0)
                    {
                        t += a * count;
                        count++;
                    }

         return t;
   }
   else
   {
         euclidesEST ( a,  b, &s, &t); // retorna s e t;
       
                while ( s < 0)
                {
                    s += b * count;
                    count++;
                }

       return s; 
   } 
    
}

int main ()
{
    long long int a, b, m, temp;

    printf("Digite A, B, M\n");
    scanf("%lld%lld%lld", &a, &b, &m);

    if (a < m) // condição 1  
    {
      temp =  mdc(m,a);

            if(b % temp != 0) // verifica se tem solução
            {
                printf("Não tem solução");
                return 0;
            }

            if(temp > 1) // simplifica se possível
            {
                a /= temp;
                b /= temp;
                m /= temp;
            }

    }
    else // condição 2 (a > m)
    {
     temp =  mdc(a,m);

            if(b % temp != 0) // verifica se tem solução
            {
                printf("Não tem solução");
                return 0;
            }
            if(temp > 1) // simplifica se possível
            {
                a /= temp;
                b /= temp;
                m /= temp;
            }
    }

     printf("%lld + %lld * K", (inverso(a,m) * b) % m , m );

    return 0;
    
}