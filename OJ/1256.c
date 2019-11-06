//
// Created by LinSihan on 2019/11/3.
//

/***************************************
    输入10个数字，然后逆序输出。
    输入：10个整数
    输出：逆序输出，空格隔开
*****************************************/

#include <stdio.h>
int main(){
    int list[10];
    int i, temp;
    for(i = 0; i < 10; i++){
        scanf("%d", &list[i]);
    }

    for(i = 0; i < 5; i++){
        temp = list[i];
        list[i] = list[9 - i];
        list[9-i] = temp;
    }

    for(i = 0; i < 10; i++){
        printf("%d ", list[i]);
    }

    return 0;
}