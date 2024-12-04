#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string str1, str2;
	
	str1 ="Hello ";
	str2 ="World!";
	
	//concatenating using + operator
	string result = str1 + str2;
	
	cout<<"Concatenated string: "<<result;
	
	
	
	return 0;
}