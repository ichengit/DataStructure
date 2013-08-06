#include<iostream>
using namespace std;
typedef int ElemType;

typedef struct node{
	ElemType data;
	struct node *next;
}node,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void init(LinkQueue &queue){
	queue.front = queue.rear = (node *)malloc(sizeof(node));
	queue.front->next = NULL;
}

void destroy(LinkQueue &queue){
	while(queue.front){
		queue.rear = queue.front->next;
		free(queue.front);
		queue.front = queue.rear;
	}
}

void EnQueue(LinkQueue &queue,ElemType data){
	node * p = (QueuePtr)malloc(sizeof(node));
	p->data = data;
	p->next = NULL;
	queue.rear->next = p;
	queue.rear = p;
}

void DeQueue(LinkQueue &queue,ElemType &data){
	if(queue.front == queue.rear)
		return;
	node *p = queue.front->next;
	data = p->data;
	queue.front->next = p->next;
	if(p == queue.rear)
		queue.rear = queue.front;
	free(p);
}

void clear(LinkQueue &queue){
	queue.rear = queue.front;
}

bool empty(LinkQueue &queue){
	return queue.front == queue.rear;
}

int length(LinkQueue &queue){
	int count = 0;
	node *p = queue.front;
	while(p->next){
		count++;
		p = p->next;
	}
	return count;
}

void GetHead(LinkQueue &queue,ElemType &data){
	if(queue.front != queue.rear)
		data = queue.front->next->data;
}

void show(LinkQueue queue){
	QueuePtr p = queue.front->next;
	while(p){
		cout << p->data << " ";
		p = p->next;
	}
}

