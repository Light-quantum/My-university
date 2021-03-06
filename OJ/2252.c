//
// Created by LinSihan on 2019/12/8.
//
/************************************************************************
    题目描述
    Description
    通过对整数的数字求和来找到正整数的数字根。
    如果结果值是单个数字，则该数字是数字根。
    如果结果值包含两个或更多位数字，则将这些数字相加，并重复该过程。
    只要有必要获得单个数字，这是继续的。

    例如，考虑正整数24.添加2和4产生值6.由于6是一个数字，6是数字根。
    现在考虑正整数39.添加3和9的收益12.由于12不是单个数字，所以必须重复该过程。
    添加1和2年3，一个数字，也是39的数字根。
    输入描述
    Input
    输入文件将包含正整数列表，每行一个。输入0时程序结束。
    输出描述
    Output
    对于输入中的每个整数，在输出的单独一行上输出其数字根。
************************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    int n, root = 0;

    while(scanf("%d", &n), n != 0){
        root = 0;
        while(n % 10 == 0){
            n = n / 10;
        }
        while(n){
            root += (n % 10);
            n /= 10;
        }
        n = root;
        while(root >= 10){
            int sum = 0;
            while(n % 10 == 0){
                n = n / 10;
            }
            while(n){
                sum += (n % 10);
                n /= 10;
            }
            root = sum;
        }
        printf("%d\n", root);
    }
    return 0;
}