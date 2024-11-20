#include<iostream>
using namespace std;
int main()
{
  int a=10;	
	cout<<&a<<endl;
	
 int *ptr;  
 ptr = &a;
 cout<<*ptr<<endl;	
	
	int c =100;
		cout<<&c<<endl;
	
	
	int *newptr;
	  newptr=&c;

	cout<<*newptr<<endl;
	
 return 0;
}