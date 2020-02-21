//
// Created by LinSihan on 2019/12/6.
//
/*********************************************************************************
    题目描述
    Description
    生命游戏是英国数学家约翰·何顿·康威在1970年发明的细胞自动机
    生命游戏其实是一个零玩家游戏，它包括一个二维矩形世界，
    这个世界中的每个方格居住着一个活着的或死了的细胞。
    一个细胞在下一个时刻生死取决于相邻八个方格中活着的或死了的细胞的数量。
    如果相邻方格活着的细胞数量过多，这个细胞会因为资源匮乏而在下一个时刻死去；
    相反，如果周围活细胞过少，这个细胞会因太孤单而死去。
    这是一个10*10的表盘，但实际上他是一个球面，所以每一个细胞周围都有且仅有8个细胞，
    你应该想象这个表盘围成一个球的样子。
    一定要看的规则：
    1． 如果一个细胞周围有3个细胞为生，则该细胞为生
    （即该细胞若原先为死，则转为生，若原先为生，则保持不变） 。
    2． 如果一个细胞周围有2个细胞为生，则该细胞的生死状态保持不变
    3． 在其它情况下，该细胞为死
    （即该细胞若原先为生，则转为死，若原先为死，则保持不变）
    初始表盘如下（即n = 0 的情况）：
    ..........
    ..........
    ..........
    ..###.....
    ..#.#.....
    ..###.....
    ...#......
    ..........
    ..........
    ..........
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void getTheFirstWorld(char theWorld[10][10]);
void getNextWorld(char theBeforeWorld[10][10], char theNextWorld[10][10]);
struct World{
    char world[10][10];
};
int main(){
    struct World theWorld[1000] = {{'0'}};
    getTheFirstWorld(theWorld[0].world);

    int i, j, n;

    for(i = 1; i <= 1000; i++){
        getNextWorld(theWorld[i - 1].world, theWorld[i].world);
    }

    while(scanf("%d", &n) != EOF){
        printf("%d\n", n);
        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                printf("%c", theWorld[n].world[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

void getTheFirstWorld(char theWorld[10][10]){
    int i, j;

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(i == 3 || i == 5){
                if(j >= 2 && j <= 4){
                    theWorld[i][j] = '#';
                }
                else{
                    theWorld[i][j] = '.';
                }
            }
            else if(i == 4){
                if(j == 2 || j == 4){
                    theWorld[i][j] = '#';
                }
                else{
                    theWorld[i][j] = '.';
                }
            }
            else if(i == 6){
                if(j == 3){
                    theWorld[i][j] = '#';
                }
                else{
                    theWorld[i][j] = '.';
                }
            }
            else{
                theWorld[i][j] = '.';
            }
        }
    }
}

void getNextWorld(char theBeforeWorld[10][10], char theNextWorld[10][10]){
    int i, j;
    int count = 0;
    int k1, k2;

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            count = 0;
            for(k1 = i - 1; k1 <= i + 1; k1++){
                for(k2 = j - 1; k2 <= j + 1; k2++){
                    if((k1 >= 0 && k1 < 10) && (k2 >= 0 && k2 < 10)){
                        if(k1 == i && k2 == j){
                            continue;
                        }
                        else if(theBeforeWorld[k1][k2] == '#'){
                            count++;
                        }
                    }
                    else if((k1 < 0) && (k2 >= 0 && k2 < 10)){
                        if(k1 == i && k2 == j){
                            continue;
                        }
                        else if(theBeforeWorld[9][9-k2] == '#'){
                            count++;
                        }
                    }
                    else if((k1 >= 0 && k1 < 10) && (k2 < 0)){
                        if(k1 == i && k2 == j){
                            continue;
                        }
                        else if(theBeforeWorld[9 - k1][9] == '#'){
                            count++;
                        }
                    }
                    else if((k1 < 0) && (k2 < 0)) {
                        if (k1 == i && k2 == j) {
                            continue;
                        }
                        else if (theBeforeWorld[9][9] == '#') {
                            count++;
                        }
                    }
                    else if((k1 >= 10) && (k2 >= 0 && k2 < 10)){
                        if(k1 == i && k2 == j){
                            continue;
                        }
                        else if(theBeforeWorld[0][9 - k2] == '#'){
                            count++;
                        }
                    }
                    else if((k1 >= 0 && k1 < 10) && (k2 >= 10)){
                        if(k1 == i && k2 == j){
                            continue;
                        }
                        else if(theBeforeWorld[9 - k1][0] == '#'){
                            count++;
                        }
                    }
                    else if((k1 >= 10) && (k2 >= 10)) {
                        if (k1 == i && k2 == j) {
                            continue;
                        }
                        else if (theBeforeWorld[0][0] == '#') {
                            count++;
                        }
                    }
                }
            }
            if(count == 3){
                theNextWorld[i][j] = '#';
            }
            else if(count == 2){
                theNextWorld[i][j] = theBeforeWorld[i][j];
            }
            else{
                theNextWorld[i][j] = '.';
            }
        }
    }
}
