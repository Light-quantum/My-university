//
// Created by LinSihan on 2019/12/27.
//
/* *********************************************************************
    题目描述
    Description
    小强从小就喜欢生命科学，他总是好奇花草鸟兽从哪里来的。
    终于， 小强上中学了，接触到了神圣的名词--DNA.它有一个双螺旋的结构。
    这让一根筋的小强抓破头皮，“要是能画出来就好了” 小强喊道。现在就请你帮助他吧
    输入描述
    Input
    输入包含多组测试数据。第一个整数N（N<=15）,N表示组数，
    每组数据包含两个整数a,b。a表示一个单位的DNA串的行数，
    a为奇数且 3<=a<=39。b表示重复度(1<=b<=20)。
    输出描述
    Output
    输出DNA的形状，每组输出间有一空行。
**********************************************************************/

#include <stdio.h>

void printDNA(int len, int multiplicity);
int main(){
    int n;
    int len, multiplicity;
    int i = 0;
    scanf("%d", &n);
    while(n--){
        if(i != 0){
            printf("\n");
        }
        scanf("%d %d", &len, &multiplicity);
        printDNA(len, multiplicity);
        i = 1;
    }
    return 0;
}

void printDNA(int len, int multiplicity){
    int i, j = 1;
    for(i = 1; i <= multiplicity; i++){
        for(; j <= len; j++){
            if(j == (len / 2 + 1)){
                printf("X \n");
            }
            else{
                printf("X X \n");
            }
        }
        j = 2;
    }
}
