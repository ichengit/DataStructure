#include<stdio.h>
#include<stdlib.h>
#include "../base.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

//初始化顺序表
Status InitList(SqList &L){
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

//销毁顺序表
Status DestroyList(SqList &L){
	if(L.elem){
		free(L.elem);
		return OK;
	}
}

//清空顺序表
Status ClearList(SqList &L){
	L.length = 0;
	return OK;
}

//获取顺序表长度
int ListLength(SqList L){
	return L.length;
}

//判断顺序表是否为空
int ListEmpty(SqList L){
	if(L.length == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}

//将第i个元素的值赋给e
Status GetElem(SqList L,int i,ElemType &e){
	if(i < 1 || i > ListLength(L)){
		exit(OVERFLOW);
	}
	int k;
	e = L.elem[i - 1];
	return OK;
}
int compare(ElemType e1,ElemType e2){
    if(e1 < e2){
        return -1;
    }else if(e1 == e2){
        return 0;
    }else{
        return 1;
    }
}

//返回L中第1个与e满足compare的数据元素的位置
Status LocateElem(SqList L,ElemType e,int (*compare)(ElemType arg1,ElemType arg2)){
    int i,t;
    int length = ListLength(L);
    for(i = 1;i <= length;i++){
        GetElem(L,i,t);
        if(compare(e,t) == 0){
            return i;
        }
    }
    if(i > length){
        return 0;
    }
}

//返回前驱元素
Status PriorElem(SqList L,ElemType cur_e,ElemType &e){
    ElemType current;
    GetElem(L,1,current);
    if(cur_e == current){
        return ERROR;
    }
    int length = ListLength(L);
    int i;
    for(i = 2;i <= length;i++){
        GetElem(L,i,current);
        if(current == cur_e){
            GetElem(L,i - 1,e);
            return OK;
        }
    }
    if(i > length){
        return ERROR;
    }
}

//返回后继元素
Status NextElem(SqList L,ElemType cur_e,ElemType &e){
    int length = ListLength(L);
    ElemType current;
    GetElem(L,length,current);
    if(cur_e == current){
        return ERROR;
    }
    int i;
    for(i = 1;i < length;i++){
        GetElem(L,i,current);
        if(current == cur_e){
            GetElem(L,i + 1,e);
            return OK;
        }
    }
    if(i >= length){
        return ERROR;
    }
}

//在L中第i个位置之前插入元素e
Status ListInsert(SqList &L,int i,ElemType e){
    if(i < 1 || i > L.length + 1){
        return ERROR;
    }
    if(L.length >= L.listsize){
        ElemType *newbase = (ElemType*)realloc(L.elem,(L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase){
            exit(OVERFLOW);
        }
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    int j;
    for(j = L.length - 1;j >= i - 1;j--){
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
    return OK;
}

//删除L中第i个元素
Status ListDelete(SqList &L,int i,ElemType &e){
    if(i < 1 || i > L.length){
        return ERROR;
    }
    GetElem(L,i,e);
    int j;
    for(j = i - 1;j < L.length - 1;j++){
        L.elem[j] = L.elem[j + 1];
    }
    L.length--;
    return OK;
}

void print(ElemType e){
    printf("%d ",e);
}

Status ListTraverse(SqList L,void (*visit)(ElemType e)){
    int i;
    ElemType data;
    int length = ListLength(L);
    for(i = 1;i <= length;i++){
        GetElem(L,i,data);
        visit(data);
    }
    printf("\n");
    return OK;
}
