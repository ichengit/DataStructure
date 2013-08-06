#include<iostream>
#include<cstdlib>

#define INIT_SIZE 100 
#define INCREMENT 10 

typedef struct{
	int * data;
	int length;
	int listsize;
}SqList;

using namespace std;

/*��ʼ��˳���*/
void InitList(SqList &L){
	L.data = (int *)malloc(INIT_SIZE * sizeof(int));
	L.length = 0;
	L.listsize = INIT_SIZE;
}

/*���˳����е�Ԫ��*/
void ShowList(SqList &L){
	if(L.length == 0)
		cout << "˳���Ϊ��\n";
	for(int i = 0;i < L.length;i++)
		cout << L.data[i] << " ";
}

/*��˳����в���һ��Ԫ��*/
void InsertData(SqList &L,int location,int data){
	if(location < 1 || location > L.length + 1){
		cout << "����λ�ò���ȷ\n";
		return;
	}
	if(L.length == L.listsize){
		L.data = (int *)realloc(L.data,(L.listsize + INCREMENT) * sizeof(int));
		L.listsize += INCREMENT;
	}
	for(int p = L.length - 1;p >= location - 1;p--)
		L.data[p + 1] = L.data[p];
	L.data[location - 1] = data;
	L.length += 1;
}

/*��˳�����ɾ��һ��Ԫ��*/
void DeleteData(SqList &L,int location,int &data){
	if(location < 1 || location > L.length){
		cout << "ɾ��λ�ô���\n";
		return;
	}
	for(int i = location - 1;i < L.length - 1;i++)
		L.data[i] = L.data[i + 1];
	L.length--;
}

/*ɾ��˳�����ֵΪx��Ԫ��*/
void delete_x(SqList &L,int x){
	int k = 0;
	for(int i = 0;i < L.length;i++){
		if(L.data[i] != x){
			L.data[k++] = L.data[i];
		}
	}
	L.length = k;
}

/*��������Ԫ��*/
void ReverseList(SqList &L,int start,int end){
	int mid = (end - start) / 2;
	for(int i = 0;i <= mid;i++){
		int temp = L.data[start + i];
		L.data[start + i] = L.data[end - i];
		L.data[end - i] = temp;
	}
}

/*����˳�����ǰ�������ֵ�λ��*/
void exchange(SqList &L,int p){	//pΪǰһ����Ԫ�ظ���
	ReverseList(L,0,p - 1);	//����ǰp��Ԫ��
	ReverseList(L,p,L.length - 1); //����ʣ��Ԫ��
	ReverseList(L,0,L.length - 1);	//����˳�������Ԫ��
}

/*�ҳ������������е���λ��*/
int find_mid(SqList &L1,SqList &L2){
	int s1 = 0,d1 = L1.length - 1,m1,s2 = 0,d2 = L2.length - 1,m2;
	while(s1 != d1 || s2 != d2){
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if(L1.data[m1] == L2.data[m2])
			return L1.data[m1];
		else if(L1.data[m1] < L2.data[m2]){
			if((s1 + d1) % 2 == 0){
				s1 = m1;
				d2 = m2;	
			}
			else{
				s1 = m1 + 1;
				d2 = m2;
			}
		}
		else{
			if((s2 + d2) % 2 == 0){
				d1 = m1;
				s2 = m2;
			}
			else{
				d1 = m1;
				s2 = m2 + 1;
			}
		}
	}
	return L1.data[s1] <= L2.data[s2] ? L1.data[s1]:L2.data[s2];
}

void main(){
	SqList L1,L2;	
	int n;
	cout << "�����ʼ��˳�����Ԫ�ظ���: ";
	cin >> n;
	cout << "\n������" << n << "��Ԫ��:\n";

	InitList(L1);	//��ʼ��
	InitList(L2);
	for(int i = 1;i <= n;i++){	//����ԭʼ����
		int temp;
		cin >> temp;
		InsertData(L1,i,temp);
	}
	ShowList(L1);
	for(i = 1;i <= n;i++){	//����ԭʼ����
		int temp;
		cin >> temp;
		InsertData(L2,i,temp);
	}
	ShowList(L2);
	cout << find_mid(L1,L2);
	/*int location;
	int data;
	char operation;
	bool flag = true;
	cout << "\nѡ���������(����:i,ɾ��:d,�˳�:q):";
	getchar();
	while(flag){		
		switch(getchar()){
		case 'i':
			cout << "\n�������λ��:";
			cin >> location;
			cout << "\n�������Ԫ��:";
			cin >> data;
			InsertData(L,location,data);
			ShowList(L);
			break;
		case 'd':
			cout << "����ɾ��λ��:";
			cin >> location;
			DeleteData(L,location,data);
			ShowList(L);
			break;
		case 'q':
			flag = false;
			break;
		default:
			break;
		}
		
		cout << "\nѡ���������(����:i,ɾ��:d,�˳�:q):";getchar();
	}*/
}


