// Created by LinSihan on 2019/10/30.


#ifndef CALENDAR_UTIL_H
#define CALENDAR_UTIL_H

#endif //CALENDAR_UTIL_H

#include <stdio.h>
/*************************************************************
    �������ܣ�get the number of days in this month; ���ÿ������
����������������������������������������������������������������������
    ���룺month; �·�
    �����the number of day in this month; ��������
                                    by SihanLin 19-10-30 00:14
**************************************************************/
int isLeapYear(int year);
int getDays(int year, int month){
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return (isLeapYear(year)) ? 29 : 28;
        default:
            return 0;
    }
}



/*************************************************************
    �������ܣ�judge whether the input year is a leap year��
             �ж����������Ƿ�Ϊ����
����������������������������������������������������������������������
    ���룺year; ���
    �����Whether it is a leap year, is 1, no is 0;
         �Ƿ�Ϊ���꣬��Ϊ1����Ϊ0��
                                    by SihanLin 19-10-30 00:36
**************************************************************/
int isLeapYear(int year){
    return year % (year % 100 == 0 ? 400 : 4) == 0;
}



/*************************************************************
    �������ܣ�ʹ�ò��չ�ʽ����ÿ��һ�Ŷ�Ӧ���ڼ�
����������������������������������������������������������������������
    ���룺year��month��day = 1��
    ���������[0, 6],��Ӧ���յ���һ
                                    by SihanLin 19-10-30 00:47
**************************************************************/
int getWeek(int year, int month) {
    int day = 1;
    int c, y, m, d, w;

    //����ǰԤ����
    if (month <= 2) {
        y = year - 1;
        m = 12 + month;
    } else {
        y = year;
        m = month;
    }
    d = day;
    c = y / 100;
    y = y % 100;


    //��ʼ����
    w = ((y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1) % 7 + 7) % 7;

    return w;
}


/*************************************************************
    �������ܣ���ӡ����
����������������������������������������������������������������������
    ���룺���չ�ʽ������w����������days
    �������ӡ������
                                    by SihanLin 19-10-30 10:59
*************************************************************/
int getCalendar(int w, int days, int year, int month){
    int w1;
    w1 = w;
    printf("---------------��������%4d��%2d�£�------------------------\n\n", year, month);
    printf("��\tһ\t��\t��\t ��\t ��\t ��\n");
    printf("\n ");
    while(w1--){
        printf("\t");
    }
    int i, j;
    for(i = 1; i <= days; i++){
        printf("%2d\t", i);
        j = i + w;
        if(j % 7 == 0){
            printf("\n ");
            printf("\n ");
        }
    }
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("�����¼�ͷ�л���ݣ������Ҽ�ͷ�л��·ݣ�Esc�˳���");
    return 1;
}