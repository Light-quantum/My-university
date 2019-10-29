// Created by LinSihan on 2019/10/27.
/*******************
 * 求素数问题
 *******************/


#include <stdio.h>
#include <math.h>
int main(){
    int n, j, i, prime;
    double k;
    scanf("%d", &n);
    for(i = 2; i <= n; i++) {
        k = sqrt(i);
        prime = 1;
        for(j = 2; j <= k; j++){
            if(i % j == 0) {
                prime = 0;
            }
        }
        if (prime == 1){
            printf("%d ", i);
        }
    }
    return 0;
}