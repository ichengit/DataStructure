#include<iostream>
#include "sort.h"
using namespace std;
int main(){
	int a[] = {12,2,78,1,9543,5002,778,34,34522,441};
	merge_sort(a,0,9);
	for(int i = 0;i < 10;i++)
		cout << a[i] <<" ";
}