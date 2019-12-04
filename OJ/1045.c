//
// Created by LinSihan on 2019/11/14.
//
/*******************************************************************************
    题目描述
    Description
    CC同学刚从美国回来，发现手上还有一些未用完的美金，于是想去银行兑换成人民币。
    可是听说最近人民币将会升值，并从金融机构得到了接下来十二个月可能的美元对人民币汇率，
    现在，CC想要在接下来一年中把美金都兑换成人民币，请问最多能得到多少人民币？
    输入描述
    Input
    第一行一个实数D（1.00<=D<=100.00），表示CC现有的美金数量。
    接下来一行，包含12个实数ai(5.00<=ai<=7.00)，表示接下来十二个月的美元对人民币汇率。
    输出描述
    Output
    输出一个小数R，表示CC最多能获得的人民币数量，保留两位小数。
 *****************************************************************************/

#include <stdio.h>
int main(){
    double exchangeRate[12] = {0};
    double sum, max;
    int i;

    scanf("%lf", &sum);
    for(i = 0; i < 12; i++){
        scanf("%lf", &exchangeRate[i]);
    }

    max = exchangeRate[0];
    for(i = 1; i < 12; i++){
        if(exchangeRate[i] > max){
            max = exchangeRate[i];
        }
    }

    printf("%.2lf", sum * max);
    return 0;
}