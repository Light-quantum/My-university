#include "util.h"

int main() {
    char map1[25][100] = {"\0"};

    int i = 0;
    int j = 0;
    int goal = 0;
    int success_eat = 0;
    SNAKE *head = NULL;

    printf("\n\n\n���Ǹ����ڶ�ά���������������������̰����\n");
    printf("�ǳ���л����֧��\n");
    printf("------------------------------------------------------------------\n");
    printf("��������ƶ�, �������ᶯ����ESC�˳���Ϸ\n");
    printf("��Ϊ�Ҳ�֪����ôʵ������һֱ����\nȻ��������ı䷽��ģ�д������\n");
    printf("������и��õ��뷨��ӭ���ҽ���\n");
    printf("-------------------------------------------------Author: SinhanLin\n");
    printf("��Ϸ���� 15s ��ʼ��������׼��\n");

    for(i = 15; i >= 0; i--){
        printf("%d\n", i);
        Sleep(1000);
    }
    system("cls");

    // ������ͼ
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

    head = initSnake(map1, 100, 25, head); // ��ʼ����
    randFood(map1, 100, 25); // �������ʳ��

    int status = 77; // ���˶�״̬��������ļ�ֵ
    while(1) {
        map(map1); // ��ӡ��ͼ
        status = getch();
        if(status == 75 ){ // �����
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
        else if(status == 77){ //  �ҷ����
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

        else if(status == 72){  // �Ϸ����
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
        else if(status == 80){  //  �·����
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