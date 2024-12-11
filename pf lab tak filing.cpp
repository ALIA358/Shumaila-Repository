#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	//Creating a file
	ofstream File(" newfile.txt ");
	
	File<<"I'm doing my pf lab task!";
	File.close();
	
	string Text;
	//Reading data from the file
	ifstream readFile(" newfile.txt ");
	
	while(getline(readFile, Text)){
		cout<<Text;
	}
	readFile.close();
	
 return 0;
}