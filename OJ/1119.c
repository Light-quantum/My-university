//
// Created by LinSihan on 2019/11/17.
//
/**********************************************************
    题目描述
    Description
    公共汽车从始发站(称为第1站)开出,在始发站上车的人数为a,
    然后到达 第2站,在第2站有人上、下车,但上、下车的人数相同，
    因此在第2站开出时（即在到达第3站之前）车上的人数保持为a人。
    从第3站起（包括第3站）上、下 车的人数有一定的规律：
    上车的人数都是前两站上车人数之和，而下车人数等于上一站上车人数，
    一直到终点站的前一站（第n-1站），都满足此规律。
    现给出的 条件是：共有n个车站，始发站上车的人数为a,
    最后一站下车的人数是m（全部下车）。
    试问从x站开出时车上的人数是多少？
    输入描述
    Input
    只有一行，四个整数a,n,m和x
    输出描述
    Output
    x站开出时车上的人数
*************************************************************/

#include <stdio.h>

int main(){
    int the_star_get_on_the_bus_num = 0;
    int the_last_out_of_the_bus_num = 0;
    int out_of_the_bus_num = 0;
    int get_of_the_bus_num = 0;
    int sum_of_station = 0;
    int num_of_station = 0

    scanf("%d %d %d %d",
            &the_star_get_on_the_bus_num,
            &sum_of_station,
            &the_last_out_of_the_bus_num,
            &num_of_station);


}





