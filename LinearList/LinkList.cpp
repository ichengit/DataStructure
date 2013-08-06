#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node,*LinkList;

/*创建链表*/
LinkList CreateList(){
	LinkList L = (LinkList)malloc(sizeof(node));
	L->next = NULL;
	return L;
}

/*初始化链表*/
void InitList(LinkList &L){
	struct node *end = L,*p;
	cout << "链表初始化时元素个数:";
	int n;
	cin >> n;
	cout << "\n输入这" << n << "个元素:";
	for(int i = 0;i < n;i++){
		p = (struct node*)malloc(sizeof(node));
		cin >> p->data;
		p->next = NULL;
		end->next = p;
		end = p;
	}
}


/*获取链表中第i个元素*/
struct node *GetElem(LinkList &L,int i){
	if(i == 0)
		return L;
	if(i < 0)
		return NULL;
	struct node *p = L->next;
	int j = 1;
	while(p && j < i){
		p = p->next;
		j++;
	}
	return p;
}

/*向链表中插入元素*/
void InsertData(LinkList &L,int location,int data){
	struct node *pre = GetElem(L,location - 1);	//获取第location个元素的直接前驱
	if(pre == NULL){
		cout << "插入位置不正确\n";
		return;
	}
	struct node *node = (struct node *)malloc(sizeof(node));
	node->data = data;	
	node->next = pre->next;
	pre->next = node;
}

/*删除第i个元素*/
void DeleteData(LinkList &L,int location){
	struct node *pre = GetElem(L,location - 1);
	if(pre == NULL){
		cout << "插入位置不正确\n";
		return;
	}
	pre->next = pre->next->next;
}

/*输出链表中所有元素*/
void ShowList(LinkList &L){
	struct node *p = L->next;
	if(!p){
		cout << "链表为空";
		return;
	}
	while(p){
		cout << p->data << " ";
		p = p->next;
	}
}

void main(){
	LinkList L = CreateList();
	InitList(L);
	ShowList(L);
	cout << "\n输入插入元素位置:";
	int location;
	cin >> location;
	cout << "\n输入元素值:";
	int data;
	cin >> data;
	InsertData(L,location,data);
	ShowList(L);
	cout << "\n输入删除元素位置:";
	cin >> location;
	DeleteData(L,location);
	ShowList(L);
}