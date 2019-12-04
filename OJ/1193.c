//
// Created by LinSihan on 2019/12/3.
//
/**********************************************************************
    题目描述
    Description
    小王对既是素数又是回文的数特别感兴趣。比如说151既是素数又是个回文。
    现在小王想要你帮助他找出某个范围内的素数回文数，
    请你写个程序找出 a 跟b 之间满足条件的数。(5 <= a < b <= 100,000,000);
    输入描述
    Input
    输入a和b(5 <= a < b <= 100,000,000)
    输出描述
    Output
    按从小到大输出a，b之间所有满足条件的素数回文数
***********************************************************************/

// 1.判断是否为素数
// 2.判断是否为为回文数

#include <stdio.h>
#include <math.h>
#include <string.h>
int isPrime(int n);
void num_turn_to_str(int temp, char list[]);
int isPalindromicNumber(int n);
int main(){
    int a, b;
    int i;

    scanf("%d %d", &a, &b);
    for(i = a; i <= b; i++){
        if(i > 9989899){
            break;
        }
        if(isPrime(i)){
            if(isPalindromicNumber(i)){
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
//这个函数太慢了
int isPrime(int n){
    int i;
    double k = sqrt(n);
    int isPrime = 1;
    for(i = 2; i <= k; i++){
        if(n % i == 0){
            isPrime = 0;
            break;
        }
    }
    return isPrime ? 1 : 0;
}

void num_turn_to_str(int temp, char list[]){
    int i = 0;
    while(1){
        list[i] = temp % 10 + '0'; // 从个位开始转为字符然后存入字符数组
        temp = temp / 10;  //存入后去掉个位
        i++;
        if(temp == 0){
            break;
        }
    }
    list[i] = '\0'; //添加字符串结束标记
}

int isPalindromicNumber(int n){
    char list[20];
    int i = 0;
    int len;
    num_turn_to_str(n, list);
    len = strlen(list);
    for(i = 0; i < len / 2; i++){
        if(list[i] != list[len -1 -i]){
            return 0;
        }
    }
    return 1;
}