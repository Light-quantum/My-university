//
// Created by LinSihan on 2019/11/10.
//
/*************************************************************
    题目描述
    Description
    现有有N个学生的数据记录，每个记录包括学号、姓名、三科成绩。
    编写一个函数input,用来输入一个学生的数据记录。
     编写一个函数print,打印一个学生的数据记录。
     在主函数调用这两个函数，读取N条记录输入，再按要求输出。N
    输入描述
    Input
    学生数量N占一行每个学生的学号、姓名、三科成绩占一行，空格分开。
    输出描述
    Output
    每个学生的学号、姓名、三科成绩占一行，逗号分开。
************************************************************/

#include <stdio.h>
#include <string.h>
int main(){
    int n, m, i;
    char studentsMsg[1000] = "\0";
    scanf("%d\n", &n);

    while(n--){
        gets(studentsMsg);
        m = strlen(studentsMsg);

        for(i = 0; i < m; i++){
            if(studentsMsg[i] == ' '){
                studentsMsg[i] = ',';
            }
        }
        puts(studentsMsg);
    }
    return 0;
}