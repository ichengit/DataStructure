#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node,*LinkList;

/*��������*/
LinkList CreateList(){
	LinkList L = (LinkList)malloc(sizeof(node));
	L->next = NULL;
	return L;
}

/*��ʼ������*/
void InitList(LinkList &L){
	struct node *end = L,*p;
	cout << "�����ʼ��ʱԪ�ظ���:";
	int n;
	cin >> n;
	cout << "\n������" << n << "��Ԫ��:";
	for(int i = 0;i < n;i++){
		p = (struct node*)malloc(sizeof(node));
		cin >> p->data;
		p->next = NULL;
		end->next = p;
		end = p;
	}
}


/*��ȡ�����е�i��Ԫ��*/
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

/*�������в���Ԫ��*/
void InsertData(LinkList &L,int location,int data){
	struct node *pre = GetElem(L,location - 1);	//��ȡ��location��Ԫ�ص�ֱ��ǰ��
	if(pre == NULL){
		cout << "����λ�ò���ȷ\n";
		return;
	}
	struct node *node = (struct node *)malloc(sizeof(node));
	node->data = data;	
	node->next = pre->next;
	pre->next = node;
}

/*ɾ����i��Ԫ��*/
void DeleteData(LinkList &L,int location){
	struct node *pre = GetElem(L,location - 1);
	if(pre == NULL){
		cout << "����λ�ò���ȷ\n";
		return;
	}
	pre->next = pre->next->next;
}

/*�������������Ԫ��*/
void ShowList(LinkList &L){
	struct node *p = L->next;
	if(!p){
		cout << "����Ϊ��";
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
	cout << "\n�������Ԫ��λ��:";
	int location;
	cin >> location;
	cout << "\n����Ԫ��ֵ:";
	int data;
	cin >> data;
	InsertData(L,location,data);
	ShowList(L);
	cout << "\n����ɾ��Ԫ��λ��:";
	cin >> location;
	DeleteData(L,location);
	ShowList(L);
}