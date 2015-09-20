#include<stdio.h>
#include<stdlib.h>
#include "../base.h"
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//初始化链表
Status InitList(LinkList &L){//此处参数为&L，否则不能给L赋值
    L = (LinkList)malloc(sizeof(LNode));
    if(!L){
        exit(OVERFLOW);
    }
    L->next = NULL;
    return OK;
}
//获取第i个元素
Status GetElem(LinkList L,int i,ElemType &e){
    int j = 1;
    LNode *p = L->next;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p || j > i){
        return ERROR;
    }
    e = p->data;
    return OK;
}

//在第i个元素前插入e
Status ListInsert(LinkList L,int i,ElemType e){
    int j = 0;
    LNode *p = L;
    while(p && j < i - 1){
        p = p->next;
        j++;
    }
    if(!p || j > i - 1){
        return ERROR;
    }
    LNode *node = (LinkList)malloc(sizeof(LNode));
    node->data = e;
    node->next = p->next;
    p->next = node;
    return OK;
}

//删除第i个元素
Status ListDelete(LinkList L,int i,ElemType &e){
    int j = 0;
    LNode *p = L;
    while(p->next && j < i - 1){
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i - 1){
        return ERROR;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

void print(ElemType e){
    printf("%d ",e);
}
//遍历链表
Status ListTraverse(LinkList L,void (*visit)(ElemType e)){
    LNode *p = L->next;
    while(p){
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
