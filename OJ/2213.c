//
// Created by LinSihan on 2019/12/11.
//
/***********************************************************************
    题目描述
    Description
    小俞同学，最近勤学苦练数学，对一种数表产生了兴趣。
    数表如下：
    1/1 1/2 1/3 1/4 1/5
    2/1 2/2 2/3 2/4
    3/1 3/2 3/3
    4/1 4/2
    5/1
    她冥思苦相了好久，貌似摸到了一点规律，
    但是她不知道自己的规律找的对不对，所以需要你来写一个程序来判断。
    她的想法：
    第一项：1/1
    第二项：1/2
    第三项: 2/1
    第四项：3/1
    第五项：2/2.
    ……
***********************************************************************/

// 思路： 其实就是一个斜着的三角形，然后一行一行扫描
#include <stdio.h>

int get_line(int n, int *place);
int main(){
    int n, place_of_line = 0, *place = &place_of_line;

    while(scanf("%d", &n) != EOF) {
        place_of_line = 0;
        place = &place_of_line;
        int line = get_line(n, place);

        if (line % 2 == 0) {
            printf("%d/%d\n", 1 + (*place - 1), line - (*place - 1));
        } else {
            printf("%d/%d\n", line - (*place - 1), 1 + (*place - 1));
        }
    }
    return 0;
}



int get_line(int n, int *place){
    int sum = 1;
    int i;

    for(i = 2; 1; i++){
        sum += i;
        if(n <= sum){
            *place = (n - (sum - i));   // 等于 0 为行末
            return i;
        }
    }
}