//
// Created by LinSihan on 2019/11/29.
//
/*************************************
    题目描述
    Description
         B      DEF
    A + --- + ------- = 10
         C      GHI

    这个算式中A~I代表1~9的数字，
    不同的字母代表不同的数字。
    比如：
    6+8/3+952/714 就是一种解法，
    5+3/1+972/486 是另一种解法。
    这个算式一共有多少种解法？
    限时：1000s
    空间：65536K
************************************/

#include <stdio.h>

int main(){
    int A, B, C, D, E, F, G, H, I;
    int count = 0;

    for(A = 1; A <= 9.0; A++){
        for(B = 1; B <= 9; B++){
            if(B == A){
                continue;
            }
            for(C = 1; C <= 9; C++){
                if(C == A || C == B){
                    continue;
                }
                for(D = 1; D <= 9; D++){
                    if(D == A || D == B ||
                    D == C){
                        continue;
                    }
                    for(E = 1; E <= 9; E++){
                        if(E == A || E == B ||
                           E == C || E == D){
                            continue;
                        }
                        for(F = 1;  F <= 9; F++){
                            if(F == A || F == B ||
                               F == C || F == D ||
                               F == E){
                                continue;
                            }
                            for(G = 1;  G <= 9; G++){
                                if(G == A || G == B ||
                                   G == C || G == D ||
                                   G == E || G == F){
                                    continue;
                                }
                                for(H = 1;  H <= 9; H++){
                                    if(H == A || H == B ||
                                       H == C || H == D ||
                                       H == E || H == F ||
                                       H == G){
                                        continue;
                                    }
                                    for(I = 1;  I <= 9; I++){
                                        if(I == A || I == B ||
                                           I == C || I == D ||
                                           I == E || I == F ||
                                           I == G || I == H){
                                            continue;
                                        }
                                        if((A + ((double)B/(double)C) +
                                        (((double)D*100 + (double)E*10 + (double )F)/((double)G*100 + (double)H*10 +(double)I))) == 10.0){
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
