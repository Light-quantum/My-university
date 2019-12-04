//
// Created by LinSihan on 2019/11/14.
//
/*************************************************************
    题目描述
    Description
    输入5个人的身高，请你输出他们按照从矮到高的排序结果
    输入描述
    Input
    多组输入，EOF表示结束
    每一组输入将会输入5个正整数，分别表示5个人的身高（整数形式表示）
    身高的范围在 100 - 200之间
    输出描述
    Output
    对于每一组输入，在新的一行输出5个人按照从矮到高的排序结果
*************************************************************/

#include <stdio.h>
int main(){
    int height[5] = {0};
    int i, j, temp;

    while(scanf("%d %d %d %d %d", &height[0], &height[1], &height[2], &height[3], &height[4]) != EOF){
        for(i = 0; i < 4; i++){
            for(j = 0; j < 4 - i; j++){
                if(height[j] > height[j + 1]){
                    temp = height[j + 1];
                    height[j + 1] = height[j];
                    height[j] = temp;
                }
            }
        }

        for(i = 0; i < 5; i++){
            printf("%d ", height[i]);
        }
        printf("\n");
    }
    return 0;
}