//Created by LinSihan on 2019/10/28.
/************************
 * 舍罕王的失算
 ************************/

#include <stdio.h>
int main(){
    int i, a = 1;
    unsigned long long sum;
    for(i = 1; i <= 64; i++){
        if(i == 1){
            sum = 1;
        }
        else{
            a = a * 2;
            sum = sum + a;
        }
    }
    printf("%llu", sum);
    return 0;
}
