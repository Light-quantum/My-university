//
// Created by LinSihan on 2019/12/22.
//
/* **********************************************
    求仰角增加速率
***********************************************/
#include <stdio.h>
#include <math.h>
int main(){
    int T;
    int V, H, L;
    double V_angleAdd;

    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &V, &H, &L);
        V_angleAdd = ((V*1.0) / (L * 1.0)) / (1 + ((H *1.0)/L) * ((H * 1.0) / L));
        printf("%.3lf\n", V_angleAdd);
    }
    return 0;
}