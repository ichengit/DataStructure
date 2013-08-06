#include "sort.h"

void insertion_sort(int a[],int n){
	for(int i = 1;i < n;i++){
		int key = a[i];
		int j = i - 1;
		while(j >= 0 && a[j] > key){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void merge(int a[],int p,int q,int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int * temp1 = new int[n1];
	int * temp2 = new int[n2];
	for(int i = 0;i < n1;i++)
		temp1[i] = a[p + i];
	for(int j = 0;j < n2;j++)
		temp2[j] = a[q + 1 + j];
	i = 0;
	j = 0;
	for(int k = p;k <= r;k++){
		if(i == n1){	//temp1数组已经复制完
			while(k <= r)
				a[k++] = temp2[j++];
			break;
		}
		else if(j == n2){	//temp2数组已经复制完
			while(k <= r)
				a[k++] = temp1[i++];
			break;
		}
		if(temp1[i] <= temp2[j]){
			a[k] = temp1[i];
			i++;
		}
		else{
			a[k] = temp2[j];
			j++;
		}
	}
	delete temp1;
	delete temp2;
}

void merge_sort(int a[],int p,int r){
	if(p < r){
		int q = (p + r) / 2;
		merge_sort(a,p,q);
		merge_sort(a,q + 1,r);
		merge(a,p,q,r);
	}
}
