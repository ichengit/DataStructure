#include <stdio.h>
#include <stdlib.h>
#include "../base.h"
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char ElemType;
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S){
	S.base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S.base){
		exit(OVERFLOW);
	}
	S.stacksize = STACK_INIT_SIZE;
	S.top = S.base;
	return OK;
}

Status GetTop(SqStack &S,ElemType &e){
	if(S.base == S.top){
		return ERROR;
	}
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S,ElemType e){
	if(S.top - S.base >= S.stacksize){
		S.base = (ElemType*)realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(ElemType));
		if(!S.base){
			exit(OVERFLOW);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*(S.top++) = e;
	return OK;
}

Status Pop(SqStack &S,ElemType &e){
	if(S.top == S.base){
		return ERROR;
	}
	e = *(--S.top);
	return OK;
}

Status DestroyStack(SqStack &S){
	if(S.base){
		free(S.base);
	}
	return OK;
}

Status ClearStack(SqStack &S){
	S.top = S.base;
	return OK;
}

void PrintStack(SqStack &S){
	ElemType *p = S.base;
	while(p != S.top){
		printf("%c",*p++);
	}
	printf("\n");
}

void LineEdit(){
	SqStack S;
	ElemType e;
	InitStack(S);
	char ch = getchar();
	while(ch != '~'){
		while(ch != '~' && ch != '\n'){
			switch(ch){
				case '#':
					Pop(S,e);
					break;
				case '@':
					ClearStack(S);
					break;
				default:
					Push(S,ch);
					break;
			}
			ch = getchar();
		}
		PrintStack(S);
		ClearStack(S);
		if(ch != '~'){
			ch = getchar();
		}
	}
}