// Created by LinSihan on 2019/10/30.

/************************************************************
    �ó������ã������û���������´�ӡ����Ӧ��������
    function: according to the user entered a year and month
              to print out the corresponding calendar��
                                  by SihanLin 19-10-30 00:37
 ***********************************************************/
// ˼·��
// ����year��month
// ���� �����ж�����
// ���� ���µ�һ�������ڼ�
// ѭ����ӡ1���������һ��
// ����������

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include "util.h"

int main(){
    int year, month, days, w, c;

    time_t nowtime;
    struct tm *timeinfo;
    time( &nowtime ); //��ȡ��ǰʱ��
    timeinfo = localtime( &nowtime ); //תΪ����ʱ��
    year = timeinfo->tm_year + 1900; //��1900�꿪ʼ����
    month = timeinfo->tm_mon + 1;

    do{
        days = getDays(year, month); //��ø�������
        w = getWeek(year, month); //ʹ�ò��չ�ʽ�������1�������ڼ�
        getCalendar(w, days, year, month); //��ӡ������
        c = getch();
        if(c == 75 ){
            if(month == 1){
                month = 12;
                year = year - 1;
            }
            else
                month = month - 1;
        }
        else if(c == 77){
            if(month == 12){
                month = 1;
                year = year + 1;
            }
            else
                month = month + 1;
        }

        else if(c == 72){
            year = year - 1;
        }
        else if(c == 80){
            year = year + 1;
        }
        system("cls");

    }while(c != 27);
    return 0;
}