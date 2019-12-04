//
// Created by LinSihan on 2019/11/10.
//

#include <stdio.h>

int main(){
    int n, k1, i;
    int list[9] = {0};
    int result[9] = {0};

    scanf("%d", &n);
    while(n--) {
        for (i = 0; i < 9; i++) {
            scanf("%d", &list[i]);
        }
        k1 = list[0];

        int count = 0;
        for(i = 1; i < 9; i++){
            if(list[i] < k1){
                count++;
            }
        }

        int j = 1, t = 1;
        result[count] = k1;
        for(i = 1; i < 9; i++){
            if(list[i] > k1) {
                result[count + j] = list[i];
                j++;
            }
            else{
                result[count - t] = list[i];
                t++;
            }
        }

        for(i = 0; i < 9; i++){
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    return 0;
}