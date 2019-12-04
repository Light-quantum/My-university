//
// Created by LinSihan on 2019/11/17.
//
/********************************************
    判断一个数是否为素数
********************************************/

#include <stdio.h>
#include <math.h>

int isPrime(int n){
    int i;
    double k = sqrt(n);
    int isPrime = 1;
    for(i = 2; i < k; i++){
        if(n % i == 0){
            isPrime = 0;
            break;
        }
    }
    return isPrime ? 1 : 0;
}

int main(){
    int n;
    scanf("%d", &n);
    if(isPrime(n)){
        printf("Y\n");
    } 
    else{
        printf("N\n");
    }
    return 0;
}