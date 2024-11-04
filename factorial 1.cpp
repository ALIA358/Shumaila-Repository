#include<iostream>
using namespace std;
int main()
{
	
int a;
long s=1;
cout<<"enter a no to find fictorial"<<endl;
cin>>a;

for(int i=1; i<a; i++)
{
		s*=i ;
}

	cout<<"Factorial of "<<a<<" is "<<s;
return 0;
}
