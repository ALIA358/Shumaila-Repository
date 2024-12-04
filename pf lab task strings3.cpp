#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string str;
	
	str ="HelloWorld!";
	                                  //lengnth and append are user defined functions.
	int length = str.length();
   
	cout<<"The lenght of string: "<<	str <<" is: "<<length<<endl;
	
	return 0;
}