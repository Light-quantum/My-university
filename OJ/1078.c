// Created by LinSihan on 2019/10/27.
/****************************
 * 矩阵对角线上元素之和
 * 用二维数组然后取[1][1], [2][2]
 ***************************/

#include <stdio.h>
int main(){
    int N, i, j;
    scanf("%d", &N);
    
    int list[N][N];
    
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &list[i][j]);
        }
    }

    int a = 0, b = 0, c = 0, sum = 0;
    for(i = 0, j = 0; i < N && j < N; i++, j++){
        a = list[i][j];
        b = list[i][N-1-j];
        if(i == (N-1)/2 && j == (N-1)/2 && (N-1)%2 == 0){  // 注意偶数矩阵
            c = list[i][j];
        }
        sum += a + b;
    }
    printf("%d", sum - c);
    return 0;
}
