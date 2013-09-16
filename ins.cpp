/* Insertion Sort */

#include<iostream>
using namespace std;

void insSort(int A[] ,int n){
	int i , j , tmp;
	for(i=1; i < n; ++i){
		tmp = A[i];
		j = i;
		for(j=i; j > 0 && A[j-1] > tmp ; --j){
			A[j] = A[j-1];
		}
		A[j] = tmp;
	}
}

void printArray(int A[] ,int n){
	cout<<"\n";
	for(int i=0; i < n; ++i)
		cout<<A[i]<<" ";
}

int main(){
	int A[10], n;
	cin >> n;
	for(int i=0; i<n;++i)
		cin>>A[i];
	insSort(A,n);
	printArray(A,n);
	return 0;
}