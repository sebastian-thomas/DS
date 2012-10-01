
#include<iostream>
using namespace std;

void sort_cost(int a[] , int n, int k)
{
	int small,pos,temp;
	
	  
   for(int i=0; i<n ; ++i)
   {
   	small=a[i];
   	pos=i;
   	for(int j=i;j<n;++j)
   	{
   	   if(a[j]<small)
   	     {
   	        small=a[j];
   	        pos=j;	
   	     }	
   	}
   	temp=a[i];
   	a[i]=a[pos];
   	a[pos]=temp;
   	
   }	
}

int main()
{
	 int n,k,totalcost=0,noflowers=0,kcount=0;
	 int *cost;
	 cin>>n>>k;
	 cost= new int[n];
	 for(int i=0; i<n ;++i)
	  cin>>cost[i];
	 
	 sort_cost(cost, n ,k);

    for(int i=0; i<n; ++i)
    {
        	totalcost+= (noflowers+1)*cost[i];
        	kcount++;
        	if(kcount==k)
        	{
        	 	kcount=0;
        	 	noflowers++;
        	}
        	
    }	 
	 cout<<totalcost<<"\n";
    return 0;	
}
