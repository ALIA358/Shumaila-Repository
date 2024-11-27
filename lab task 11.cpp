/*Task 1:
?The Book structure includes members for the book's title, author, year of publication, and number of pages.
?Functions are defined to input information and display information about a book.
?The main function creates an array of 5 Book structures, inputs information for each book, and then displays the information for each book.
 Task 2:
?The User structure has a member variable name to store the username. 
?The program prompts the user to enter their username, simulates a login process (you should replace this with actual authentication logic),
 and then displays a personalized welcome message upon successful login.
    Task 3:
?Create a Structure named StudentGrading for collecting information about a student, such as name, SAP ID, address, department, and marks for two subjects.
?The calculateMaxMarks function calculates the maximum marks for a student based on their performance in the two subjects.
?The displayStudent function showcases the student's information, including their name, SAP ID, address, department, marks for two subjects,
 and the calculated maximum marks.
?The main function acts as the program's entry point. It creates an array of Student structures to manage details for five students.
 It utilizes loops to input information, calculate maximum marks, and then display the overall information for each student.*/
 #include<iostream>
 using namespace std;
 
 struct Book{  //struct is user defined not build in
	char title[20];
	char author[20];
	int yearOfPublication;
	int noOfPages;
	
};
int main()
{
	Book book[5];
	
	for(int i=0; i<5; i++){
		cout<<"Enter the details for Book "<<i+1<<": "<<endl;
		cout<<"Enter the title: "<<endl;
		cin.getline(book[i].title,20);
		
		cout<<"Enter the author :"<<endl;
	    cin.getline(book[i].author,20);
		
		cout<<"Enter the  year of publication:"<<endl;
		cin>>book[i].yearOfPublication;
		
		cout<<"Enter the no. of pages:"<<endl;
	    cin>>book[i].noOfPages;
		 cout<<endl;
		//Clear the input buffer
	    	cin.ignore();
	}cout<<endl;
	for(int i=0; i<5; i++) {
	 	cout << "Information for Book "<<i+1<<endl;
	 	cout<<"Title:"<<book[i].title<<endl;
	 	cout<<"Author"<<book[i].author<<endl;
	 	cout<<"Year Of Publication:"<<book[i].yearOfPublication<<endl;
	 	cout<<"No. of pages:"<<book[i].noOfPages<<endl;
	 	
	 cout<<endl; 	
	} cout<<endl;
	
return 0;
}
	
	