//
// Created by LinSihan on 2019/11/3.
//
/***********************************************************************************************
 * 定义一个带参的宏，使两个参数的值互换，并写出程序，输入两个数作为使用宏时的实参。输出已交换后的两个值。
 **********************************************************************************************/

//投机取巧的

#include <stdio.h>
int main(){
    int a, b, temp;
    scanf("%d %d", &a, &b);
    temp = a;
    a = b;
    b = temp;
    printf("%d %d", a, b);
    return 0;
}