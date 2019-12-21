#include "util.h"

int main() {
    char map1[25][100] = {"\0"};

    int i = 0;
    int j = 0;
    int goal = 0;
    int success_eat = 0;
    SNAKE *head = NULL;

    printf("\n\n\n这是个基于二维数组和链表做出来的垃圾贪吃蛇\n");
    printf("非常感谢您的支持\n");
    printf("------------------------------------------------------------------\n");
    printf("按方向键移动, 不按不会动，按ESC退出游戏\n");
    printf("因为我不知道怎么实现让他一直动，\n然后还能输入改变方向的，写不出来\n");
    printf("如果您有更好的想法欢迎和我交流\n");
    printf("-------------------------------------------------Author: SinhanLin\n");
    printf("游戏将在 15s 后开始，请做好准备\n");

    for(i = 15; i >= 0; i--){
        printf("%d\n", i);
        Sleep(1000);
    }
    system("cls");

    // 建立地图
    for(i = 0; i < 25; i++){
        for(j = 0; j < 100; j++){
            if(i == 0 || i == 24){
                map1[i][j] = '#';
            }
            else{
                if(j == 0 || j == 99){
                    map1[i][j] = '#';
                }
                else{
                    continue;
                }
            }
        }
    }

    head = initSnake(map1, 100, 25, head); // 初始化蛇
    randFood(map1, 100, 25); // 随机生成食物

    int status = 77; // 蛇运动状态，方向键的键值
    while(1) {
        map(map1); // 打印地图
        status = getch();
        if(status == 75 ){ // 左方向键
            if(getDeath(map1, head, status)) {
                goal = getGoal(map1, head, status, goal, &success_eat);
                if(success_eat) {
                    head = snakeGrow(map1, head, status);
                }
                head = goLeft(map1, head);
                if(success_eat){
                    randFood(map1, 100, 25);
                    success_eat = 0;
                }
            }
            else{
                break;
            }
        }
        else if(status == 77){ //  右方向键
            if(getDeath(map1, head, status)) {
                goal = getGoal(map1, head, status, goal, &success_eat);
                if(success_eat) {
                    head = snakeGrow(map1, head, status);
                }
                head = goRight(map1, head);
                if(success_eat){
                    randFood(map1, 100, 25);
                    success_eat = 0;
                }
            }
            else{
                break;
            }
        }

        else if(status == 72){  // 上方向键
            if(getDeath(map1, head, status)) {
                goal = getGoal(map1, head, status, goal, &success_eat);
                if(success_eat) {
                    head = snakeGrow(map1, head, status);
                }
                head = goUp(map1, head);
                if(success_eat){
                    randFood(map1, 100, 25);
                    success_eat = 0;
                }
            }
            else{
                break;
            }
        }
        else if(status == 80){  //  下方向键
            if(getDeath(map1, head, status)) {
                goal = getGoal(map1, head, status, goal, &success_eat);
                if(success_eat) {
                    head = snakeGrow(map1, head, status);
                }
                head = goDown(map1, head);
                if(success_eat){
                    randFood(map1, 100, 25);
                    success_eat = 0;
                }
            }
            else{
                break;
            }
        }
        if(status == 27){
            break;
        }
        system("cls");
    }
    printf("game over !!!\n");
    printf("Your goal: %d\n",goal);
    printf("Press any key to continue\n");
    getchar();
    return 0;
}