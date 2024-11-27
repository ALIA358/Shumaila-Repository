//Task 3:

 #include<iostream>
 using namespace std;
 
 
 struct StudentGrading{  //structure definition
	char name[20];
	int SAPID;
	char address[20];
	char department[20];
	float marksSubject1;
	float marksSubject2;
		
};
 
 float calculateMaxMarks(float marksSubject1, float marksSubject2 ){  //function def and decleration
 float MaxMarks= marksSubject1; 
     if( MaxMarks<marksSubject2) 	
        MaxMarks=marksSubject2;
        return  MaxMarks;
 }
 
 void displayStudent(const StudentGrading& student){
   cout<<" Name:"<<student.name<<endl;
   cout<<"SAPID :"<<student.SAPID<<endl;
   cout<<"Address :"<<student.address<<endl;
   cout<<"Department :"<<student.department<<endl;
   cout<<"Marks for Subject1:"<<student.marksSubject1<<endl;
   cout<<"Marks for Subject1:"<<student.marksSubject2<<endl;
   cout<<"Max marks are:"<<calculateMaxMarks(student.marksSubject1,student.marksSubject2 ); //function call
    cout << "----------------------------------------\n";
   
    cout<<endl;
 }  
 
 int main()
{   
  StudentGrading s1[5];
 //INPUT INFO
   for(int i=0; i<5; i++){
   	cout<<"Enter info for student:"<<i+1<<endl;
   	cout<<"Enter your name:"<<endl;
   	cin.ignore();
	cin.getline(s1[i].name,20);
	
	cout<<"Enter your sap id:"<<endl;
	cin>>s1[i].SAPID;
	
	cout<<"Enter your address:"<<endl;
		cin.ignore();
	cin.getline(s1[i].address,20);
	
	cout<<"Enter your department:"<<endl;
		cin.ignore();
	cin.getline(s1[i].department,20);
	
	cout<<"Enter your marks for Subject1:"<<endl;
	cin>>s1[i].marksSubject1;
	
	cout<<"Enter your marks for Subject2:"<<endl;
	cin>>s1[i].marksSubject2;
	cout<<endl;
	cout << "----------------------------------------\n";
   }
   
    // Display information for all students
    cout << "\nDisplaying Student Information:\n";
    for (int i = 0; i < 5; i++) {
    	cout<<"Info for student:"<<i+1<<endl;
        displayStudent(s1[i]); //function call
       
        cout<<endl;
    }  
return 0;
}
