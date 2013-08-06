#include<iostream>
#include<cstdlib>
using namespace std;

#define end '\n'
#define space ' '
#define TElemType char
typedef struct BiTreeNode{
	TElemType data;
	struct BiTreeNode *lchild,*rchild;
}BiTreeNode,*BiTree;
typedef BiTree ElemType;

#define INITSIZE 100
#define INCREMENT 10
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}Stack;

void init(Stack &stack);
void push(Stack &stack,ElemType data);
void pop(Stack &stack,ElemType &data);
ElemType GetTop(Stack &stack);
bool empty(Stack &stack);