//
// Created by LinSihan on 2019/12/11.
//
/* *****************************************************************************
    金明今天很开心，家里购置的新房就要领钥匙了，
    新房里有一间他自己专用的很宽敞的房间。
    更让他高兴的是，妈妈昨天对他说：
    “你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过N元钱就行”。
    今天一早金明就开始做预算，但是他想买的东西太多了，肯定会超过妈妈限定的N元。
    于是，他把每件物品规定了一个重要度，分为5等：用整数1~5表示，第5等最重要。
    他还从因特网上查到了每件物品的价格（都是整数元）。
    他希望在不超过N元（可以等于N元）的前提下，使每件物品的价格与重要度的乘积的总和最大。
    设第j件物品的价格为v[j]，重要度为w[j]，共选中了k件物品，编号依次为j1，j2，……，jk，
    则所求的总和为：
    v[j1]*w[j1]+v[j2]*w[j2]+ …+v[jk]*w[jk]。（其中*为乘号）
    请你帮助金明设计一个满足要求的购物单。
******************************************************************************/

#include <stdio.h>

struct commodity{
    int price;
    int weight;
    int value;
};

int main(){
    struct commodity shopping_list[25] = {{0, 0, 0}};
    int allMoney, num_of_want_have;
    int i;

    scanf("%d %d", &allMoney, &num_of_want_have);
    for(i = 0; i < num_of_want_have; i++){
        scanf("%d %d", &shopping_list[i].price, &shopping_list[i].weight);
        shopping_list[0].value = shopping_list[i].price * shopping_list[i].weight;
    }

    int sumMoney = 0;
    int sumValue = 0;
    int max = shopping_list[0].value;
    int maxi = 0;

    while(sumMoney < allMoney){
        maxi = 0;
        max = shopping_list[0].value;
        for(i = 1; i < num_of_want_have; i++){
            if(shopping_list[i].value > max){
                max = shopping_list[i].value;
                maxi = i;
            }
        }
        sumValue += max;
        sumMoney += shopping_list[maxi].price;
        shopping_list[maxi].value = 0;
    }

    printf("%d\n", sumValue);
}