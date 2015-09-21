#include<stdio.h>
#include<stdlib.h>
#include "../base.h"
typedef struct{
	float coef;
	int expn;
}term,ElemType;
typedef struct LNode{
	ElemType data;
	LNode *next;
}LNode,*polynomial;
void CreatePolyn(polynomial &P,int m){
	P = (polynomial)malloc(sizeof(LNode));
	P->data.coef = 0.0;
	P->data.expn = -1;
	P->next = NULL;
	int i;
	for(i = 1;i <= m;i++){
		term t;
		scanf("%f %d",&t.coef,&t.expn);
		LNode *node = (LNode *)malloc(sizeof(LNode));
		node->data = t;
		LNode *p = P;
		while(p->next && p->next->data.expn < t.expn){
			p = p->next;
		}
		node->next = p->next;
		p->next = node;
	}
}

void PrintPolyn(polynomial P){
	LNode *p = P->next;
	while(p){
		printf("%gx^%d",p->data.coef,p->data.expn);
		if(p->next){
			printf("+");
		}
		p = p->next;
	}
	printf("\n");
}
int compare(int a,int b){
	if(a > b){
		return 1;
	}else if(a < b){
		return -1;
	}else{
		return 0;
	}
}

void AddPolyn(polynomial &Pa,polynomial &Pb){
	LNode *qa_pre = Pa;
	LNode *qb = Pb->next;
	while(qa_pre->next && qb){
		switch(compare(qa_pre->next->data.expn , qb->data.expn)){
			case -1:
				qa_pre = qa_pre->next;
				break;
			case 0:
				float sum;
				sum = qa_pre->next->data.coef + qb->data.coef;
				if(sum){
					qa_pre->next->data.coef = sum;
					qa_pre = qa_pre->next;
					LNode *t = qb;
					qb = qb->next;
					free(t);
				}else{
					LNode *t = qa_pre->next;
					qa_pre = qa_pre->next->next;
					free(t);
					t = qb;
					qb = qb->next;
					free(t);
				}
				break;
			case 1:
				LNode *t = qb->next;
				qb->next = qa_pre->next;
				qa_pre->next = qb;
				qa_pre = qa_pre->next;
				qb = t;
				break;
		}
	}
	if(qb){
		qa_pre->next = qb;
	}
	free(Pb);
}

void MultiPolyn(polynomial &Pa,polynomial &Pb){
	LNode *qa = Pa->next;
	LNode *qb = Pb->next;
	LNode *qd = (LNode*)malloc(sizeof(LNode));
	qd->next = NULL;
	while(qb){
		LNode *qc = (LNode *)malloc(sizeof(LNode));
		qc->next = NULL;
		LNode *p = qc;
		qa = Pa->next;
		while(qa){
			LNode *node = (LNode *)malloc(sizeof(LNode));
			term t;
			t.coef = qb->data.coef * qa->data.coef;
			t.expn = qb->data.expn + qa->data.expn;
			node->data = t;
			node->next = p->next;
			p->next = node;
			p = p->next;
			qa = qa->next;
		}
		AddPolyn(qd,qc);
		qb = qb->next;
	}
	Pa = qd;
	free(Pb);
}
