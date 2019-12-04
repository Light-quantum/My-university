//
// Created by LinSihan on 2019/11/10.
//
// 1026 变式

#include <stdio.h>
int main() {
    int n, i, j, k = 1, different;


    //输入
    while (scanf("%d", &n), n != 0) {
        k = 1;
        int list[1000] = {-1};
        int result[1000] = {-1};
        for (i = 0; i < n; i++) {
            scanf("%d", &list[i]);
        }

        //去重
        for (i = 0; i < n; i++) {
            different = 1;
            for (j = 0; j < k; j++) {
                if (list[i] == result[j]) {  //list[0] = 1
                    different = 0;
                    break;
                }
                else {
                    continue;
                }
            }
            if (different == 1) {
                result[k - 1] = list[i];
                k++;
            }
            else {
                continue;
            }
        }

        //计算个数
        int count = 0;
        for (i = 0; result[i] != 0; i++) {
            count++;
        }

        //排序
        int temp;
        for (i = 0; i < count - 1; i++) {
            for (j = 0; j < count - 1 - i; j++) {
                if (result[j] > result[j + 1]) {
                    temp = result[j + 1];
                    result[j + 1] = result[j];
                    result[j] = temp;
                }
            }
        }

        //输出
        printf("%d\n", count);
        for (i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n\n");
    }
}