//Created by LinSihan on 2019/10/28.
/****************
 * 完全数问题
 ****************/

#include <stdio.h>
int main(){
    int n, i, N;
    int sum;
    scanf("%d", &N);    //找出N（输入）之内的所有完全数
    for (n = 1; n <= N; n++){    //从1开始循环到N
        sum = 0;
        for(i = 1; i < n; i++){    //从1到n，用n去除以每一个数，找出n的因子
            if(n % i == 0){
                sum += i;    //把因子加起来
            }
        }
        if (sum == n){    //判断sum和n是否相等，即n是否为完全数
            printf("%d its factors are", n);    //如何输出6 its factors are 1 2 3
            for(i = 1; i < n; i++){    //先输出前面的，如何不换行，然后循环输出
                if(n % i == 0){
                    printf(" ");    //使得输出的每一个数前有空格隔开
                    printf("%d", i);
                }
            }
            printf("\n");  //循环输出结束换行
        }
    }
    return 0;
}

