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

/*初始化顺序表*/
void InitList(SqList &L){
	L.data = (int *)malloc(INIT_SIZE * sizeof(int));
	L.length = 0;
	L.listsize = INIT_SIZE;
}

/*输出顺序表中的元素*/
void ShowList(SqList &L){
	if(L.length == 0)
		cout << "顺序表为空\n";
	for(int i = 0;i < L.length;i++)
		cout << L.data[i] << " ";
}

/*向顺序表中插入一个元素*/
void InsertData(SqList &L,int location,int data){
	if(location < 1 || location > L.length + 1){
		cout << "插入位置不正确\n";
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

/*从顺序表中删除一个元素*/
void DeleteData(SqList &L,int location,int &data){
	if(location < 1 || location > L.length){
		cout << "删除位置错误\n";
		return;
	}
	for(int i = location - 1;i < L.length - 1;i++)
		L.data[i] = L.data[i + 1];
	L.length--;
}

/*删除顺序表中值为x的元素*/
void delete_x(SqList &L,int x){
	int k = 0;
	for(int i = 0;i < L.length;i++){
		if(L.data[i] != x){
			L.data[k++] = L.data[i];
		}
	}
	L.length = k;
}

/*倒置所有元素*/
void ReverseList(SqList &L,int start,int end){
	int mid = (end - start) / 2;
	for(int i = 0;i <= mid;i++){
		int temp = L.data[start + i];
		L.data[start + i] = L.data[end - i];
		L.data[end - i] = temp;
	}
}

/*交换顺序表中前后两部分的位置*/
void exchange(SqList &L,int p){	//p为前一部分元素个数
	ReverseList(L,0,p - 1);	//倒置前p个元素
	ReverseList(L,p,L.length - 1); //倒置剩余元素
	ReverseList(L,0,L.length - 1);	//倒置顺序表所有元素
}

/*找出两个升序序列的中位数*/
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
	cout << "输入初始化顺序表中元素个数: ";
	cin >> n;
	cout << "\n输入这" << n << "个元素:\n";

	InitList(L1);	//初始化
	InitList(L2);
	for(int i = 1;i <= n;i++){	//插入原始数据
		int temp;
		cin >> temp;
		InsertData(L1,i,temp);
	}
	ShowList(L1);
	for(i = 1;i <= n;i++){	//插入原始数据
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
	cout << "\n选择操作类型(插入:i,删除:d,退出:q):";
	getchar();
	while(flag){		
		switch(getchar()){
		case 'i':
			cout << "\n输入插入位置:";
			cin >> location;
			cout << "\n输入插入元素:";
			cin >> data;
			InsertData(L,location,data);
			ShowList(L);
			break;
		case 'd':
			cout << "输入删除位置:";
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
		
		cout << "\n选择操作类型(插入:i,删除:d,退出:q):";getchar();
	}*/
}


