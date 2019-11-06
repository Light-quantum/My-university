//
// Created by LinSihan on 2019/11/3.
//
/*****************************************************************************
    题目描述
    Description
    Fans是个ACM程序设计迷。有时侯，他表现出很强烈的逆反心理，你往东，他往西，你往南，他偏往北。
    这一次，不知道又是谁惹着他了，好端端的一个个01串，到了他的手里，都变成10串了。
    请你编个程序来模仿他的行为，将01串（长度≤200），全变成10串吧。
    输入描述
    Input
    0110100100100 1000000010000000000
    输出描述
    Output
    1001011011011 0111111101111111111
***************************************************************************************/

#include <stdio.h>
#include <string.h>
/*  垃圾算法，输入字符串时不要一个一个字符输入，会出错
int main(){
    char list[200];
    int i = 0;
    while(scanf("%c", &list[0]) != EOF) {
        for (i = 1; scanf("%c", &list[i]), list[i] != '\n'; i++);
        list[i] = '\0';
        for(i = 0; i < strlen(list); i++){
            if (list[i] == '\n') {
                continue;
            }
            else if (list[i] == '0') {
                list[i] = '1';
            }
            else {
                list[i] = '0';
            }
        }

        for(i = 0; i < strlen(list); i++){
            if(list[i] != '\n'){
                printf("%c", list[i]);
            }
            else{
                continue;
            }
        }
        printf("\n");

        for(i = 0; i < 200; i++){
            list[i] = '\0';
        }
    }
    return 0;
}
 */

int main(){
    int i;
    char num[200];

    while(scanf("%s", num) != EOF){
        for(i = 0; i < strlen(num); i++){
            if (num[i] == '0') {
                num[i] = '1';
            }
            else {
                num[i] = '0';
            }
        }
        puts(num);
    }
    return 0;
}