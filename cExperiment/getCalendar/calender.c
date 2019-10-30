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
#include "util.h"

int main(){
    int year, month, days, w;
    scanf("%d %d", &year, &month); //�����꣬��

    days = getDays(month, year); //��ø�������
    w = getWeek(year, month); //ʹ�ò��չ�ʽ�������1�������ڼ�

    getCalendar(w, days); //��ӡ������
    return 0;
}