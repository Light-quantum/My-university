//
// Created by LinSihan on 2019/11/15.
//
/**********************************************************************************
    题目描述
    Description
    学校要派出一支队伍出去打球赛，校内有很多同学自发的组成了若干支队伍，每支队伍都有5个人。
    其中每个人都会有一个综合评价分k。
    现在学校的要求是：5个人的平均综合评价分要高于70且最低分不低于65分才算合格。
    输入一个队伍中5个人的综合评价分，你能告诉我这支队伍是否合格吗？
    合格的话打印True否则打印False
    输入描述
    Input
    多组输入，EOF结束
    每组输入1行，有5个整数，分别表示5个人的综合评价分k，（k∈[0,100]）
    输出描述
    Output
    对于每组输入，在新的一行输出结果
************************************************************************************/

#include <stdio.h>

int main(){
    int score[5] = {0};
    double averageScore;
    int min, i;

    while(scanf("%d %d %d %d %d", &score[0], &score[1], &score[2], &score[3], &score[4]) != EOF){
        averageScore = (score[0] + score[1] + score[2] + score[3] + score[4]) / 5.0;
        min = score[0];

        for(i = 1; i < 5; i++){
            if(score[i] < min){
                min = score[i];
            }
        }

        if(averageScore > 70 && min >= 65){
            printf("True\n");
        }
        else{
            printf("False\n");
        }
    }
    return 0;
}