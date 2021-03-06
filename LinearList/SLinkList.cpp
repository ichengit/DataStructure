#include<stdio.h>
#define MAXSIZE 1000
typedef int ElemType;
typedef struct{
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE];

void InitSpace_SL(SLinkList space){
	int i;
	for(i = 0;i < MAXSIZE - 1;i++){
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
}

void Free_SL(SLinkList space,int k){
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

int Malloc_SL(SLinkList space){
	int i = space[0].cur;
	if(space[0].cur){
		space[0].cur = space[i].cur;
	}
	return i;
}

void ListTraverse(SLinkList space,int S){
	int k = space[S].cur;
	while(k){
		printf("%d ",space[k].data);
		k = space[k].cur;
	}
}

void difference(SLinkList space,int &S){
	InitSpace_SL(space);
	S = Malloc_SL(space);
	int r = S;
	printf("input size of A and B:\n");
	int m,n;
	scanf("%d %d",&m,&n);
	printf("input elements of A:\n");
	int i,j;
	for(i = 0;i < m;i++){
		j = Malloc_SL(space);
		scanf("%d",&space[j].data);
		space[r].cur = j;
		r = j;
	}
	space[r].cur = 0;
	printf("input elements of B:\n");
	int b;
	int p,k;
	for(i = 0;i < n;i++){
		scanf("%d",&b);
		p = S;
		k = space[S].cur;
		while(k != space[r].cur && space[k].data != b){
			p = k;
			k = space[k].cur;
		}
		if(k == space[r].cur){
			j = Malloc_SL(space);
			space[j].data = b;
			space[j].cur = space[r].cur;
			space[r].cur = j;
		}else{
			space[p].cur = space[k].cur;
			Free_SL(space,k);
			if(k == r){
				r = p;
			}
		}
	}
}
