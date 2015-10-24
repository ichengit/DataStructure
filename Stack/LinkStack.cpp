#include <stdio.h>
#include <stdlib.h>
#include "../base.h"
#include "../LinearList/LinkList.cpp"

typedef struct LinkStack
{
	LinkList data;
	int stacksize;
}LinkStack;

Status InitStack(LinkStack &S){
	S.stacksize = 0;
	return InitList(S.data);
}

Status GetTop(LinkStack &S,ElemType &e){
	return GetElem(S.data,S.stacksize,e);
}

Status Push(LinkStack &S,ElemType e){
	Status status = ListInsert(S.data,1,e);
	S.stacksize += 1;
	return status;
}

Status Pop(LinkStack &S,ElemType &e){
	Status status = ListDelete(S.data,1,e);
	S.stacksize -= 1;
	return status;
}

Status DestroyStack(LinkStack &S){
	return DestroyList(S.data);
}

Status ClearStack(LinkStack &S){
	return ClearList(S.data);
}