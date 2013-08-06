#include<iostream>
#include<cstdlib>
#define INITSIZE 100
#define INCREMENT 10
using namespace std;
typedef char ElemType;
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}Stack;

void init(Stack &stack){
	stack.base = stack.top = (ElemType *)malloc(INITSIZE * sizeof(ElemType));
	stack.stacksize = INITSIZE;
}

void push(Stack &stack,ElemType data){
	if(stack.top - stack.base >= stack.stacksize){
		stack.base = (ElemType *)realloc(stack.base,(stack.stacksize + INCREMENT) * sizeof(ElemType));
		stack.top = stack.base + stack.stacksize;
		stack.stacksize += INCREMENT;
	}
	*stack.top++ = data;
}

void pop(Stack &stack,ElemType &data){
	if(stack.base == stack.top){
		cout << "ջΪ��\n";
		return;
	}
	data = *(--stack.top);
}

ElemType GetTop(Stack &stack){
	return *(stack.top - 1);
}

void ShowStack(Stack stack){
	while(stack.top != stack.base)
		cout << *--stack.top << " ";
}

void destroy(Stack &stack){
	free(stack.base);
}

void clear(Stack &stack){
	while(stack.base < stack.top)
		stack.top--;
}

int length(Stack &stack){
	return stack.top - stack.base;
}

bool empty(Stack &stack){
	return stack.base == stack.top;
}

void traverse(Stack stack){
	while(stack.base < stack.top)
		cout << *stack.base++;
}
void conversion(int n,int radix){	//����ת������ʱ���ElemType��Ϊint
	Stack stack;
	init(stack);
	while(n){
		push(stack,n % radix);
		n /= radix;
	}
	ShowStack(stack);
	destroy(stack);
}

bool pattern(){	//����ƥ�䣬��ʱ���ElemType��Ϊchar
	Stack stack;
	init(stack);
	char ch,last;
	cout << "�����ƥ�����������:\n";
	while((ch = getchar()) != '\n'){
		switch(ch){
		case '[':
		case '(':
		case '{':
			push(stack,ch);
			break;
		case ']':
			if(empty(stack))
				return false;
			pop(stack,last);
			if(last != '[')
				return false;
			break;
		case ')':
			if(empty(stack))
				return false;
			pop(stack,last);
			if(last != '(')
				return false;
			break;
		case '}':
			if(empty(stack))
				return false;
			pop(stack,last);
			if(last != '{')
				return false;
			break;
		default:
			cout << "��������\n";
			exit(-1);
		}
	}
	if(empty(stack))
		return true;
	return false;
}

void LineEdit(){
	Stack stack;
	char ch,c;
	init(stack);
	while((ch = getchar()) != EOF){

		switch(ch){
		case '#':
			pop(stack,c);
			break;
		case '@':
			clear(stack);
			break;
		default:
			push(stack,ch);
			break;
		}
	}
	traverse(stack);
}
void main(){
	LineEdit();
}