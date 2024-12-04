#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string str1, str2;
	
	str1 ="Hello ";
	str2 ="World!";
	
    cout<<"Concatenated string: "<< str1.append(str2);
	
	
	return 0;
}