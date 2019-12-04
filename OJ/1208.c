//
// Created by LinSihan on 2019/11/10.
//
/****************************************************************
    题目描述
    Description
    青年歌手大奖赛中，评委会给参赛选手打分。
    选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，
    请编程输出某选手的得分
    输入描述
    Input
    输入数据有多组，每组占一行，每行的第一个数是n(2＜n＜100)，
    表示评委的人数，然后是n个评委的打分。
    输出描述
    Output
    对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。
****************************************************************/

#include <stdio.h>
int main(){
    int grade[100] = {0};
    int n, i, j;
    int temp;
    while(scanf("%d", &n) != EOF ){
        for(i = 0; i < n; i++){
            scanf("%d", &grade[i]);
        }
        for(i = 0; i < n - 1; i++){
            for(j = 0; j < n - 1 - i; j++){
                if(grade[j] > grade[j + 1]){
                    temp = grade[j + 1];
                    grade[j + 1] = grade[j];
                    grade[j] = temp;
                }
            }
        }
        double averageGrade;
        int sum = 0;
        for(i = 1; i < n - 1; i++){
            sum += grade[i];
        }
        averageGrade = (double)sum / (n - 2);
        printf("%.2lf\n", averageGrade);
    }
    return 0;
}
