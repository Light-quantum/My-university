//Created by LinSihan on 2019/10/27.
/************************
 * 1000内水仙花数
 * 重点获得百位，十位，个位
 * 每个数用空格隔开，最后无空格
 *************************/

#include <stdio.h>
int main(){
    int n;
    int a, b, c;
    for (n = 100; n <1000; n++){
        a = n / 100;  // 997  a = 9
        b = (n - a * 100) / 10; // 997 - 900 = 97
        c = (n - (n / 10) * 10);
        if (a*a*a + b*b*b + c*c*c == n){
            if (n != 153) {
                printf(" ");
            }
            printf("%d", n);
        }
    }
    return 0;
}
