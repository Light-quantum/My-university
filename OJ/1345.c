//
// Created by LinSihan on 2019/11/14.
//
/*******************************************************************
    题目描述
    Description
    如果一个字符串可以由某个长度为k的字符串重复多次得到，则称该串以k为周期。
    例如，abcabcabcabc以3为周期（注意，它也以6和12为周期）。
    输入一个长度不超过100的字符串，输出其最小周期。
    输入描述
    Input
    第一行输入一个整数T，接下来有T行，每行输入一个长度不超过100的字符串
    输出描述
    Output
    对于每个字符串，输出其最小周期
*******************************************************************/

#include <stdio.h>
#include <string.h>
// 思路 复制n个元素和n到2n个元素进行对比，如果相同 且 2n 与 4n也相同 则周期为n
int main(){
    char string[101] = "\0";
    char cycleStr1[101] = "\0";
    char cycleStr2[101] = "\0";
    int T, n, ret, i, j, k, len;

    scanf("%d", &n);
    while(n--){
        scanf("%s", string);
        T = 1;
        len = strlen(string);

        while(T < len){
            for(j = 0; j < T; j++){
                cycleStr1[j] = string[j];
            }
            cycleStr1[j] = '\0';
            for(i = 0, j = T; j < 2*T; j++, i++){
                cycleStr2[i] = string[j];
            }
            cycleStr2[i] = '\0';
            ret = strcmp(cycleStr1, cycleStr2);

            if(ret == 0) {
                if (len % T != 0){  //长度非周期倍数，肯定T不是周期
                    T++;
                    continue;
                }
                else{
                    for(k = 2*T; (k <= len - 2*T) && (ret == 0); k = k + 2*T){

                        for(i = 0, j = k; j < k + T; j++, i++){
                            cycleStr1[i] = string[j];
                        }
                        cycleStr1[i] = '\0';
                        for(i = 0, j = k + T; j < k + 2*T; j++, i++){
                            cycleStr2[i] = string[j];
                        }
                        cycleStr2[i] = '\0';
                        ret = strcmp(cycleStr1, cycleStr2);
                    }
                    if(ret != 0){
                        T++;
                        continue;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                T++;
                continue;
            }
        }
        printf("%d\n", T);
    }
    return 0;
}