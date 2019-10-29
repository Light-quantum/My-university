// Created by LinSihan on 2019/10/26.
/***************
 * 三角形问题
 **************/

#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a+b>c && a+c>b && b+c>a){
        if(a*a == b*b+c*c || b*b == a*a + c*c || c*c == a*a + b*b){
           printf("yes");
        }
         else{
             printf("no");
         }
    }
    else{
        printf("not a triangle");
    }
    return 0;

}