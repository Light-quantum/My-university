//
// Created by LinSihan on 2019/12/3.
//
/**********************************************************
    题目描述
    Description
    还记得中学时候学过的杨辉三角吗？
    具体的定义这里不再描述，你可以参考以下的图形：
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    1 5 10 10 5 1
    输入描述
    Input
    输入数据包含多个测试实例，
    每个测试实例的输入只包含一个正整数n（1＜=n＜=30），
    表示将要输出的杨辉三角的层数。
    输出描述
    Output
    对应于每一个输入，请输出相应层数的杨辉三角，
    每一层的整数之间用一个空格隔开，每一个杨辉三角后面加一个空行。
************************************************************/

#include <stdio.h>
void get_YH_triangle(long long YH[31][31]);
int main(){
    long long YH[31][31] = {0};
    int i, j, n;
    get_YH_triangle(YH);

    while(scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            for (j = 0; j <= i; j++) {
                printf("%lld ", YH[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void get_YH_triangle(long long YH[31][31]){
    int i = 0, j = 0;

    for(i = 0; i < 31; i++){
        YH[i][0] = 1;
    }

    for(i = 1; i < 31; i++){
        for(j = 1; j <= i; j++){
            YH[i][j] = YH[i - 1][j - 1] + YH[i - 1][j];
        }
    }
}