#include <stdio.h>
#include <stdlib.h>
#include "../base.h"
typedef int ElemType;
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front){
		exit(OVERFLOW);
	}
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q){
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue &Q){
	QueuePtr p = Q.front->next;
	while(p){
		Q.rear = p->next;
		free(p);
		p = Q.rear;
	}
	Q.rear = Q.front;
	Q.front->next = NULL;
	return OK;
}

Status QueueEmpty(LinkQueue Q){
	return Q.front == Q.rear;
}

int QueueLength(LinkQueue Q){
	return Q.rear - Q.front;
}

Status GetHead(LinkQueue Q,QElemType &e){
	e = Q.front->next->data;
}

Status EnQueue(LinkQueue &Q,QElemType e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p){
		exit(OVERFLOW);
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e){
	QueuePtr p = Q.front->next;
	Q.front->next = p->next;
	if(Q.rear == p){
		Q.rear = Q.front;
	}
	free(p);
	return OK;
}
