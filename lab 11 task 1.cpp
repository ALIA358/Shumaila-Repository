//Task 2:
 #include<iostream>
 using namespace std;
 
 struct User{  
	string variableName;	
};
int main()
{
	User username;
	string Username="Has*123";
	cout<<"Enter your username:"<<endl;
	getline(cin,username.variableName);
    
    if(username.variableName==Username){
    	cout<<"You are successfully logged in!"<<endl;
	}
    else
    cout<<"Invalid username!!!"<<endl;
	
return 0;
}
