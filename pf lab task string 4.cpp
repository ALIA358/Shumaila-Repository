#include<iostream>
#include<cstring>
using namespace std;
int main(){

char source[]="HelloWorld!";
char destination[50];     //limit/size of array

//use strcpy() to copy the source string into destination
strcpy(destination, source);

//print the copied string
cout<<"Source string: "<<source<<endl;
cout<<"Destination string: "<<destination<<endl;


	return 0;
}