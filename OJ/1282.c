//
// Created by LinSihan on 2019/12/10.
//
/**************************************************************
    题目描述
    Description
    已有a、b两个链表，每个链表中的结点包括学好、成绩。
    要求把两个链表合并，按学号升序排列。
    输入描述
    Input
    第一行，a、b两个链表元素的数量N、M,用空格隔开。
    接下来N行是a的数据然后M行是b的数据每行数据由学号和成绩两部分组成
    输出描述
    Output
    按照学号升序排列的数据
**************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct student_link_list{
    int id;
    int score;
    struct student_link_list * next;
};
typedef struct student_link_list STUDENT;

STUDENT *create(int n); // 建立链表
STUDENT *sort(STUDENT *head1);
int main(){
    STUDENT *head1, *head2 = NULL;
    int N, M;

    scanf("%d %d", &N, &M);

    head1 = create(N + M); // 创建链表
    head2 = sort(head1); // 排序链表

    //print
    STUDENT *p = head2;
    while(p != NULL){
        printf("%d %d\n", p->id, p->score);
        p = p->next;
    }
    return 0;
}

STUDENT *create(int n){
    STUDENT *head, *tail = NULL, *p;
    int i;
    int id, score;

    head = NULL;

    for(i = 1; i <= n; i++){
        scanf("%d %d", &id, &score);
        p = (STUDENT *)malloc(sizeof(STUDENT));
        p->id = id;
        p->score = score;
        if(head == NULL){
            head = p;
        }
        else{
            tail->next = p;
        }
        tail = p;
    }
    tail->next = NULL;
    return head;
}

STUDENT *sort(STUDENT *head1){
    STUDENT *p, *minP, *q, *newNode, *head2 = NULL;
    // 排序
    // 找到 head1 中 id 最小的节点
    p = head1;
    minP = p;
    int min = head1->id;
    p = p->next;
    while(p != NULL){
        if(p->id < min){
            min = p->id;
            minP = p;
        }
        p = p->next;
    }
    head2 = (STUDENT *)malloc(sizeof(STUDENT));  // 把 id 最小的结点作为 head2 的第一个节点
    head2->id = min;
    head2->score = minP->score;
    head2->next = NULL;
    p = head1;
    while(p != NULL){  // 排序开始
        q = head2;
        if(p->id == min){  // 如果当前
            if(p->next != NULL) {
                p = p->next;
                continue;
            }
            else{
                break;
            }
        }
        while(q->next != NULL) {
            if (p->id < q->next->id) {
                newNode = (STUDENT *) malloc(sizeof(STUDENT));
                newNode->id = p->id;
                newNode->score = p->score;
                newNode->next = q->next;
                q->next = newNode;
                break;
            } else {
                q = q->next;
            }
        }
        if(q->next == NULL){
            newNode = (STUDENT *)malloc(sizeof(STUDENT));
            newNode->id = p->id;
            newNode->score = p->score;
            newNode->next = NULL;
            q->next = newNode;
        }
        p = p->next;
    }
    return head2;
}