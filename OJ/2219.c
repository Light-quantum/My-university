//
// Created by LinSihan on 2019/12/5.
//
/******************************************************************************
    题目描述
    Description
    墨墨购买了一套N支彩色画笔（其中有些颜色可能相同），摆成一排，你需要回答墨墨的提问。
    墨墨会像你发布如下指令：
    1、 Q L R代表询问你从第L支画笔到第R支画笔中共有几种不同颜色的画笔。
    2、 R P Col 把第P支画笔替换为颜色Col。为了满足墨墨的要求，你知道你需要干什么了吗？
    输入描述
    Input
    第1行两个整数N，M，分别代表初始画笔的数量以及墨墨会做的事情的个数。
    第2行N个整数，分别代表初始画笔排中第i支画笔的颜色。
    第3行到第2+M行，每行分别代表墨墨会做的一件事情，格式见题干部分。
    输出描述
    Output
    对于每一个Query的询问，你需要在对应的行中给出一个数字，
    代表第L支画笔到第R支画笔中共有几种不同颜色的画笔。
******************************************************************************/

#include <stdio.h>
void changeColor(int L, int Col, int penColor[]);
int countNumOfColor(const int penColor[], int n, int L, int R);
struct event{
    char order;
    int L;
    int RorCol;
};
int main(){
    int n, m; // n只笔， m件事情
    int i;
    struct event event1;

    scanf("%d %d", &n, &m);
    int penColor[n + 1];

    for(i = 0; i < n; i++){
        scanf("%d", &penColor[i]);
    }
    getchar();
    while(m--){
        scanf("%c", &event1.order);
        scanf("%d %d", &event1.L, &event1.RorCol);
        getchar();
        if(event1.order == 'Q'){
            printf("%d\n", countNumOfColor(penColor, n, event1.L, event1.RorCol));
        }
        else{
            changeColor(event1.L, event1.RorCol, penColor);
        }
    }
}


void changeColor(int L, int Col, int penColor[]){
    penColor[L - 1] = Col;
}

int countNumOfColor(const int penColor[], int n, int L, int R){
    int count = 0;
    int differentColor[n];
    int i, j, isDifferent = 1;
    for(i = L - 1; i < R; i++){
        isDifferent = 1;
        if(i == L - 1){
            differentColor[count] = penColor[i];
            count++;
        }
        else{
            for(j = 0; j < count; j++){
                if(penColor[i] == differentColor[j]){
                    isDifferent = 0;
                    break;
                }
            }
            if(isDifferent == 1){
                differentColor[count] = penColor[i];
                count++;
            }
        }
    }
    return count;
}

