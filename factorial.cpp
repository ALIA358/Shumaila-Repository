#include<iostream>
using namespace std;
int main()
{
	
int a,s;
                                          // long mai -ve sy ly k +ve tk saari values aati hain 4 digits hon to long 
cout<<"enter a no to find fictorial"<<endl;
cin>>a;
int i=1;

do{
	s=i*a ;
	i++;
}
	while(i<a);
	
	cout<<"Factorial of "<<a<<" is "<<s;	
	
	
	
	
	
	
	
	return 0;
}