//
// Created by LinSihan on 2019/11/2.
//
/**************************************
 * 按如下递归公式求函数值。
        x=1时 f(x)=10；x>1时 f(x)=f(x-1)+2
 ......................................
 输入：x
 输出：f(x)
 *************************************/
#include <stdio.h>
int main(){
    int x, f = 0, i;
    scanf("%d", &x);

    if(x == 1){
        f = 10;
    }
    else{
        for(i = 1; i <= x; i++){
            if(i == 1){
                f = 10;
            }
            else {
                f = f + 2;
            }
        }
    }
    printf("%d", f);
    return 0;
}