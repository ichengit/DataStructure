#include<iostream>
#include<cmath>
using namespace std;

#define INIT_SIZE 100 
#define INCREMENT 10 

typedef struct{
	int * data;
	int length;
	int listsize;
}SqList;

/*初始化顺序表*/
void InitList(SqList &L){
	L.data = (int *)malloc(INIT_SIZE * sizeof(int));
	L.length = 0;
	L.listsize = INIT_SIZE;
}

/*返回线性表长年*/
int length(SqList &L){
	return L.length;
}

/*输出顺序表中的元素*/
void ShowList(SqList &L){
	if(L.length == 0)
		cout << "空集\n";
	for(int i = 0;i < L.length;i++)
		cout << L.data[i] << " ";
	cout << "\n";
}

/*获取第i个元素*/
int GetElem(SqList &L,int i){
	return L.data[i - 1];
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

void PowerSet(int i,SqList L1,SqList &L2){
	if(i > L1.length)
		ShowList(L2);
	else{
		int x = GetElem(L1,i);
		int k = length(L2);
		InsertData(L2,k + 1,x);
		PowerSet(i + 1,L1,L2);
		DeleteData(L2,k + 1,x);
		PowerSet(i + 1,L1,L2);
	}
}

/*判断当前摆放是否合法*/
bool IsLegal(int location[],int i){
	for(int k = 0;k < i;k++)
		if(location[k] == location[i] || i - k == abs(location[i] - location[k]))
			return false;
	return true;
}

/*打印摆放位置*/
void ShowQueen(int location[],int n){
	for(int i = 0;i < n;i++){
		cout << "|";
		for(int j = 0;j < location[i];j++)
			cout << " |";
		cout << "Q|";
		for(j++;j < n;j++)
			cout << " |";
		cout << "\n";
	}
	cout << "\n";
}


/*八皇后*/
void EightQueen(int i,int n,int location[]){
	if(i == n)
		ShowQueen(location,n);
	else{
		for(int j = 0;j < n;j++){
			location[i] = j;
			if(IsLegal(location,i))
				EightQueen(i + 1,n,location);
		}
	}	
}

void main(){
	int location[8];
	EightQueen(0,8,location);
}
