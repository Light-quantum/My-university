//
// Created by LinSihan on 2019/11/10.
//
//
//1105
//1170
/*********************************************************************
    题目描述
    Description
    明明想在学校中请一些同学一起做一项问卷调查，
    为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤100），
    对于其中重复的数字，只保留一个，
    把其余相同的数去掉，不同的数对应着不同的学生的学号。
    然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
    请你协助明明完成“去重”与“排序”的工作。
    输入描述
    Input
    输入文件random.in 有2行，第1行为1个正整数，表示所生成的随机数的个数：
    N
    第2行有N个用空格隔开的正整数，为所产生的随机数。
    输出描述
    Output
    输出文件random.out 也是2行，
    第1行为1个正整数M，表示不相同的随机数的个数。
    第2行为M个用空格隔开的正整数，为从小到大排好序的不相同的随机数。
*********************************************************************/

#include <stdio.h>
int main(){
    int n, i, j, k = 1, different;
    int list[1000] = {-1};
    int result[1000] = {-1};

    //输入
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &list[i]);
    }

    //去重
    for(i = 0; i < n; i++) {
        different = 1;
        for (j = 0; j < k; j++) {
            if (list[i] == result[j]) {
                different = 0;
                break;
            }
            else{
                continue;
            }
        }
        if(different == 1){
            result[k - 1] = list[i];
            k++;
        }
        else{
            continue;
        }
    }

    //计算个数
    int count = 0;
    for(i = 0; result[i] != 0; i++ ){
        count++;
    }

    //排序
    int temp;
    for(i = 0; i < count - 1; i++){
        for(j = 0; j < count - 1 - i; j++){
            if(result[j] > result[j + 1]){
                temp = result[j + 1];
                result[j + 1] = result[j];
                result[j] = temp;
            }
        }
    }

    //输出
    printf("%d\n", count);
    for(i = 0; i < count; i++){
        printf("%d ", result[i]);
    }
}