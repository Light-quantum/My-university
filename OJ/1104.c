//
// Created by LinSihan on 2019/12/3.
//
/***********************************************************************
    题目描述
    Description
    已知元素从小到大排列的两个数组x[]和y[]，
    请写出一个程序算出两个数组彼此之间差的绝对值中最小的一个，这叫做数组的距离
    输入描述
    Input
    第一行为两个整数m, n(1≤m, n≤1000)，分别代表数组f[], g[]的长度。
    第二行有m个元素，为数组f[]。
    第三行有n个元素，为数组g[]。
    输出描述
    Output
    数组的最短距离
***********************************************************************/

#include <stdio.h>
int getMaxInList(int list[], int n);
int getMinInList(int list[], int n);
int main(){
    int m, n;
    int distance1, distance2;
    int result;
    int list_m[1001] = {0};
    int list_n[1001] = {0};
    int i;
    int max_of_list_m, max_of_list_n;
    int min_of_list_m, min_of_list_n;

    scanf("%d %d", &m, &n);
    for(i = 0; i < m; i++){
        scanf("%d", &list_m[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d", &list_n[i]);
    }

    max_of_list_m = getMaxInList(list_m, m);
    max_of_list_n = getMaxInList(list_n, n);
    min_of_list_m = getMinInList(list_m, m);
    min_of_list_n = getMinInList(list_n, n);
    if(max_of_list_m < min_of_list_n || max_of_list_n < min_of_list_m) {
        distance1 = max_of_list_m - min_of_list_n;
        distance2 = max_of_list_n - min_of_list_m;

        if (distance1 < distance2) {
            result = distance1;
        } else {
            result = distance2;
        }

        result = (result < 0 ? -result : result);
        printf("%d\n", result);
    }
    else{
        printf("0\n");
    }
}

int getMaxInList(int list[], int n){
    int i;
    int max;

    max = list[0];
    for(i = 1; i < n; i++){
        if(list[i] > max){
            max = list[i];
        }
    }
    return max;
}

int getMinInList(int list[], int n){
    int i;
    int min;

    min = list[0];
    for(i = 1; i < n; i++){
        if(list[i] < min){
            min = list[i];
        }
    }
    return min;
}