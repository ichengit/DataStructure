#include<iostream>
#include<cstdlib>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;
typedef struct{
	ElemType *base;
	int front;
	int rear;
}SqQueue;

void init(SqQueue &queue){
	queue.base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	queue.front = queue.rear = 0;
}

int length(SqQueue queue){
	return (queue.rear - queue.front + MAXSIZE) % MAXSIZE;
}

void EnQueue(SqQueue &queue,ElemType data){
	if((queue.rear + 1) % MAXSIZE == queue.front)
		return;
	queue.base[queue.rear] = data;
	queue.rear = (queue.rear + 1) % MAXSIZE;
}

void DeQueue(SqQueue &queue,ElemType &data){
	if(queue.front == queue.rear)
		return;
	data = queue.base[queue.front];
	queue.front = (queue.front + 1) % MAXSIZE;
}

void show(SqQueue queue){
	while(queue.front < queue.rear)
		cout << queue.base[queue.front++] << " ";
}

void main(){
	SqQueue queue;
	int data;
	init(queue);
	for(int i = 0;i < 99;i++)
		EnQueue(queue,i);
	show(queue);
	cout << "\nlength=" << length(queue) << "\n";
	for(i = 0;i < 90;i++)
		DeQueue(queue,data);
	show(queue);
	cout << "\nlength=" << length(queue) << "\n";
}