#include<iostream>
//#include<string.h>


using namespace std;

int similarity(string s)
{

   int count=0;
   //count=strlen(s);
   for(int i=0;s[i]!='\0';++i)
     count++;
   
   for(int i=1;s[i] !='\0';++i)
   {
   	for(int j=0, k=i; s[k]!='\0';++k,++j)
   	{
   		if(s[j] != s[k])
   		{
                   break;   			
   		}
   		else
   		  count++;
   	}
        	
     
   }
   
   return count;	
	
}

int main()
{
	int t;
	cin>>t;
	string str[t];
	//int count[t];
	for(int i=0; i<t;++i)
	{
	 cin>>str[i];
	}
	
	for(int i=0;i<t;++i)
	{
          cout<<similarity(str[i])<<"\n";	
          
	}
	/*for(int i=0;i<t;++i)
	{
           cout<<count[i]<<"\n";	
	}*/
	
       return 0;	
}
