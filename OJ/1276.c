//
// Created by LinSihan on 2019/11/3.
//
/*********************************************
    题目描述
    Description
    有n个整数，使前面各数顺序向后移m个位置，最后m个数变成前面m个数，见图。写一函数：实现以上功能，在主函数中输入n个数和输出调整后的n个数。
    输入描述
    Input
    输入数据包括整数的个数n，第二行有n个整数，第三行为整数m。
    输出描述
    Output
    移动后的n个数，每个数后面接一个空格
*********************************************/

#include <stdio.h>
int main(){
    int n, m;
    scanf("%d", &n);
    int list[n], list1[n];
    int i;

    for(i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }
    scanf("%d", &m);
    for(i = 0; i < n; i++){
        if(i + m <= n - 1){
            list1[ i + m] = list[i];
        }
        else{
            list1[ i + m - n] = list[i];
        }
    }

    for(i = 0; i < n; i++){
        printf("%d ", list1[i]);
    }
    return 0;
}