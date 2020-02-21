//
// Created by LinSihan on 2019/12/12.
//
/******************************************************************************
    题目描述
    Description
       有一把密码锁，密码为4位数，每一位的数字都是0到9。
       每次可以改变其中一位数为其相邻的数字。
       例如，数字5可以换成4或者6，数字0可以换成1或9，数字9可以换成8或者0，以此类推。
       已知密码锁的正确密码是9394，
       但是它的初始状态每次都不相同，求最少需要转换多少次才能解开密码锁。
    输入描述
    Input
       第一行是一个正整数T(T<=10000)，表示有T组测试数据。
       每组数据的第一行是一个长度为4的字符串，仅包含'0'到'9'，表示密码锁的初始状态。
    输出描述
    Output
        每组数据的答案输出为一行，表示解开密码锁所需的最少转换次数。
******************************************************************************/
// 思路： 判断它往前换还是往后换

#include <stdio.h>

int main(){
    int T, i, count;
    char password[5] = "\0";

    scanf("%d", &T);
    getchar();
    while(T--){
        count = 0;
        scanf("%s", password); // 注意越界问题

        for(i = 0; i < 4; i++){
            if(i == 0 || i == 2){
                if(password[i] <= '4'){
                    count += (password[i] - '0' + 1);
                }
                else{
                    count += ('9' - password[i]);
                }
            }
            else if(i == 1){
                if(password[1] <= '3'){
                    count += ('3' - password[1]);
                }
                else if(password[1] > 3 && password[1] <= '8'){
                    count += (password[1] - '3');
                }
                else{ // password[1] == '9'
                    count += 4;
                }
            }
            else if(i == 3){
                if(password[3] <= '4'){
                    count += ('4' - password[3]);
                }
                else{
                    count += (password[3] - '4');
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}