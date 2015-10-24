#include <stdio.h>
#include <stdlib.h>
#include "../base.h"
#define MAXQSIZE 100

typedef struct{
	ElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
	Q.base = (ElemType *)malloc(MAXQSIZE * sizeof(ElemType));
	if(!Q.base){
		exit(OVERFLOW);
	}
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

Status DestroyQueue(SqQueue &Q){
	free(Q.base);
	return OK;
}

Status ClearQueue(SqQueue &Q){
	Q.front = Q.rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue Q){
	return Q.front == Q.rear;
}

int QueueLength(SqQueue Q){
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status GetHead(SqQueue &Q,ElemType &e){
	e = Q.base[Q.front];
	return OK;
}

Status EnQueue(SqQueue &Q,ElemType e){
	if(Q.front == (Q.rear + 1) % MAXQSIZE){
		return ERROR;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q,ElemType &e){
	if(Q.front == Q.rear){
		return ERROR;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}