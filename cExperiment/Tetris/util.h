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
	�������ܣ��ı���λ��
����������������������������������������������
	���룺x, y
	���أ�void
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
   �������ܣ���ʼ������ģ��
��������������������������������������������������������
    �������������ģ�������
    ����ֵ��void
*************************************************/
void initmod(MOD modList[]){
    // �����ǵ� 0 �ַ���
    // 2 Ϊ��ת��
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

    // �����ǵ� 1 �ַ���
    // 5 Ϊ��ת��
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
    // �����ǵ� 2 �ַ���
    // 5 Ϊ��ת��
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
    // �����ǵ� 3 �ַ���
    // 2 Ϊ��ת��
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
    // �����ǵ� 4 �ַ���
    //  3 Ϊ��ת��
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
    // �����ǵ� 5 �ַ���
    //  4 Ϊ��ת��
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
   �������ܣ���ʼ����ͼ
��������������������������������������������������������
    ��������������ͼ�Ķ�ά����
    ����ֵ��void
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
   �������ܣ���ӡ��ͼ
��������������������������������������������������������
    ��������������ͼ�Ķ�ά����
    ����ֵ��void
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
   �������ܣ�������ģ��
��������������������������������������������������������
    ���������void
    ����ֵ��ģ������ 0 ~ 5
*************************************************/
int getkindofmod(){
    srand((unsigned)time(0));
    return rand() % 6;
}


/* ************************************************
   �������ܣ���ģ����ص���ͼ��
��������������������������������������������������������
    �����������ͼģ���ά���飬����, ģ����������
    ����ֵ��void
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
   �������ܣ���õ�ǰģ��Ľṹ��
��������������������������������������������������������
    ������������ͣ� ģ�����飬 ģ��Ľṹ��ָ��
    ����ֵ��void
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
   �������ܣ���Ȼ����
������������������������������������������������������������������
    �����������ͼģ���ά���飬ģ�����ͣ� ��ǰģ��Ľṹ��ָ��
    ����ֵ��void
*********************************************************/
// �����������Ϻۼ������ºۼ�
void freefall(char map[30][20], int kind, MOD * currentMod){
    int cankeepfall(char map[30][20], int kind, MOD * currentMod);
    switch(kind){
        case 0:
        case 3:
        case 4:
        case 5:{
            if(cankeepfall(map, kind, currentMod)){
                //����ɺۼ�
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                //����
                currentMod->square1.y = currentMod->square1.y + 1;
                currentMod->square2.y = currentMod->square2.y + 1;
                currentMod->square3.y = currentMod->square3.y + 1;
                currentMod->square4.y = currentMod->square4.y + 1;
                currentMod->pointOfRotation.y = currentMod->pointOfRotation.y + 1;
                //�����ºۼ�
                map[currentMod->square1.y][currentMod->square1.x] = 219;
                map[currentMod->square2.y][currentMod->square2.x] = 219;
                map[currentMod->square3.y][currentMod->square3.x] = 219;
                map[currentMod->square4.y][currentMod->square4.x] = 219;
            }
        }break;
        case 1:
        case 2:{
            if(cankeepfall(map, kind, currentMod)) {
                //����ɺۼ�
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                map[currentMod->square5.y][currentMod->square5.x] = '\0';
                //����
                currentMod->square1.y = currentMod->square1.y + 1;
                currentMod->square2.y = currentMod->square2.y + 1;
                currentMod->square3.y = currentMod->square3.y + 1;
                currentMod->square4.y = currentMod->square4.y + 1;
                currentMod->square5.y = currentMod->square5.y + 1;
                currentMod->pointOfRotation.y = currentMod->pointOfRotation.y + 1;
                //�����ºۼ�
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
   �������ܣ��ܷ��������
��������������������������������������������������������
    �����������ͼ��ά���飬 ���ͣ� ��ǰģ��Ľṹ��ָ��
    ����ֵ���������ܷ���1�����ܷ���0��
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
   �������ܣ������ƶ�
������������������������������������������������������������������������������
    �����������ͼ��ά���飬 ���ͣ� ��ǰģ��Ľṹ��ָ�룬 �����ֵ��A or D
    ����ֵ��void
********************************************************************/
// ˼·���ܼ򵥣�x ������Ӽ������ǵ÷�Խ����ص����������߻����ҵķ����Ƿ��з��飩
void move(char map[30][20], int kind, MOD * currentMod, int direction){
    int cankeepmove(char map[30][20], int kind, MOD * currentMod, int direction);
    switch(kind){
        case 0:
        case 3:
        case 4:
        case 5:{
            if(cankeepmove(map, kind, currentMod, direction)) {
                //����ɺۼ�
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                //�ƶ�
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
                //�����ºۼ�
                map[currentMod->square1.y][currentMod->square1.x] = 219;
                map[currentMod->square2.y][currentMod->square2.x] = 219;
                map[currentMod->square3.y][currentMod->square3.x] = 219;
                map[currentMod->square4.y][currentMod->square4.x] = 219;
            }
        }break;
        case 1:
        case 2:{
            if(cankeepmove(map, kind, currentMod, direction)) {
                //����ɺۼ�
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                map[currentMod->square5.y][currentMod->square5.x] = '\0';
                //�ƶ�
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
                //�����ºۼ�
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
   �������ܣ��ܷ������ƶ�
������������������������������������������������������������������������������
    �����������ͼ��ά���飬 ���ͣ� ��ǰģ��Ľṹ��ָ�룬 �����ֵ��A or D
    ����ֵ���������ܷ���1�����ܷ���0��
********************************************************************/
int cankeepmove(char map[30][20], int kind, MOD * currentMod, int direction){
    if(direction == 'a' || direction == 'A') {  //����
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
    else{ // ����
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
   �������ܣ�����һ��
������������������������������������������������������������������������������
    �����������ͼ��ά����, �÷�
    ����ֵ��void
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
   �������ܣ�������ͼ����һ��
������������������������������������������������������������������������������
    �����������ͼ��ά���飬 �����
    ����ֵ��void
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
   �������ܣ���ת
������������������������������������������������������������������������������
    �����������ͼ��ά���飬 ��ǰģ��
    ����ֵ��void
********************************************************************/
//���Ĵ��룬��ֵһ����
// �µ�x = ��ת���x - ����y - ת���y��
// �µ�y = ��ת���y + ����x - ת���y��
void rotate(char map[30][20], int kind, MOD * currentMod){
    MOD tempMod;
    switch(kind){
        case 5:
            return;
        case 0:
        case 3:
        case 4:{
            //����ɺۼ�
            map[currentMod->square1.y][currentMod->square1.x] = '\0';
            map[currentMod->square2.y][currentMod->square2.x] = '\0';
            map[currentMod->square3.y][currentMod->square3.x] = '\0';
            map[currentMod->square4.y][currentMod->square4.x] = '\0';
            //��ת
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
            //�����ºۼ�
            map[currentMod->square1.y][currentMod->square1.x] = 219;
            map[currentMod->square2.y][currentMod->square2.x] = 219;
            map[currentMod->square3.y][currentMod->square3.x] = 219;
            map[currentMod->square4.y][currentMod->square4.x] = 219;

        }return;
        case 1:
        case 2://����ɺۼ�
            map[currentMod->square1.y][currentMod->square1.x] = '\0';
            map[currentMod->square2.y][currentMod->square2.x] = '\0';
            map[currentMod->square3.y][currentMod->square3.x] = '\0';
            map[currentMod->square4.y][currentMod->square4.x] = '\0';
            map[currentMod->square5.y][currentMod->square5.x] = '\0';
            //��ת
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
            //�����ºۼ�
            map[currentMod->square1.y][currentMod->square1.x] = 219;
            map[currentMod->square2.y][currentMod->square2.x] = 219;
            map[currentMod->square3.y][currentMod->square3.x] = 219;
            map[currentMod->square4.y][currentMod->square4.x] = 219;
            map[currentMod->square5.y][currentMod->square5.x] = 219;

    }
}

/* *****************************************************************
   �������ܣ���������
������������������������������������������������������������������������������
    �����������ͼ��ά���飬 ��ǰģ��
    ����ֵ��void
********************************************************************/
void speedfall(char map[30][20], int kind, MOD * currentMod){
    switch(kind){
        case 0:
        case 3:
        case 4:
        case 5:{
            if(cankeepfall(map, kind, currentMod)){
                //����ɺۼ�
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                //����
                currentMod->square1.y = currentMod->square1.y + 3;
                currentMod->square2.y = currentMod->square2.y + 3;
                currentMod->square3.y = currentMod->square3.y + 3;
                currentMod->square4.y = currentMod->square4.y + 3;
                currentMod->pointOfRotation.y = currentMod->pointOfRotation.y + 3;
                //�����ºۼ�
                map[currentMod->square1.y][currentMod->square1.x] = 219;
                map[currentMod->square2.y][currentMod->square2.x] = 219;
                map[currentMod->square3.y][currentMod->square3.x] = 219;
                map[currentMod->square4.y][currentMod->square4.x] = 219;
            }
        }break;
        case 1:
        case 2:{
            if(cankeepfall(map, kind, currentMod)) {
                //����ɺۼ�
                map[currentMod->square1.y][currentMod->square1.x] = '\0';
                map[currentMod->square2.y][currentMod->square2.x] = '\0';
                map[currentMod->square3.y][currentMod->square3.x] = '\0';
                map[currentMod->square4.y][currentMod->square4.x] = '\0';
                map[currentMod->square5.y][currentMod->square5.x] = '\0';
                //����
                currentMod->square1.y = currentMod->square1.y + 3;
                currentMod->square2.y = currentMod->square2.y + 3;
                currentMod->square3.y = currentMod->square3.y + 3;
                currentMod->square4.y = currentMod->square4.y + 3;
                currentMod->square5.y = currentMod->square5.y + 3;
                currentMod->pointOfRotation.y = currentMod->pointOfRotation.y + 3;
                //�����ºۼ�
                map[currentMod->square1.y][currentMod->square1.x] = 219;
                map[currentMod->square2.y][currentMod->square2.x] = 219;
                map[currentMod->square3.y][currentMod->square3.x] = 219;
                map[currentMod->square4.y][currentMod->square4.x] = 219;
                map[currentMod->square5.y][currentMod->square5.x] = 219;
            }
        }break;
    }
}