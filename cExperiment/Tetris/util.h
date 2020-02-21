#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <conio.h>

typedef struct Mycoord{
    int x;
    int y;
}MYCOORD;

typedef struct mod{
    MYCOORD pointOfRotation;
    MYCOORD square1;
    MYCOORD square2;
    MYCOORD square3;
    MYCOORD square4;
    MYCOORD square5;
}MOD;

/* ********************************************
	函数功能：改变光标位置
。。。。。。。。。。。。。。。。。。。。。。。
	输入：x, y
	返回：void
*********************************************/
void gotoxy(int x, int y) {
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, pos);
}

/* ************************************************
   函数功能：初始化各种模块
。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：储存模块的数组
    返回值：void
*************************************************/
void initmod(MOD modList[]){
    // 以下是第 0 种方块
    // 2 为旋转点
    //  1
    //  2 3
    //    4
    modList[0].square1.x = 9;
    modList[0].square1.y = 0;

    modList[0].square2.x = 9;
    modList[0].square2.y = 1;

    modList[0].square3.x = 10;
    modList[0].square3.y = 1;

    modList[0].square4.x = 10;
    modList[0].square4.y = 2;

    //modList[0].pointOfRotation.x = 9;
    //modList[0].pointOfRotation.y = 1;
    modList[0].pointOfRotation = modList[0].square2;

    // 以下是第 1 种方块
    // 5 为旋转点
    //  1
    //  2 5
    //  3 4
    //modList[1].pointOfRotation.x = 10;
    //modList[1].pointOfRotation.y = 1;

    modList[1].square1.x = 9;
    modList[1].square1.y = 0;

    modList[1].square2.x = 9;
    modList[1].square2.y = 1;

    modList[1].square3.x = 9;
    modList[1].square3.y = 2;

    modList[1].square4.x = 10;
    modList[1].square4.y = 2;

    modList[1].square5.x = 10;
    modList[1].square5.y = 1;

    modList[1].pointOfRotation = modList[1].square5;
    // 以下是第 2 种方块
    // 5 为旋转点
    //    1
    //  5 2
    //  4 3
    //modList[2].pointOfRotation.x = 9;
    //modList[2].pointOfRotation.y = 1;

    modList[2].square1.x = 10;
    modList[2].square1.y = 0;

    modList[2].square2.x = 10;
    modList[2].square2.y = 1;

    modList[2].square3.x = 10;
    modList[2].square3.y = 2;

    modList[2].square4.x = 9;
    modList[2].square4.y = 2;

    modList[2].square5.x = 9;
    modList[2].square5.y = 1;

    modList[2].pointOfRotation = modList[2].square2;
    // 以下是第 3 种方块
    // 2 为旋转点
    //    1
    //  4 2
    //    3
    //modList[3].pointOfRotation.x = 10;
    //modList[3].pointOfRotation.y = 1;

    modList[3].square1.x = 10;
    modList[3].square1.y = 0;

    modList[3].square2.x = 10;
    modList[3].square2.y = 1;

    modList[3].square3.x = 10;
    modList[3].square3.y = 2;

    modList[3].square4.x = 9;
    modList[3].square4.y = 1;


    modList[3].pointOfRotation = modList[3].square2;
    // 以下是第 4 种方块
    //  3 为旋转点
    //  1
    //  2
    //  3
    //  4
    //modList[4].pointOfRotation.x = 9;
    //modList[4].pointOfRotation.y = 2;

    modList[4].square1.x = 9;
    modList[4].square1.y = 0;

    modList[4].square2.x = 9;
    modList[4].square2.y = 1;

    modList[4].square3.x = 9;
    modList[4].square3.y = 2;

    modList[4].square4.x = 9;
    modList[4].square4.y = 3;

    modList[4].pointOfRotation = modList[4].square3;
    // 以下是第 5 种方块
    //  4 为旋转点
    //  3  1
    //  4  2
    //modList[5].pointOfRotation.x = 9;
    //modList[5].pointOfRotation.y = 1;

    modList[5].square1.x = 10;
    modList[5].square1.y = 0;

    modList[5].square2.x = 10;
    modList[5].square2.y = 1;

    modList[5].square3.x = 9;
    modList[5].square3.y = 0;

    modList[5].square4.x = 9;
    modList[5].square4.y = 1;

    modList[5].pointOfRotation = modList[5].square4;
}

/* ************************************************
   函数功能：初始化地图
。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：储存地图的二维数组
    返回值：void
*************************************************/
void initmap(char map[30][20]){
    int i, j;
    for(i = 0; i < 30; i++){
        for(j = 0; j < 20; j++){
            if(i != 29){
                if(j == 0 || j == 19){
                    map[i][j] = 219;
                }
                else{
                    map[i][j] = '\0';
                }
            }
            else{
                map[i][j] = 219;
            }
        }
    }
}

/* ************************************************
   函数功能：打印地图
。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：储存地图的二维数组
    返回值：void
*************************************************/
void printmap(char map[30][20]){
    gotoxy(0, 0);
    int i, j;
    for(i = 0; i < 30; i++){
        for(j = 0; j < 20; j++){
            if(map[i][j] == '\0'){
                printf("  ");
            }
            else{
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

/* ************************************************
   函数功能：获得随机模块
。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：void
    返回值：模块类型 0 ~ 5
*************************************************/
int getkindofmod(){
    srand((unsigned)time(0));
    return rand() % 6;
}


/* ************************************************
   函数功能：将模块加载到地图中
。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：地图模块二维数组，类型, 模块类型数组
    返回值：void
*************************************************/
void loadmod(char map[30][20], int kind, MOD modList[]){
    switch(kind){
        case 0:
        case 3:
        case 4:
        case 5:{
            map[modList[kind].square1.y][modList[kind].square1.x] = 219;
            map[modList[kind].square2.y][modList[kind].square2.x] = 219;
            map[modList[kind].square3.y][modList[kind].square3.x] = 219;
            map[modList[kind].square4.y][modList[kind].square4.x] = 219;
            }
            break;
        case 1:
        case 2:{
            map[modList[kind].square1.y][modList[kind].square1.x] = 219;
            map[modList[kind].square2.y][modList[kind].square2.x] = 219;
            map[modList[kind].square3.y][modList[kind].square3.x] = 219;
            map[modList[kind].square4.y][modList[kind].square4.x] = 219;
            map[modList[kind].square5.y][modList[kind].square5.x] = 219;
            }
            break;
    }
}

/* ************************************************
   函数功能：获得当前模块的结构体
。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：类型， 模块数组， 模块的结构体指针
    返回值：void
*************************************************/
void getcurrentmod(int kind, MOD modList[], MOD * currentMod){
    switch(kind){
        case 0:
        case 3:
        case 4:
        case 5:{
            currentMod->square1.x = modList[kind].square1.x;
            currentMod->square1.y = modList[kind].square1.y;

            currentMod->square2.x = modList[kind].square2.x;
            currentMod->square2.y = modList[kind].square2.y;

            currentMod->square3.x = modList[kind].square3.x;
            currentMod->square3.y = modList[kind].square3.y;

            currentMod->square4.x = modList[kind].square4.x;
            currentMod->square4.y = modList[kind].square4.y;

            currentMod->pointOfRotation = modList[kind].pointOfRotation;
        }
            break;
        case 1:
        case 2:{
            currentMod->square1.x = modList[kind].square1.x;
            currentMod->square1.y = modList[kind].square1.y;

            currentMod->square2.x = modList[kind].square2.x;
            currentMod->square2.y = modList[kind].square2.y;

            currentMod->square3.x = modList[kind].square3.x;
            currentMod->square3.y = modList[kind].square3.y;

            currentMod->square4.x = modList[kind].square4.x;
            currentMod->square4.y = modList[kind].square4.y;

            currentMod->square5.x = modList[kind].square5.x;
            currentMod->square5.y = modList[kind].square5.y;

            currentMod->pointOfRotation = modList[kind].pointOfRotation;
        }
            break;
    }
}

/* *******************************************************
   函数功能：自然下落
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：地图模块二维数组，模块类型， 当前模块的结构体指针
    返回值：void
*********************************************************/
// 下落包括清除老痕迹生成新痕迹
void freefall(char map[30][20], int kind, MOD * currentMod){
    int cankeepfall(char map[30][20], int kind, MOD * currentMod);
    switch(kind){
        case 0:
        case 3:
        case 4:
        case 5:{
            if(cankeepfall(map, kind, currentMod)){
                //清楚旧痕迹
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                //下落
                currentMod->square1.y = currentMod->square1.y + 1;
                currentMod->square2.y = currentMod->square2.y + 1;
                currentMod->square3.y = currentMod->square3.y + 1;
                currentMod->square4.y = currentMod->square4.y + 1;
                currentMod->pointOfRotation.y = currentMod->pointOfRotation.y + 1;
                //生成新痕迹
                map[currentMod->square1.y][currentMod->square1.x] = 219;
                map[currentMod->square2.y][currentMod->square2.x] = 219;
                map[currentMod->square3.y][currentMod->square3.x] = 219;
                map[currentMod->square4.y][currentMod->square4.x] = 219;
            }
        }break;
        case 1:
        case 2:{
            if(cankeepfall(map, kind, currentMod)) {
                //清楚旧痕迹
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                map[currentMod->square5.y][currentMod->square5.x] = '\0';
                //下落
                currentMod->square1.y = currentMod->square1.y + 1;
                currentMod->square2.y = currentMod->square2.y + 1;
                currentMod->square3.y = currentMod->square3.y + 1;
                currentMod->square4.y = currentMod->square4.y + 1;
                currentMod->square5.y = currentMod->square5.y + 1;
                currentMod->pointOfRotation.y = currentMod->pointOfRotation.y + 1;
                //生成新痕迹
                map[currentMod->square1.y][currentMod->square1.x] = 219;
                map[currentMod->square2.y][currentMod->square2.x] = 219;
                map[currentMod->square3.y][currentMod->square3.x] = 219;
                map[currentMod->square4.y][currentMod->square4.x] = 219;
                map[currentMod->square5.y][currentMod->square5.x] = 219;
            }
        }break;
    }
}

/* ************************************************
   函数功能：能否继续下落
。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：地图二维数组， 类型， 当前模块的结构体指针
    返回值：布尔，能返回1，不能返回0；
*************************************************/
int cankeepfall(char map[30][20], int kind, MOD * currentMod){
    switch(kind){
        case 0: {
            if (abs((currentMod->square1.y - currentMod->square4.y)) == 2) {
                if(currentMod->square1.y < currentMod->square4.y) {
                    if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square2.y + 1][currentMod->square2.x] == -37) {
                        return 0;
                    }
                }
                else{
                    if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square3.y + 1][currentMod->square3.x] == -37) {
                        return 0;
                    }
                }
            }
            else{
                if(currentMod->square1.y < currentMod->square4.y){
                    if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square3.y + 1][currentMod->square3.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                        return 0;
                    }
                }
                else{
                    if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square2.y + 1][currentMod->square2.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                        return 0;
                    }
                }
            }
        }break;
        case 3:{
            if (abs((currentMod->square1.y - currentMod->square3.y)) == 2) {
                if(currentMod->square1.y < currentMod->square3.y) {
                    if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square3.y + 1][currentMod->square3.x] == -37) {
                        return 0;
                    }
                }
                else{
                    if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                        return 0;
                    }
                }
            }
            else{
                if(currentMod->square2.y < currentMod->square4.y){
                    if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square3.y + 1][currentMod->square3.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                        return 0;
                    }
                }
                else{
                    if (map[currentMod->square3.y + 1][currentMod->square3.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square2.y + 1][currentMod->square2.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                        return 0;
                    }
                }
            }
        }break;
        case 4:{
            if (abs((currentMod->square1.y - currentMod->square4.y)) == 3) {
                if(currentMod->square1.y < currentMod->square4.y) {
                    if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                        return 0;
                    }
                }
                else{
                    if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                        return 0;
                    }
                }
            }
            else{
                if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                    return 0;
                }
                if (map[currentMod->square2.y + 1][currentMod->square2.x] == -37) {
                    return 0;
                }
                if (map[currentMod->square3.y + 1][currentMod->square3.x] == -37) {
                    return 0;
                }
                if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                    return 0;
                }
            }
        }break;
        case 5:{
            if (map[currentMod->square2.y + 1][currentMod->square2.x] == -37) {
                return 0;
            }
            if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                return 0;
            }
        }break;
        case 1:
        case 2:{
            if (abs((currentMod->square1.y - currentMod->square3.y)) == 2) {
                if(currentMod->square1.y < currentMod->square3.y) {
                    if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square3.y + 1][currentMod->square3.x] == -37) {
                        return 0;
                    }
                }
                else{
                    if (map[currentMod->square5.y + 1][currentMod->square5.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                        return 0;
                    }
                }
            }
            else{
                if(currentMod->square2.y < currentMod->square5.y){
                    if (map[currentMod->square4.y + 1][currentMod->square4.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square5.y + 1][currentMod->square5.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                        return 0;
                    }
                }
                else{
                    if (map[currentMod->square3.y + 1][currentMod->square3.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square2.y + 1][currentMod->square2.x] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square1.y + 1][currentMod->square1.x] == -37) {
                        return 0;
                    }
                }
            }
        }break;
    }
    return 1;
}

/* *****************************************************************
   函数功能：左右移动
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：地图二维数组， 类型， 当前模块的结构体指针， 方向键值：A or D
    返回值：void
********************************************************************/
// 思路：很简单，x 的整体加减，但是得防越界和重叠（最左的左边或最右的方块是否有方块）
void move(char map[30][20], int kind, MOD * currentMod, int direction){
    int cankeepmove(char map[30][20], int kind, MOD * currentMod, int direction);
    switch(kind){
        case 0:
        case 3:
        case 4:
        case 5:{
            if(cankeepmove(map, kind, currentMod, direction)) {
                //清除旧痕迹
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                //移动
                if (direction == 'A' || direction == 'a') {
                    currentMod->square1.x = currentMod->square1.x - 1;
                    currentMod->square2.x = currentMod->square2.x - 1;
                    currentMod->square3.x = currentMod->square3.x - 1;
                    currentMod->square4.x = currentMod->square4.x - 1;
                    currentMod->pointOfRotation.x = currentMod->pointOfRotation.x - 1;
                } else if (direction == 'D' || direction == 'd') {
                    currentMod->square1.x = currentMod->square1.x + 1;
                    currentMod->square2.x = currentMod->square2.x + 1;
                    currentMod->square3.x = currentMod->square3.x + 1;
                    currentMod->square4.x = currentMod->square4.x + 1;
                    currentMod->pointOfRotation.x = currentMod->pointOfRotation.x + 1;
                }
                //生成新痕迹
                map[currentMod->square1.y][currentMod->square1.x] = 219;
                map[currentMod->square2.y][currentMod->square2.x] = 219;
                map[currentMod->square3.y][currentMod->square3.x] = 219;
                map[currentMod->square4.y][currentMod->square4.x] = 219;
            }
        }break;
        case 1:
        case 2:{
            if(cankeepmove(map, kind, currentMod, direction)) {
                //清楚旧痕迹
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                map[currentMod->square5.y][currentMod->square5.x] = '\0';
                //移动
                if (direction == 'A' || direction == 'a') {
                    currentMod->square1.x = currentMod->square1.x - 1;
                    currentMod->square2.x = currentMod->square2.x - 1;
                    currentMod->square3.x = currentMod->square3.x - 1;
                    currentMod->square4.x = currentMod->square4.x - 1;
                    currentMod->square5.x = currentMod->square5.x - 1;
                    currentMod->pointOfRotation.x = currentMod->pointOfRotation.x - 1;
                } else if (direction == 'D' || direction == 'd') {
                    currentMod->square1.x = currentMod->square1.x + 1;
                    currentMod->square2.x = currentMod->square2.x + 1;
                    currentMod->square3.x = currentMod->square3.x + 1;
                    currentMod->square4.x = currentMod->square4.x + 1;
                    currentMod->square5.x = currentMod->square5.x + 1;
                    currentMod->pointOfRotation.x = currentMod->pointOfRotation.x + 1;
                }
                //生成新痕迹
                map[currentMod->square1.y][currentMod->square1.x] = 219;
                map[currentMod->square2.y][currentMod->square2.x] = 219;
                map[currentMod->square3.y][currentMod->square3.x] = 219;
                map[currentMod->square4.y][currentMod->square4.x] = 219;
                map[currentMod->square5.y][currentMod->square5.x] = 219;
            }
        }break;
    }
}

/* *****************************************************************
   函数功能：能否左右移动
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：地图二维数组， 类型， 当前模块的结构体指针， 方向键值：A or D
    返回值：布尔，能返回1，不能返回0；
********************************************************************/
int cankeepmove(char map[30][20], int kind, MOD * currentMod, int direction){
    if(direction == 'a' || direction == 'A') {  //左移
        switch (kind) {
            case 0: {
                if (abs((currentMod->square1.y - currentMod->square4.y)) == 2) {
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square2.y][currentMod->square2.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                    }
                }
                else{
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square2.y][currentMod->square2.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                            return 0;
                        }
                    }
                }
            }break;
            case 3:{
                if (abs((currentMod->square1.y - currentMod->square3.y)) == 2) {
                    if(currentMod->square1.y < currentMod->square3.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square2.y][currentMod->square2.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                            return 0;
                        }
                    }
                }
                else{
                    if(currentMod->square4.y < currentMod->square2.y) {
                        if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                    }
                }
            }break;
            case 4:{
                if (abs((currentMod->square1.y - currentMod->square4.y)) == 3) {
                    if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square2.y][currentMod->square2.x - 1] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                        return 0;
                    }
                }
                else{
                    if(currentMod->square4.x < currentMod->square1.x) {
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                    }
                }
            }break;
            case 5:{

                if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                    return 0;
                }
                if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                    return 0;
                }
            }break;
            case 1:{
                if (abs((currentMod->square1.y - currentMod->square4.y)) == 2) {
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square2.y][currentMod->square2.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square5.y][currentMod->square5.x - 1] == -37) {
                            return 0;
                        }
                    }
                }
                else{
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square5.y][currentMod->square5.x - 1] == -37) {
                            return 0;
                        }
                    }
                }
            }break;
            case 2:{
                if (abs((currentMod->square1.y - currentMod->square4.y)) == 2) {
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square5.y][currentMod->square5.x - 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square2.y][currentMod->square2.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                            return 0;
                        }
                    }
                }
                else{
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square5.y][currentMod->square5.x - 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square3.y][currentMod->square3.x - 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x - 1] == -37) {
                            return 0;
                        }
                    }
                }
            }break;
        }
    }
    else{ // 右移
        switch (kind) {
            case 0: {
                if (abs((currentMod->square1.y - currentMod->square4.y)) == 2) {
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square2.y][currentMod->square2.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }

                    }
                }
                else{
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x + 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square2.y][currentMod->square2.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }

                    }
                }
            }break;
            case 3:{
                if (abs((currentMod->square1.y - currentMod->square3.y)) == 2) {
                    if(currentMod->square1.y < currentMod->square3.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square2.y][currentMod->square2.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x + 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }
                    }
                }
                else{
                    if(currentMod->square4.y < currentMod->square2.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square3.y][currentMod->square3.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }
                    }
                }
            }break;
            case 4:{
                if (abs((currentMod->square1.y - currentMod->square4.y)) == 3) {
                    if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square2.y][currentMod->square2.x + 1] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square3.y][currentMod->square3.x + 1] == -37) {
                        return 0;
                    }
                    if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                        return 0;
                    }
                }
                else{
                    if(currentMod->square4.x < currentMod->square1.x) {
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }
                    }
                }
            }break;
            case 5:{

                if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                    return 0;
                }
                if (map[currentMod->square2.y][currentMod->square2.x + 1] == -37) {
                    return 0;
                }
            }break;
            case 1:{
                if (abs((currentMod->square1.y - currentMod->square4.y)) == 2) {
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square5.y][currentMod->square5.x + 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square2.y][currentMod->square2.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x + 1] == -37) {
                            return 0;
                        }
                    }
                }
                else{
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square5.y][currentMod->square5.x + 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square3.y][currentMod->square3.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }
                    }
                }
            }break;
            case 2:{
                if (abs((currentMod->square1.y - currentMod->square4.y)) == 2) {
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square2.y][currentMod->square2.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square3.y][currentMod->square3.x + 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square5.y][currentMod->square5.x + 1] == -37) {
                            return 0;
                        }
                    }
                }
                else{
                    if(currentMod->square1.y < currentMod->square4.y) {
                        if (map[currentMod->square3.y][currentMod->square3.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square4.y][currentMod->square4.x + 1] == -37) {
                            return 0;
                        }
                    }
                    else{
                        if (map[currentMod->square1.y][currentMod->square1.x + 1] == -37) {
                            return 0;
                        }
                        if (map[currentMod->square5.y][currentMod->square5.x + 1] == -37) {
                            return 0;
                        }
                    }
                }
            }break;
        }
    }
    return 1;
}

/* *****************************************************************
   函数功能：消除一行
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：地图二维数组, 得分
    返回值：void
********************************************************************/
void clean(char map[30][20], int *score){
    void allfall(char map[30][20], int line);
    int i, j;
    int full;
    for(i = 0; i < 29; i++){
        full = 1;
        for(j = 1; j < 19; j++){
            if(map[i][j] == '\0'){
                full = 0;
                break;
            }
        }
        if(full == 1){
            allfall(map, i);
            (*score) ++;
        }
    }
}

/* *****************************************************************
   函数功能：整个地图下移一行
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：地图二维数组， 行序号
    返回值：void
********************************************************************/
void allfall(char map[30][20], int line){
    int i, j;
    for(i = line; i > 0; i--){
        for(j = 1; j < 19; j++){
            map[i][j] = map[i - 1][j];
        }
    }
    for(j = 1; j < 19; j++){
        map[0][j] = '\0';
    }
}

/* *****************************************************************
   函数功能：旋转
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：地图二维数组， 当前模块
    返回值：void
********************************************************************/
//核心代码，估值一个亿
// 新的x = 旋转点的x - （块y - 转点的y）
// 新的y = 旋转点的y + （块x - 转点的y）
void rotate(char map[30][20], int kind, MOD * currentMod){
    MOD tempMod;
    switch(kind){
        case 5:
            return;
        case 0:
        case 3:
        case 4:{
            //清除旧痕迹
            map[currentMod->square1.y][currentMod->square1.x] = '\0';
            map[currentMod->square2.y][currentMod->square2.x] = '\0';
            map[currentMod->square3.y][currentMod->square3.x] = '\0';
            map[currentMod->square4.y][currentMod->square4.x] = '\0';
            //旋转
            tempMod.square1.x = currentMod->pointOfRotation.x -
                    (currentMod->square1.y - currentMod->pointOfRotation.y);
            tempMod.square1.y = currentMod->pointOfRotation.y +
                    (currentMod->square1.x - currentMod->pointOfRotation.x);

            tempMod.square2.x = currentMod->pointOfRotation.x -
                                    (currentMod->square2.y - currentMod->pointOfRotation.y);
            tempMod.square2.y = currentMod->pointOfRotation.y +
                                    (currentMod->square2.x - currentMod->pointOfRotation.x);

            tempMod.square3.x = currentMod->pointOfRotation.x -
                                    (currentMod->square3.y - currentMod->pointOfRotation.y);
            tempMod.square3.y = currentMod->pointOfRotation.y +
                                    (currentMod->square3.x - currentMod->pointOfRotation.x);

            tempMod.square4.x = currentMod->pointOfRotation.x -
                                    (currentMod->square4.y - currentMod->pointOfRotation.y);
            tempMod.square4.y = currentMod->pointOfRotation.y +
                                    (currentMod->square4.x - currentMod->pointOfRotation.x);
            currentMod->square1 = tempMod.square1;
            currentMod->square2 = tempMod.square2;
            currentMod->square3 = tempMod.square3;
            currentMod->square4 = tempMod.square4;
            //生成新痕迹
            map[currentMod->square1.y][currentMod->square1.x] = 219;
            map[currentMod->square2.y][currentMod->square2.x] = 219;
            map[currentMod->square3.y][currentMod->square3.x] = 219;
            map[currentMod->square4.y][currentMod->square4.x] = 219;

        }return;
        case 1:
        case 2://清除旧痕迹
            map[currentMod->square1.y][currentMod->square1.x] = '\0';
            map[currentMod->square2.y][currentMod->square2.x] = '\0';
            map[currentMod->square3.y][currentMod->square3.x] = '\0';
            map[currentMod->square4.y][currentMod->square4.x] = '\0';
            map[currentMod->square5.y][currentMod->square5.x] = '\0';
            //旋转
            tempMod.square1.x = currentMod->pointOfRotation.x -
                                (currentMod->square1.y - currentMod->pointOfRotation.y);
            tempMod.square1.y = currentMod->pointOfRotation.y +
                                (currentMod->square1.x - currentMod->pointOfRotation.x);

            tempMod.square2.x = currentMod->pointOfRotation.x -
                                (currentMod->square2.y - currentMod->pointOfRotation.y);
            tempMod.square2.y = currentMod->pointOfRotation.y +
                                (currentMod->square2.x - currentMod->pointOfRotation.x);

            tempMod.square3.x = currentMod->pointOfRotation.x -
                                (currentMod->square3.y - currentMod->pointOfRotation.y);
            tempMod.square3.y = currentMod->pointOfRotation.y +
                                (currentMod->square3.x - currentMod->pointOfRotation.x);

            tempMod.square4.x = currentMod->pointOfRotation.x -
                                (currentMod->square4.y - currentMod->pointOfRotation.y);
            tempMod.square4.y = currentMod->pointOfRotation.y +
                                (currentMod->square4.x - currentMod->pointOfRotation.x);

            tempMod.square5.x = currentMod->pointOfRotation.x -
                                (currentMod->square5.y - currentMod->pointOfRotation.y);
            tempMod.square5.y = currentMod->pointOfRotation.y +
                                (currentMod->square5.x - currentMod->pointOfRotation.x);

            currentMod->square1 = tempMod.square1;
            currentMod->square2 = tempMod.square2;
            currentMod->square3 = tempMod.square3;
            currentMod->square4 = tempMod.square4;
            currentMod->square5 = tempMod.square5;
            //生成新痕迹
            map[currentMod->square1.y][currentMod->square1.x] = 219;
            map[currentMod->square2.y][currentMod->square2.x] = 219;
            map[currentMod->square3.y][currentMod->square3.x] = 219;
            map[currentMod->square4.y][currentMod->square4.x] = 219;
            map[currentMod->square5.y][currentMod->square5.x] = 219;

    }
}

/* *****************************************************************
   函数功能：加速下落
。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
    传入参数：地图二维数组， 当前模块
    返回值：void
********************************************************************/
void speedfall(char map[30][20], int kind, MOD * currentMod){
    switch(kind){
        case 0:
        case 3:
        case 4:
        case 5:{
            if(cankeepfall(map, kind, currentMod)){
                //清楚旧痕迹
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                //下落
                currentMod->square1.y = currentMod->square1.y + 3;
                currentMod->square2.y = currentMod->square2.y + 3;
                currentMod->square3.y = currentMod->square3.y + 3;
                currentMod->square4.y = currentMod->square4.y + 3;
                currentMod->pointOfRotation.y = currentMod->pointOfRotation.y + 3;
                //生成新痕迹
                map[currentMod->square1.y][currentMod->square1.x] = 219;
                map[currentMod->square2.y][currentMod->square2.x] = 219;
                map[currentMod->square3.y][currentMod->square3.x] = 219;
                map[currentMod->square4.y][currentMod->square4.x] = 219;
            }
        }break;
        case 1:
        case 2:{
            if(cankeepfall(map, kind, currentMod)) {
                //清楚旧痕迹
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                map[currentMod->square5.y][currentMod->square5.x] = '\0';
                //下落
                currentMod->square1.y = currentMod->square1.y + 3;
                currentMod->square2.y = currentMod->square2.y + 3;
                currentMod->square3.y = currentMod->square3.y + 3;
                currentMod->square4.y = currentMod->square4.y + 3;
                currentMod->square5.y = currentMod->square5.y + 3;
                currentMod->pointOfRotation.y = currentMod->pointOfRotation.y + 3;
                //生成新痕迹
                map[currentMod->square1.y][currentMod->square1.x] = 219;
                map[currentMod->square2.y][currentMod->square2.x] = 219;
                map[currentMod->square3.y][currentMod->square3.x] = 219;
                map[currentMod->square4.y][currentMod->square4.x] = 219;
                map[currentMod->square5.y][currentMod->square5.x] = 219;
            }
        }break;
    }
}