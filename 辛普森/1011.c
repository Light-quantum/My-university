//Created by LinSihan on 2019/10/27.
/***************
   级数求和问题
 **************/
#include <stdio.h>
int main (){
    double Sn = 0.0;
    int n, k;
    scanf("%d", &k);
    for (n = 1; Sn <= k; n++){
        Sn = Sn + 1.0 / n;
    }
    printf("%d", n - 1);
    return 0;
}
