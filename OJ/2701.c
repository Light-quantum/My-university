//
// Created by LinSihan on 2019/11/15.
//

/************************************************************************
    题目描述
    Description
    你的任务是对五个数字a,b,c,d,e进行处理，请你计算 a+b-c*d/e 的结果
    注意：除法使用整数除法，例如 5 / 4 = 1，2 / 3 = 0
    输入描述
    Input
    输入一共有n+1行
    第一行输入一个整数n，表示接下来有n行输入，其中n不大于10000
    接下来n行每行有5个整数a,b,c,d,e,其中e不为0，5个整数的绝对值都不会大于1000
    输出描述
    Output
    对于每行输入，在新的一行输出结果
***************************************************************************/

#include <stdio.h>

int main(){
    int n;
    int a, b, c, d, e;

    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        printf("%d\n", a + b - (c * d / e));
    }
    return 0;
}