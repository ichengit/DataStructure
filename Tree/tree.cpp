#include "head.h"

void visit(BiTree T){
	if(T)
		cout << T->data;
}

/*按先序次序创建二叉树*/
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

/*先序遍历，采用递归*/
void PreOrderTraverse(BiTree T,void (*visit)(BiTree)){
	if(T){
		visit(T);
		PreOrderTraverse(T->lchild,visit);
		PreOrderTraverse(T->rchild,visit);
	}
}

/*中序序遍历，采用递归*/
void InOrderTraverse(BiTree T,void (visit)(BiTree)){
	if(T){
	    InOrderTraverse(T->lchild,visit);
		visit(T);
		InOrderTraverse(T->rchild,visit);
	}
}

/*后序遍历，采用递归*/
void PostOrderTraverse(BiTree T,void (visit)(BiTree)){
	if(T){
		PostOrderTraverse(T->lchild,visit);
		PostOrderTraverse(T->rchild,visit);
		visit(T);
	}
}

/*先序遍历，非递归算法*/
void PreOrderTraverse1(BiTree T,void (*visit)(BiTree)){
	Stack stack;
	BiTree p;
	init(stack);
	push(stack,T);	//根指针进栈
	while(!empty(stack)){
		while(p = GetTop(stack)){
			visit(p);  //访问节点
			push(stack,p->lchild);	//向左走到尽头
		}
		pop(stack,p);	//空指针出栈
		if(!empty(stack)){
			pop(stack,p);
			push(stack,p->rchild);	//右孩子指针进栈
		}
	}
}

/*中序遍历，非递归算法*/
void InOrderTraverse1(BiTree T,void (*visit)(BiTree)){
	Stack stack;
	BiTree p;
	init(stack);
	push(stack,T);	//根指针进栈
	while(!empty(stack)){
		while(p = GetTop(stack))
			push(stack,p->lchild);	//向左走到尽头
		pop(stack,p);	//空指针出栈
		if(!empty(stack)){
			pop(stack,p);
			visit(p);  //访问节点
			push(stack,p->rchild);	//右孩子指针进栈
		}
	}
}

/*后序遍历，非递归算法*/
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
	cout << "按先序次序输入二叉树中节点的值\n";
	BiTree T;
	create(T);
	PostOrderTraverse1(T,visit);

}