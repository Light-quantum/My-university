//
// Created by LinSihan on 2019/12/27.
//
/* *******************************************************
    题目描述
    Description
    有4个互不相同的数字，输出由其中三个不重复数字组成的排列。
    输出顺序是固定的，输出顺序如样例所示。
    输入描述
    Input
    4个整数。
    输出描述
    Output
    所有排列。
********************************************************/

#include <stdio.h>

void swap(int list[], int q, int p); // 特殊的交换函数
void permutation(int list[], int k, int m);  // 全排列函数
int main(){
    int list[4] = {0};
    int useList[3] = {0};
    int i;
    scanf("%d %d %d %d", &list[0], &list[1], &list[2], &list[3]);

    useList[0] = list[0];
    useList[1] = list[1];
    useList[2] = list[2];
    permutation(useList, 0, 2);

    useList[0] = list[0];
    useList[1] = list[1];
    useList[2] = list[3];
    permutation(useList, 0, 2);

    useList[0] = list[0];
    useList[1] = list[2];
    useList[2] = list[3];
    permutation(useList, 0, 2);

    useList[0] = list[1];
    useList[1] = list[2];
    useList[2] = list[3];
    permutation(useList, 0, 2);
    return 0;
}

void swap(int list[], int q, int p){  // 交换 123 第0位和第2位交换 ==> 结果：312
    int temp;
    int i;
    temp = list[q];
    for(i = q; i > p; i--){
        list[i] = list[i - 1];
    }
    list[p] = temp;
}

void permutation(int list[], int k, int m){ // 全排列函数， k为层数，m为全排列个数
    int i, j;
    if(k == m){
        for(i = 0; i <= m; i ++){
            printf("%d ", list[i]);
        }
        printf("\n");
    }
    else{
        for(j = k; j <= m; j++){
            swap(list, j, k);
            permutation(list, k+1, m);
            swap(list, j, k);  // 还原数组
        }
    }
}

/*全排列算法， 例如 1 2 3
    第0层： 第0位与第0位交换，                      第0位与第1位交换，                         第0位与第2位交换
            123                                   213                                       312
    第1层： 第1位与第1位交换， 第1位与第2位交换       第1位与第1位交换， 第1位与第2位交换         第1位与第1位交换， 第1位与第2位交换
            123              132                  213               231                     312             321
    第2层： 打印
*/
