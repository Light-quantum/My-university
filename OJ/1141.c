//
// Created by LinSihan on 2019/11/14.
//
/****************************************************************************
    题目描述
    Description
    若一个数（首位不为0）从左到右读与从右到左读都是一样，
    这个数就叫做回文数，例如12521就是一个回文数。
    给定一个正整数，把它的每一个位上的数字倒过来排列组成一个新数，然后与原数相加，
    如果是回文数则停止，
    如果不是，则重复这个操作，直到和为回文数为止。
    给定的数本身不为回文数。
    例如：87则有：
    STEP1: 87+78=165
    STEP2: 165+561=726
    STEP3: 726+627=1353
    STEP4: 1353+3531=4884
    编写一个程序，输入M（12<=M<=100）,输出最少经过几步可以得到回文数。
    如果在8步以内（含8步）不可能得到回文数，则输出0。
    输入描述
    Input
    第1行一个正整数L,代表测试数据的组数。
    接下来L行每行一个整数M（12<=M<=100），M本身不为回文数；
    输出描述
    Output
    输出L行，第i行对应输入数据的第i+1行，输出最少需要的步数；如果步数大于8，则输出0。
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>

void num_turn_to_str(int temp, char list[]){
    int i = 0;
    while(1){
        list[i] = temp % 10 + '0';
        temp = temp / 10;
        i++;
        if(temp == 0){
            break;
        }
    }
    list[i] = '\0';
}

int main(){
    int k, i, j, n, num, tempNum;
    int len, isPalindromicNum;
    char list[100] = "\0";

    scanf("%d", &n);
    while(n--){
        scanf("%d", &num);
        for(k = 1; k <= 8; k++){
            num_turn_to_str(num, list);
            len = strlen(list);
            isPalindromicNum = 1;
            for(j = 0; j < len; j++){
                if(list[j] != list[len - 1 - j]){
                    isPalindromicNum = 0;
                    break;
                }
            }
            if(isPalindromicNum == 1){
                break;
            }
            else{
                tempNum = 0;
                j = len - 1;
                for(i = 0; i < len; i++, j--){
                    tempNum = tempNum + (list[i] - '0') * pow(10, j);
                }
                num = num + tempNum;
            }
        }
        if(k == 9){
            printf("0\n");
        }
        else{
            printf("%d\n", k-1);
        }
    }
    return 0;
}