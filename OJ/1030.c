//
// Created by LinSihan on 2019/11/25.
//
/***********************************************************************************
    题目描述
    Description
    某小学最近得到了一笔赞助，打算拿出其中一部分为学习成绩优秀的前5名学生发奖学金。
    期末，每个学生都有3门课的成绩:语文、数学、英语。
    先按总分从高到低排序，如果两个同学总分相同，再按语文成绩从高到低排序，
    如果两个同学总分和语文成绩都相同，那么规定学号小的同学 排在前面，
    这样，每个学生的排序是唯一确定的。
    任务：先根据输入的3门课的成绩计算总分，然后按上述规则排序，
    最后按排名顺序输出前五名名学生的学号和总分。注意，在前5名同学中，每个人的奖学金都不相同，
    因此，你必须严格按上述规则排序。
    例如，在某个正确答案中，如果前两行的输出数据(每行输出两个数:学号、总分) 是:
    7 279
    5 279
    这两行数据的含义是:总分最高的两个同学的学号依次是7号、5号。
    这两名同学的总分都是 279 (总分等于输入的语文、数学、英语三科成绩之和) ，
    但学号为7的学生语文成绩更高一些。如果你的前两名的输出数据是:
    5 279
    7 279
    则按输出错误处理，不能得分。
    输入描述
    Input
    输入文件scholar.in包含n+1行:
    第1行为一个正整数n，表示该校参加评选的学生人数。
    第2到n+1行，每行有3个用空格隔开的数字，每个数字都在O到100之间z第1行的3个数
    字依次表示学号为j-1的学生的语文、数学、英语的成绩。
    每个学生的学号按照输入顺序编号为l~n (恰好是输入数据的行号减1)。
    所给的数据都是正确的，不必检验。
**************************************************************************************/

// 思路使用结构体（学号，成绩，总分），结构体数组（学生人数），排序
#include <stdio.h>

struct student{
    int id;
    int score[3];
    int sumScore;
};

int main(){
    int n;
    int i, j;

    scanf("%d", &n);
    struct student students[n];
    struct student temp0;

    for(i = 0; i < n ; i++){
        students[i].id = i + 1;
        scanf("%d %d %d", &students[i].score[0], &students[i].score[1], &students[i].score[2]);
        students[i].sumScore = students[i].score[0] + students[i].score[1] + students[i].score[2];
    }

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - 1 - i; j++){
            if(students[j].sumScore < students[j + 1].sumScore){
                temp0 = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp0;
            }
            else if(students[j].sumScore == students[j + 1].sumScore){
                if(students[j].score[0] < students[j + 1].score[0]){
                    temp0 = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp0;
                }
                else if(students[j].score[0] == students[j + 1].score[0]){
                    if(students[j].id > students[j + 1].id){
                        temp0 = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp0;
                    }
                }
            }
        }
    }

    for(i = 0; i < 5; i++){
        printf("%d %d\n", students[i].id, students[i].sumScore);
    }
    return 0;
}