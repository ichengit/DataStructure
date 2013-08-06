#include "head.h"

void visit(BiTree T){
	if(T)
		cout << T->data;
}

/*��������򴴽�������*/
void create(BiTree &T){
	TElemType data;
	if(end == '\n')
		data = getchar();
	else
		cin >> data;
	if(data == end)
		return;
	if(data == space)
		T = NULL;
	else{
		T = (BiTreeNode *)malloc(sizeof(BiTreeNode));
		T->data = data;
		create(T->lchild);
		create(T->rchild);
	}
}

/*������������õݹ�*/
void PreOrderTraverse(BiTree T,void (*visit)(BiTree)){
	if(T){
		visit(T);
		PreOrderTraverse(T->lchild,visit);
		PreOrderTraverse(T->rchild,visit);
	}
}

/*��������������õݹ�*/
void InOrderTraverse(BiTree T,void (visit)(BiTree)){
	if(T){
	    InOrderTraverse(T->lchild,visit);
		visit(T);
		InOrderTraverse(T->rchild,visit);
	}
}

/*������������õݹ�*/
void PostOrderTraverse(BiTree T,void (visit)(BiTree)){
	if(T){
		PostOrderTraverse(T->lchild,visit);
		PostOrderTraverse(T->rchild,visit);
		visit(T);
	}
}

/*����������ǵݹ��㷨*/
void PreOrderTraverse1(BiTree T,void (*visit)(BiTree)){
	Stack stack;
	BiTree p;
	init(stack);
	push(stack,T);	//��ָ���ջ
	while(!empty(stack)){
		while(p = GetTop(stack)){
			visit(p);  //���ʽڵ�
			push(stack,p->lchild);	//�����ߵ���ͷ
		}
		pop(stack,p);	//��ָ���ջ
		if(!empty(stack)){
			pop(stack,p);
			push(stack,p->rchild);	//�Һ���ָ���ջ
		}
	}
}

/*����������ǵݹ��㷨*/
void InOrderTraverse1(BiTree T,void (*visit)(BiTree)){
	Stack stack;
	BiTree p;
	init(stack);
	push(stack,T);	//��ָ���ջ
	while(!empty(stack)){
		while(p = GetTop(stack))
			push(stack,p->lchild);	//�����ߵ���ͷ
		pop(stack,p);	//��ָ���ջ
		if(!empty(stack)){
			pop(stack,p);
			visit(p);  //���ʽڵ�
			push(stack,p->rchild);	//�Һ���ָ���ջ
		}
	}
}

/*����������ǵݹ��㷨*/
void PostOrderTraverse1(BiTree T,void (*visit)(BiTree)){
	Stack stack;
	BiTree p;
	init(stack);
	push(stack,T);
	while(!empty(stack)){
		while(p = GetTop(stack))
			push(stack,p->lchild);
		pop(stack,p);
		while(!empty(stack) && (GetTop(stack)->rchild == p)){
			pop(stack,p);
			visit(p);
		}
		if(!empty(stack))
			push(stack,GetTop(stack)->rchild);
	}
}
	
void main(){
	cout << "�������������������нڵ��ֵ\n";
	BiTree T;
	create(T);
	PostOrderTraverse1(T,visit);

}