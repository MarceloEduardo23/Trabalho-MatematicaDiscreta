#include<stdio.h>
#include<stdlib.h>

#define TAM 1000  // tamanho max dos arrays


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

void troca (long long int *a, long long  int *b) // troca o valor de uma variável pela outra e virce- versa;
{
    long long int temp;

        temp = *a;
        *a = *b;
        *b = temp;
}

int Achar_coeficientes (long long int a, long long int b, long long int matriz[TAM][3], int count)
{
    if(b == 0)
    {
        return count;
    }
    else
    {
        count += 1; // os coeficinets são preenchidos aparatir da 3 linha da tabela
        matriz[count][0] = a / b; // extrai os quocientes usados na tabela

        return Achar_coeficientes (b, a % b, matriz, count);    
    }
}

void euclidesEST (long long int a, long long  int b, long long int *s, long long int *t)
{
   int ii, j;
   long long int matriz [TAM][3] = { {0,1,0}, {0,0,1} }; // condição inicial da tabela bezout
  
    j = Achar_coeficientes (a, b, matriz, 1);  // Executa o algoritmo de Euclides
   
    
    for(ii = 1; ii < j; ii++) // Calcula os coeficientes de Bézout regra da tabela
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
   
   if (a < b) // caso 1 com o inverso sendo o coeficinte linear do menor
   {
        troca(&a,&b); // realiza a troca para grantir que o euclidson rode 
       
        euclidesEST ( a,  b, &s, &t); // retorna s e t;
       
                while ( t < 0) // reescreve o inverso positívo
                    {
                        t += a * count;
                        count++;
                    }

         return t;
   }
   else // caso 2 sendo o inverso coeficinte linear do maior
   {
         euclidesEST ( a,  b, &s, &t); // retorna s e t;
       
                while ( s < 0) // reescreve o inverso positivo
                {
                    s += b * count;
                    count++;
                }

       return s; 
   } 
    
}

int Comb_linear (long long int *AA, long long int *BB, long long int *MM) // reescreve as congruencias lineares;
{
    long long int a, b , m;
    long long int temp, auxA, auxM;

    a = *AA ;
    auxA = *AA ;
    b = *BB;
    m = *MM;
    auxM = *MM;

    if (a < m) // garante que mdc execute corretamente;
    {
        troca(&auxA, &auxM);
    }

    temp =  mdc(auxA,auxM);

    if(b % temp != 0) // verifica se tem solução
    {
       return 777;
    }

    if(temp > 1) // simplifica se possível
    {
        a /= temp;
        b /= temp;
        m /= temp;
    }

        ( *AA )  =  1; // equivale ao coeficinete de X 
       ( *BB ) = ( (inverso(a,m) * b) % m );
       ( *MM ) = m; 

    return 7;
  
}

int main ()
{
    long long int array_b[TAM], array_m[TAM], array_MM[TAM], array_inv_MM[TAM], array_mult_geral[TAM]; // se X = 1 não ira receber tratamento como combinação linear
    long long int *array_X = (long long int *)malloc(TAM * sizeof(long long int)); // tentar economizar um pouco de memória
    long long int aux_array_m1, aux_array_m2; // auxliares para garantir o mdc correto;
    long long int mult_arr_M, soma_final;

    int I, II, aux_I, qtd;

    mult_arr_M = 1;
    soma_final = 0;

    printf("Digite a quantidade de congruencias entre 2 e 1000\n");
    scanf("%d", &qtd );

    if(qtd > 1000 || qtd < 2)
    {
        printf("tamnho inválido");
        return 0;
    }

    printf("Digite as congruencias no formato ""a"" congrente a ""B"" mod ""m""\n"); 
    printf("Sendo ""a"" um o coeficinete que multiplica X, (geralmente 1)\n"); // se for negativo eu desisto do curso
    
    for (I = 0; I < qtd; I++)
    {
        scanf("%lld%lld%lld", &array_X[I], &array_b[I], &array_m[I]); 

        aux_I = 1;
        while (array_b[I] < 0) // caso haja um b negativo
        {
            array_b[I] += (array_m[I] * aux_I); // tornalo- emos positivo 
            aux_I ++;
        }

        if(array_X[I] > 1)
        {
                if (Comb_linear(&array_X[I], &array_b[I], &array_m[I]) == 777) // equação tratada com coeficinte X = 1, se não funcionar façamos o L!
                {
                    printf("Não há solução para congruência linar posição: %d", I + 1);
                    return 0;
                } 
        }
        
        mult_arr_M *= array_m[I];
    }

  free(array_X); // reslovido essa parte trabalharemos apenas com a e b

  for (I = 0; I < qtd - 1; I++)
  {
            for (II = I + 1; II < qtd; II++ )
            {
                aux_array_m1 = array_m[I]; 
                aux_array_m2 = array_m[II]; 

                if ( aux_array_m1 < aux_array_m2)
                {
                        troca(&aux_array_m1, &aux_array_m2);
                }

                if( mdc(aux_array_m1, aux_array_m2) != 1)
                {
                        printf("conguencias %d e %d não são cóprimas",I + 1, II + 1);
                        return 0;
                }
            }
  }
    for(I = 0; I < qtd; I++)
    {
       array_MM[I] = mult_arr_M / array_m[I]; // col M da realção (mult dos mods / mod)
       array_inv_MM[I] = inverso(array_MM[I], array_m[I]); // inverso da col M com o mod m
       array_mult_geral[I] = array_b[I] * array_MM[I] * array_inv_MM[I]; // val b (col a) * inverso * col M

        soma_final += array_mult_geral[I]; // soma da col A * M * M^-1
    }

    printf("%lld + (%lld * k)", soma_final % mult_arr_M, mult_arr_M);
    return 0;
}