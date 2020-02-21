//
// Created by LinSihan on 2019/12/9.
//
/*************************************************
    题目描述
    Description
    组合数的计算虽说简单但也不乏有些陷阱，
    这主要是因为语言中的数据类型在表示范围上是有限的。
    更何况还有中间结果溢出的现象，所以千万要小心。
    输入描述
    Input
    求组合数的数据都是成对（M与N）出现的，
    每对整数M和N满足0＜m, n≤20，以EOF结束。
    输出描述
    Output
    输出该组合数。每个组合数换行。
*************************************************/
#include <stdio.h>
long long factorial(int n, int the_end){
    int i = 1;
    long long sum = 1;
    for(i = the_end; i <= n; i++){
        sum *= i;
    }
    return sum;
}
long long the_different_factorial(int n, int time){
    int i = 1;
    int j = 1;
    long long sum = 1;
    for(i = n; j <= time; i--){
        sum *= i;
        j++;
    }
    return sum;
}

long long get_combinatorial_number(int n, int m){
    if(m > n / 2){
        m = n - m;
    }
    return ( the_different_factorial(n, m) / factorial(m, 1));
}

int main(){
    int n, m;
    long long combinatorial_number;

    while(scanf("%d %d", &n, &m) != EOF){
        combinatorial_number = get_combinatorial_number(n, m);
        printf("%lld\n", combinatorial_number);
    }
    return 0;
}