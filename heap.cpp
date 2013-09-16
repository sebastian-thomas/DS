/* Heap using array A[1...n] */

#include<iostream>
#define length 10
using namespace std;

int parent(int i){
  return i/2;
}

int left(int i){
  return 2*i;
}

int right(int i){
  return 2*i+1;
}

void max_heapify(int A[], int i , int heapSize){
   int l ,temp, r , largest=i;
   l = left(i);
   r = right(i);
   if(l <= heapSize && A[i] < A[l]){
	   largest = l;
   }
   if(r <= heapSize && A[largest] < A[r]){
	   largest = r;
   }
   if(i != largest){
	   temp = A[i];
	   A[i] = A[largest];
	   A[largest] = temp;
	   max_heapify(A,largest,heapSize);
   }
}

void build_max_heap(int A[], int heapSize){
  int i;
  for(i = heapSize/2 ; i >=1 ; --i){
    max_heapify(A,i,heapSize);
  }
}

void heapSort(int A[] , int heapSize){
  int temp, len;
  build_max_heap(A,heapSize);
  len = heapSize;
  for(int i = len ; i > 1; --i ){
    temp = A[i];
    A[i] = A[1];
    A[1] = temp;
    heapSize = heapSize -1;
    max_heapify(A,1,heapSize);
  }
}

void insert_max_heap (int A[] , int &heapSize, int val){
  int p, temp;
  if(heapSize+1 < length){
    heapSize = heapSize + 1;
    A[heapSize] = val;
    for(int i = heapSize; i >1; ){
         p = parent(i);
         if(A[p] < A[i]){
           temp = A[p];
           A[p] = A[i];
           A[i] = temp;
           i = p;
         }
         else{
          break;
         }
    }
  }
  else{
    cout<<"No more space";
  }
   
}

int main(){
  int A[length] , n;
  cout<<"Heap Size:";
  cin >> n;
  cout<<"Elem:";
  for(int i=1 ;i <= n ;++i ){
    cin>>A[i];
  }
  build_max_heap(A,n);
  for(int i=1 ;i <= n; ++i){
    cout <<A[i]<<" ";
  }
  /*cout<<"\nSorting\n";
  heapSort(A,n);
  for(int i=1 ;i <= n; ++i){
    cout <<A[i]<<" ";
  }*/
  insert_max_heap(A,n,99);
  insert_max_heap(A,n,5);
  cout<<"\n";
  for(int i=1 ;i <= n; ++i){
    cout <<A[i]<<" ";
  }
  return 0;
}
