int primo(int n) {
    if (n <= 1) return 0; // 1 e negativos não são primos
    if (n == 2) return 1; // 2 é primo
    if (n % 2 == 0) return 0; // elimina números pares

    int limite = (int) sqrt(n);
    
    for (int div = 3; div <= limite; div += 2) {
        if (n % div == 0) return 0; // não é primo
    }
    return 1; // é primo
}

int main(){
    int num;
    scanf("%d", &num);

    int res = primo(num);

    if(res == 1){
        printf("E PRIMO!\n");
    }else{
        printf("NAO E PRIMO\n");
    }

    return 0;
}