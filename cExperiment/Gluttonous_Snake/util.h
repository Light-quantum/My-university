//
// Created by LinSihan on 2019/12/19.
//

#ifndef SNAKE_UTIL_H
#define SNAKE_UTIL_H

#endif //SNAKE_UTIL_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct Snake{
    int x;
    int y;
    struct Sanke *next;
}SNAKE;


/*********************************************
    函数功能: 地图边框建立
 。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：地图二维数组
    返回：void
**********************************************/
void map(char map[][100]){
    int i, j;
    for(i = 0; i < 25; i++){
        for(j = 0; j < 100; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

/*********************************************
    函数功能: 生成随机食物
 。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：地图， 长（x）， 宽(y)
    返回：void
**********************************************/
void randFood(char map[][100], int max_x, int max_y){
    int x;
    int y;

    srand((unsigned)time(0));
    x = rand() % max_x;
    y = rand() % max_y;

    // 如果食物出现在墙上
    if(x == 0){
        x += 1;
    }
    else if(x == max_x - 1){
        x -= 1;
    }
    if(y == 0){
        y += 1;
    }
    else if(y == max_y - 1){
        y -= 1;
    }

    map[y][x] = 'Q';
}

/*********************************************
    函数功能: 生成蛇
 。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：地图
    返回：蛇头指针
**********************************************/
SNAKE *initSnake(char map[][100], int max_x, int max_y, SNAKE *head) {
    int head_x, head_y;
    SNAKE *p = head;
    SNAKE *t, *t1;

    head_x = max_x / 2;
    head_y = max_y / 2;

    head = (SNAKE *)malloc(sizeof(SNAKE));
    head->x = head_x;
    head->y = head_y;
    head->next = NULL;

    t = (SNAKE *) malloc(sizeof(SNAKE));
    t->x = head_x - 1;
    t->y = head_y;
    t->next = NULL;
    head->next = (struct Sanke *) t;

    t1 = (SNAKE *) malloc(sizeof(SNAKE));
    t1->x = head_x - 2;
    t1->y = head_y;
    t1->next = NULL;
    t->next = (struct Sanke *) t1;

    map[head_y][head_x] = '@';
    map[head_y][head_x - 1] = 'O';
    map[head_y][head_x - 2] = 'O';

    return head;
}

/*********************************************
    函数功能: 蛇向右移动
 。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：地图,蛇链表
    返回：蛇头指针
**********************************************/
SNAKE *goRight(char map[][100], SNAKE *head){
    SNAKE *p = head;
    SNAKE *per = NULL;
    while(p->next != NULL){
        per = p;
        p = (SNAKE *) p->next;
    }
    map[head->y][head->x + 1] = '@';
    map[head->y][head->x] = 'O';
    map[p->y][p->x] = '\0';
    per->next = NULL;
    free(p);

    SNAKE *t;
    t = (SNAKE *)malloc(sizeof(SNAKE));
    t->x = head->x + 1;
    t->y = head->y;
    t->next = (struct Sanke *) head;
    return t;
}

/*********************************************
    函数功能: 蛇向右移动
 。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：地图,蛇链表
    返回：蛇头指针
**********************************************/
SNAKE *goLeft(char map[][100], SNAKE *head){
    SNAKE *p = head;
    SNAKE *per = NULL;
    while(p->next != NULL){
        per = p;
        p = (SNAKE *) p->next;
    }
    map[head->y][head->x - 1] = '@';
    map[head->y][head->x] = 'O';
    map[p->y][p->x] = '\0';
    per->next = NULL;
    free(p);

    SNAKE *t;
    t = (SNAKE *)malloc(sizeof(SNAKE));
    t->x = head->x - 1;
    t->y = head->y;
    t->next = (struct Sanke *) head;
    return t;
}

/*********************************************
    函数功能: 蛇向右移动
 。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：地图,蛇链表
    返回：蛇头指针
**********************************************/
SNAKE *goUp(char map[][100], SNAKE *head){
    SNAKE *p = head;
    SNAKE *per = NULL;
    while(p->next != NULL){
        per = p;
        p = (SNAKE *) p->next;
    }
    map[head->y - 1][head->x] = '@';
    map[head->y][head->x] = 'O';
    map[p->y][p->x] = '\0';
    per->next = NULL;
    free(p);

    SNAKE *t;
    t = (SNAKE *)malloc(sizeof(SNAKE));
    t->x = head->x;
    t->y = head->y - 1;
    t->next = (struct Sanke *) head;
    return t;
}

/*********************************************
    函数功能: 蛇向右移动
 。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：地图,蛇链表
    返回：蛇头指针
**********************************************/
SNAKE *goDown(char map[][100], SNAKE *head){
    SNAKE *p = head;
    SNAKE *per = NULL;
    while(p->next != NULL){
        per = p;
        p = (SNAKE *) p->next;
    }
    map[head->y + 1][head->x] = '@';
    map[head->y][head->x] = 'O';
    map[p->y][p->x] = '\0';
    per->next = NULL;
    free(p);

    SNAKE *t;
    t = (SNAKE *)malloc(sizeof(SNAKE));
    t->x = head->x;
    t->y = head->y + 1;
    t->next = (struct Sanke *) head;
    return t;
}

/*********************************************
    函数功能: 蛇生长
 。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：地图,蛇链表, 状态
    返回：蛇头指针
**********************************************/
SNAKE *snakeGrow(char map[][100], SNAKE *head, int keep){
    SNAKE *p = head;
    while(p->next != NULL){
        p = (SNAKE *) p->next;
    }
    SNAKE* temp;
    temp = (SNAKE *)malloc(sizeof(SNAKE));
    temp->next = NULL;
    if(keep == 77){ // 右
        temp->x = p->x-1;
        temp->y = p->y;
        p->next = (struct Sanke *) temp;
        map[temp->y][temp->x] = 'O';
    }
    else if(keep == 75){ // 左
        temp->x = p->x+1;
        temp->y = p->y;
        p->next = (struct Sanke *) temp;
        map[temp->y][temp->x] = 'O';
    }
    else if(keep == 72){ // 上
        temp->x = p->x;
        temp->y = p->y+1;
        p->next = (struct Sanke *) temp;
        map[temp->y][temp->x] = 'O';
    }
    else if(keep == 80){ // 下
        temp->x = p->x-1;
        temp->y = p->y;
        p->next = (struct Sanke *) temp;
        map[temp->y][temp->x] = 'O';
    }
    return head;
}

/*********************************************
    函数功能: 得分
 。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：地图,蛇链表, 状态, 分数
    返回：分数
**********************************************/
int getGoal(char map[][100], SNAKE *head, int keep, int goal, int *success_eat){
    if(keep == 77){ // 右
        if(map[head->y][head->x + 1] == 'Q'){
            *success_eat = 1;
            goal++;
        }
    }
    else if(keep == 75){ //左
        if(map[head->y][head->x - 1] == 'Q'){
            *success_eat = 1;
            goal++;
        }
    }
    if(keep == 72){  // 上
        if(map[head->y - 1][head->x] == 'Q'){
            *success_eat = 1;
            goal++;
        }
    }
    if(keep == 80){  // 下
        if(map[head->y + 1][head->x] == 'Q'){
            *success_eat = 1;
            goal++;
        }
    }
    return goal;
}

/*********************************************
    函数功能: 判断生死
 。。。。。。。。。。。。。。。。。。。。。。。。。。
    输入：地图,蛇链表, 状态
    返回：bool
**********************************************/
int getDeath(char map[][100], SNAKE *head, int keep){
    if(keep == 77){ // 右
        if(map[head->y][head->x + 1] == '#'){
            return 0;
        }
    }
    else if(keep == 75){ //左
        if(map[head->y][head->x - 1] == '#'){
            return 0;
        }
    }
    else if(keep == 72){  // 上
        if(map[head->y - 1][head->x] == '#'){
            return 0;
        }
    }
    else if(keep == 80){  // 下
        if(map[head->y + 1][head->x] == '#'){
            return 0;
        }
    }
    else {
        return 1;
    }
}