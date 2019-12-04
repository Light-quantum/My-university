//
// Created by LinSihan on 2019/11/7.
//
/*使用函数判断是否是素数*/

#include <math.h>
#include <stdio.h>

int getWhetherPrime(long long n);
int main(){
    long long n;
    int ret;
    while(scanf("%lld", &n) != EOF){
        ret = getWhetherPrime(n);
        if(ret == 0){
            printf("notprime\n");
        }
        else{
            printf("prime\n");
        }
    }
    return 0;
}

int getWhetherPrime(long long n){
    long long i,k;
    long long prime = 1;
    if(n == 1){
        prime = 0;
    }
    else {
        k = sqrt(n);
        for (i = 2; i <= k; i++) {
            if (n % i == 0) {
                prime = 0;
                break;
            }
        }
    }
    return prime;
}