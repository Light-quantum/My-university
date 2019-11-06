//
// Created by LinSihan on 2019/11/2.
//
/**********************************************************
对于每组数据，输出1/(n^2)+1/((n+1)^2)+...+1/(m^2)，保留5位小数
 输入：0 0结束
 输出：结果
 *********************************************************/

#include <stdio.h>
int main(){
    long double m, n, i, sum;
    int j = 1;
    while(scanf("%Lf %Lf", &n, &m), n != 0 || m != 0){
        sum = 0;
        for(i = n; i <= m; i++){
            sum = sum + 1.0 / (i * i);
        }
        printf("Case %d: %.5Lf\n", j, sum);
        j++;
    }
}