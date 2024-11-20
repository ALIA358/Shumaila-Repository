#include<iostream>
using namespace std;

//function decleration
void sum(int a , int b);
void mul(int a , int b);
void sub(int a , int b);

int main()
{
	int a , b;
  cout<<"Enter 2 number :"<<endl;
  cin>>a>>b;	
 
 sum(a,b);  // function call		
 mul(a , b);   // function call	
 sub(a , b);    // function call	
		
  return 0;
}
//function definition
  void sum(int a , int b)
{
	int s= a+b;
     cout<<"Sum of "<<a<<" and"<<b<<" is :"<<s<<endl;
}
//function definition
void mul(int a , int b)
{
  int m=a*b;
  cout<<"Product of "<<a<<" and"<<b<<" is :"<<m<<endl;
}
//function definition
void sub(int a , int b)
{
	int t=a-b;
	 cout<<"Subtraction of "<<a<<" and"<<b<<" is :"<<t<<endl;
}








