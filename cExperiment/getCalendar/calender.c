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
    printf("�����������ѯ������(��ʽΪyyyy-mm): ");
    scanf("%d-%d", &year, &month); //�����꣬��
    printf("\n ");

    days = getDays(year, month); //��ø�������
    w = getWeek(year, month); //ʹ�ò��չ�ʽ�������1�������ڼ�

    printf("%4d��%2d����������:\n\n", year, month);
    getCalendar(w, days); //��ӡ������
    return 0;
}