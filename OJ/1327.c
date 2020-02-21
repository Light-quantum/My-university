//
// Created by LinSihan on 2019/12/8.
//
/**********************************************************************
    题目描述
    Description
    As a student in SCUT, Xiao Ming has a very good student
    id: SCUT2B0001. And his friend,
    Da Ming, just has a next id: SCUT2B0002.

    Well, now, give you a student id, can you calculate the next one?
    输入描述
    Input
    Each line will contain a student id,
    and it contains only letters or digits.
    Assume the length of student id is between 1 and 200.
    输出描述
    Output
    For each case, output the next student id in one line.
********************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    char ID[202] = "\0";
    char number[202] = "\0";
    int len;
    int i, j;
    int carry;

    while(scanf("%s", ID) != EOF){
        i = 0;
        j = 0;
        carry = 1;
        len = strlen(ID);
        for(i = 0; i < len; i++){
            if(ID[i] >= '0' && ID[i] <= '9'){
                number[j] = ID[i];
                j++;
            }
            else{
                memset(number, '\0', sizeof(number));
                j = 0;
            }
        }
        if(j == 0){
            printf("%s1\n", ID);
        }
        else{
            for(i = j - 1; i >= 0; i--){
                number[i] = number[i] + carry;
                carry = 0;
                if(number[i] > '9'){
                    carry = 1;
                    number[i] = '0';
                }
            }
            if(carry == 1){
                for(i = 0; i < len - j; i++){
                    printf("%c", ID[i]);
                }
                printf("1");
                printf("%s\n", number);
            }
            else{
                for(i = 0; i < len - j; i++){
                    printf("%c", ID[i]);
                }
                printf("%s\n", number);
            }
        }
        memset(number, '\0', sizeof(number));
    }
    return 0;
}