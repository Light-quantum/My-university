//
// Created by LinSihan on 2019/11/15.
//

/*************************************************************************
    题目描述
    Description
    某侦察队接到一项紧急任务，要求在A、B、C、D、E、F六个队员中尽可能多地挑若干人，
    但有以下限制条件：
    1)A和B两人中至少去一人；
    2)A和D不能一起去；
    3)A、E和F三人中要派两人去；
    4)B和C都去或都不去；
    5)C和D两人中去一个；
    6)若D不去，则E也不去。
    问应当让哪几个人去？
    输入描述
    Input
    无
    输出描述
    Output
    要派出的人
    若有多个，按字母递增顺序排列，用逗号分开（含末尾逗号）
****************************************************************************/

#include <stdio.h>
int main() {
    int list[6] = {0};
    int num = 0;
    for(list[0] = 0; list[0] <= 1; list[0]++){
        for(list[1] = 0; list[1] <= 1; list[1]++){
            if(list[0] == 0 && list[1] == 0){
                continue;
            }
            else{
                if(list[0] == 1){
                    list[3] = 0;
                }
                if()
            }
        }
    }

}
/*

#include <stdio.h>
int main(){
    printf("A,B,C,F,\n");
    return 0;
}
*/