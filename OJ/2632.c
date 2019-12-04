//
// Created by LinSihan on 2019/11/14.
//
/************************************************************************
    syz有一天决定要当一次主席(其实是GPNU ACM协会会长)。
    要当上并不容易，他需要半数以上的票才能成功当选。
    然而并没有一个人认识他……
    不过投票的人是贪婪的，只要syz给他 ci 1≤ci≤106  块钱，
    他就会选择投他一票。为了成功当选，他至少要花多少钱呢？
    输入描述
    Input
    第一行包含一个整数 n 1 ≤n ≤5000 — 表示投票的人的数量。

    第二行有n 个整数 c1,c2,…,cn1≤ci≤106 — ci 表示贿赂第i 个投票的人需要的钱。
    输出描述
    Output
    输出syz成功当选至少需要的钱的数量。
************************************************************************/
//思路：将贿赂受贿人需要的钱进行排序，选择前一半，加起来
#include <stdio.h>
int main(){
    int n, i, j, temp;
    int everyoneNeedMoney[5000] = {0};

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &everyoneNeedMoney[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (everyoneNeedMoney[j] > everyoneNeedMoney[j + 1]) {
                temp = everyoneNeedMoney[j + 1];
                everyoneNeedMoney[j + 1] = everyoneNeedMoney[j];
                everyoneNeedMoney[j] = temp;
            }
        }
    }

    long long sum = 0;
    for(i = 0; i < n / 2 + 1; i++){
        sum += everyoneNeedMoney[i];
    }
    printf("%lld", sum);
    return 0;
}