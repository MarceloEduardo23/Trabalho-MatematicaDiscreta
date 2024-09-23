#include <stdio.h>

int mdc(int A, int D, int R){
    
    int r = A;
    
    R = A%D;
    int Q = A/D;
    
    printf("%d = %d x %d + %d\n", r, D, Q, R);
    
    if (R == 0){
        return D;
    }
    else{
        A = D;
        mdc(A, D=R, R);
    }
}

int main(){
    int A, D, R;
    scanf("%d%d", &A, &D);
    
    int a = A;
    int b = D;
    
    R = A;
    
    int res = mdc(A, D, R);
    
    printf("\nMDC(%d, %d) = %d", a, b, res);


    return 0;
}

