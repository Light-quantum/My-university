//
// Created by LinSihan on 2019/11/17.
//
/****************************************************************************
    题目描述
    Description
    一本书的页码从自然数1 开始顺序编码直到自然数n。书的页码按照通常的习惯编排，
    每个页码都不含多余的前导数字0。例如，第6 页用数字6 表示，而不是06 或006 等。数
    字计数问题要求对给定书的总页码n，计算出书的全部页码中分别用到多少次数字0，1，
    2，…，9。
    输入描述
    Input
    给出表示书的总页码的整数n（1≤n≤2^31-1）
    输出描述
    Output
    输出10行，在第k行输出页码中用到数字k-1 的次数，k=1，2，…，0。
*****************************************************************************/

#include <stdio.h>
#include <string.h>

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

int main(){
    int n;
    int j, i, len;
    char num[10] = "\0";
    int count[10] = {0};
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        num_turn_to_str(i, num);
        len = strlen(num);
        for(j = 0; j < len; j++){
            count[num[j] - '0']++;
        }
    }

    for(i = 0; i < 10; i++){
        printf("%d\n", count[i]);
    }
    return 0;
}