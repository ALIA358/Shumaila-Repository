#include <iostream>
#include <iomanip>
#include <string>
#include<windows.h>
using namespace std; 
  
// for color in output text
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
//
const int MAX_FEES = 10;
const int MAX_SCHOLARSHIPS = 10;
const int MAX_INSTALLMENTS = 10;

// Define constants for maximum sizes
const int MAX_STUDENTS = 10;
const int MAX_ENROLLMENTS = 10;

// Struct to hold student details
struct Student {
    int rollNo;
    string name;
    string fatherName;
    int mobileNumber;
    string qualification;
    int marks;
    int year;
};

// Struct for enrollment details
struct Enrollment {
    int rollNo;
    string field;
    string status; // e.g., "Enrolled"
};

// Arrays to store data
Student students[MAX_STUDENTS] = {
    {1, "Ali Ahmed", "M. Tahir Khan", 1234567890, "Matric", 850, 2022},
    {2, "Zafar Raja", "Raja Ayub", 1234567891, "Intermediate", 920, 2021},
    {3, "Amna Tahir", "Shakeel Ahmed", 1234567892, "Matric", 870, 2022},
    {4, "Subhan Raja", "Imran Khan", 1234567893, "Intermediate", 900, 2020},
    {5, "Hira Khan", "Shazaib Mughal", 1234567894, "O-Level", 940, 2023}
};
int studentCount = 5;

Enrollment enrollments[MAX_ENROLLMENTS] = {
    {1, "Computer Science", "Enrolled"},
    {2, "Engineering", "Enrolled"},
    {3, "Medical", "Enrolled"},
    {4, "Law", "Enrolled"},
    {5, "B.com", "Enrolled"}
};
int enrollmentCount = 5;
// Struct for student information
struct Student2 {
    int rollNo;
    string name;
    string fatherName;
    int contactNo;
    string course;
};

const int maxStudents = 20;
Student2 s1[maxStudents] = {
    {1, "Ali Ahmed", "M. Tahir Khan", 1234567890, "Computer Science"},
    {2, "Zafar Raja", "Raja Ayub", 1234567891, "Engineering"},
    {3, "Amna Tahir", "Shakeel Ahmed", 1234567892, "Medical"},
    {4, "Subhan Raja", "Imran Khan", 1234567893, "Law"},
    {5, "Hira Khan", "Shazaib Mughal", 1234567894, "B.com"}
};
int total = 5;
// Structs to store information
struct FeeStructure {
    string programName;
    double feeAmount;
};

struct Scholarship {
    string grade;
    double scholarshipAmount;
};

struct InstallmentPlan {
    string planName;
    double totalAmount;
    int installments;
};

// Data containers
FeeStructure feeStructures[MAX_FEES];
Scholarship scholarships[MAX_SCHOLARSHIPS];
InstallmentPlan installmentPlans[MAX_INSTALLMENTS];

int feeCount = 0, scholarshipCount = 0, installmentCount = 0;
// Function prototypes
void manageFeeStructure();
void manageScholarshipProgram();
void manageInstallmentFacility();

// Fee Structure CRUD
void addFeeStructure();
void displayFeeStructures();
void updateFeeStructure();
void deleteFeeStructure();

// Scholarship Program CRUD
void addScholarship();
void displayScholarships();
void updateScholarship();
void deleteScholarship();

// Installment Facility CRUD
void addInstallmentPlan();
void displayInstallmentPlans();
void updateInstallmentPlan();
void deleteInstallmentPlan();

// Functions for Student Profiles module
void showStudents() {
	 setColor(5);
    if (studentCount == 0) {
        cout << "No students to display.\n";
        return;
    }
    setColor(6);
    cout << "Roll No" << setw(15) << "Name" << setw(20)
         << "Father Name" << setw(15) << "Mobile" << setw(20)
         << "Qualification" << setw(10) << "Marks" << setw(10) << "Year\n";
    cout << "-----------------------------------------------------------------------------------------\n";

    for (int i = 0; i < studentCount; i++) {
    		 setColor(3);
        cout << students[i].rollNo
             << setw(15) << students[i].name
             << setw(20) << students[i].fatherName
             << setw(15) << students[i].mobileNumber
             << setw(20) << students[i].qualification
             << setw(10) << students[i].marks
             << setw(10) << students[i].year << '\n';
    }
}
// Show all students
void Show() {
    setColor(2);
    cout << setw(20) << "Student Data" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Roll No" << setw(25) << "Name" << setw(25) << "Father Name"
         << setw(25) << "Contact No" << setw(28) << "Course" << endl;
setColor(3);
    for (int i = 0; i < total; i++) {
        cout << s1[i].rollNo << setw(25) << s1[i].name << setw(25)
             << s1[i].fatherName << setw(25) << s1[i].contactNo << setw(28)
             << s1[i].course << endl;
    }
}
//addStudent
void addStudent() {
	setColor(12);
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student list is full! Cannot add more students.\n";
        return;
    }
    setColor(2);
    Student &s = students[studentCount];
    cout << "Enter student's name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter father's name: ";
    getline(cin, s.fatherName);
    cout << "Enter roll number: ";
    cin >> s.rollNo;
    cout << "Enter mobile number: ";
    cin >> s.mobileNumber;
    cout << "Enter qualification: ";
    cin.ignore();
    getline(cin, s.qualification);
    cout << "Enter marks: ";
    cin >> s.marks;
    cout << "Enter year: ";
    cin >> s.year;

    studentCount++;
    cout<<endl<<endl;
    setColor(4);
    cout << "Student added successfully!\n";
}
// Add students
void Add() {
    int choice;
    setColor(6);
    cout << "How many students do you want to add? ";
    cin >> choice;

    for (int i = total; i < total + choice && i < maxStudents; i++) {
        setColor(2);
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> s1[i].name;
        cout << "Father Name: ";
        cin >> s1[i].fatherName;
        cout << "Roll No: ";
        cin >> s1[i].rollNo;
        cout << "Contact No: ";
        cin >> s1[i].contactNo;
        cout << "Course: ";
        cin >> s1[i].course;
    }
    total += choice;
    if (total > maxStudents) total = maxStudents;
}
//searchStudent
void searchStudent() {
	setColor(14);
    int rollNo;
    cout << "Enter roll number to search: ";
    cin >> rollNo;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
        	setColor(8);
            cout << "Student Found:\n";
            cout << "Name: " << students[i].name << '\n';
            cout << "Father's Name: " << students[i].fatherName << '\n';
            cout << "Roll Number: " << students[i].rollNo << '\n';
            cout << "Mobile: " << students[i].mobileNumber << '\n';
            cout << "Qualification: " << students[i].qualification << '\n';
            cout << "Marks: " << students[i].marks << '\n';
            cout << "Year: " << students[i].year << '\n';
            return;
        }
    }
    setColor(4);
    cout << "Student not found.\n";
}
// Search for a student
void Search() {
    int rollNo;
    setColor(6);
    cout << "Enter the roll no. to search: ";
    cin >> rollNo;

    for (int i = 0; i < total; i++) {
        if (s1[i].rollNo == rollNo) {
            setColor(2);
            cout << "Student Found!\n";
            cout << "Name: " << s1[i].name << endl;
            cout << "Father Name: " << s1[i].fatherName << endl;
            cout << "Roll No: " << s1[i].rollNo << endl;
            cout << "Contact No: " << s1[i].contactNo << endl;
            cout << "Course: " << s1[i].course << endl;
            return;
        }
    }
    setColor(4);
    cout << "Student not found!" << endl;
}
 //delete student
void deleteStudent() {  //delete student
    setColor(14);
	int rollNo;  string answer,info;
    cout << "Enter roll number to delete: ";
    cin >> rollNo;
    cout<<"Do you want to delete full information?"<<endl;
    cout<<"Or do you want to delete specific information? :"<<endl;
     cin>>answer;
     if(answer == "full information" || answer == "full" ){
     	 for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {   setColor(12);
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout<<endl<<endl;
            setColor(4);
            cout << "Student deleted successfully.\n";
            return;
        }
    }  setColor(4);
    cout << "Student not found.\n";
  }
else if(answer == "specific information" || answer == "specific" ){
	 cout<<"Enter the information you want to delete:"<<endl;
	  cin.ignore();
	   getline(cin, info);
	    for (int i = 0; i < studentCount; i++) {  if (students[i].rollNo == rollNo) { 
	if(info =="mobile number" || info =="phone number") { students[i].mobileNumber =0;  cout << "Information deleted successfully.\n"; }
	else if(info =="qualification" || info =="Qualification:") { students[i].qualification = "0";  cout << "Information deleted successfully.\n";}
	else  if(info =="Marks" || info =="marks"){students[i].marks=0; cout << "Information deleted successfully.\n";}
	else  if(info =="years" || info =="year"){students[i].year =0; cout << "Information deleted successfully.\n";}
	else  if(info =="Name" || info =="name"){students[i].name="0"; cout << "Information deleted successfully.\n";}
	else  if(info =="father Name" || info =="fatherName "){students[i].fatherName="0"; cout << "Information deleted successfully.\n";}
	else cout<<"Invalid entry!"<<endl;} 	
		}	
}
else {
 cout<<"Invalid choice" ; return ;	
}    	
	 }
// Delete student record
void Delete() {
    int rollNo;
    setColor(6);
    cout << "Enter the roll no. to delete: ";
    cin >> rollNo;

    for (int i = 0; i < total; i++) {
        if (s1[i].rollNo == rollNo) {
            for (int j = i; j < total - 1; j++) {
                s1[j] = s1[j + 1];
            }
            total--;
            setColor(2);
            cout << "Record deleted successfully!" << endl;
            return;
        }
    }  system("pause");
    setColor(4);
    cout << "Student not found!" << endl;  system("pause");
}
//update function 
void updateStudent()  //update function
{
    string answer, info,  updatedInfo;
    int rollNo;
    setColor(9);
    cout << "Enter the roll no. to update: ";
    cin >> rollNo; cout<<endl; setColor(11);
     cout<<"Do you want to  update full information?"<<endl;
    cout<<"Or do you want to update specific information? :"<<endl;
     cin>>answer;
     if(answer == "full information" || answer == "full" ){
     	for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
            setColor(6);
            cout << "Updating details for " << students[i].name << endl;
            cout << "Enter new Name: ";
            cin >> students[i].name;
            cout << "Enter new Father Name: ";
            cin >> students[i].fatherName;
            cout << "Enter new year: ";
            cin >> students[i].year;
            cout << "Enter new Contact No: ";
            cin >> students[i].mobileNumber;
            cout << "Enter new Marks: ";
            cin >> students[i].marks;
             cout << "Enter new qualification: ";
            cin >> students[i].qualification;
            setColor(2);
            cout << "Details updated successfully!" << endl;
            return;
        }  else {setColor(4);cout << "Student not found!" << endl;
	   } 
       
    }
  
  }
else if(answer == "specific information" || answer == "specific" ){
	 cout<<"Which information you want to update ? (roll number , marks ,etc.) :"<<endl;
	  cin.ignore();
	   getline(cin, info);
	   cout<<"Enter the "<< info<<" :"<<endl;
	   getline(cin, updatedInfo);
	for (int i = 0; i < studentCount; i++) {  if (students[i].rollNo == rollNo) { 
	if(info =="mobile number" || info =="phone number") { students[i].mobileNumber =stoi( updatedInfo);  cout << "Information update successfully.\n"; }
	else if(info =="qualification" || info =="Qualification:") { students[i].qualification =  updatedInfo;  cout << "Information update successfully.\n";}
	else  if(info =="Marks" || info =="marks"){students[i].marks=stoi(updatedInfo); cout << "Information updatesuccessfully.\n";}
	else  if(info =="years" || info =="year"){students[i].year = stoi(updatedInfo); cout << "Information deleted update uccessfully.\n";}
	else  if(info =="Name" || info =="name"){students[i].name= updatedInfo; cout << "Information update successfully.\n";}
	else  if(info =="father Name" || info =="fatherName "){students[i].fatherName= updatedInfo; cout << "Information updated successfully.\n";}
	} 
		}	
    
}
 else{  cout<<endl;  setColor(4);cout<<"Invalid choice.";
 }  
	
}   
   	
   
// Update student details
void Update() {
    int rollNo;
    setColor(2);
    cout << "Enter the roll no. to update: ";
    cin >> rollNo;

    for (int i = 0; i < total; i++) {
        if (students[i].rollNo == rollNo) {
            setColor(6);
            cout << "Updating details for " << students[i].name << endl;
            cout << "Enter new Name: ";
            cin >> s1[i].name;
            cout << "Enter new Father Name: ";
            cin >> s1[i].fatherName;
            cout << "Enter new Roll No: ";
            cin >> s1[i].rollNo;
            cout << "Enter new Contact No: ";
            cin >> s1[i].contactNo;
            cout << "Enter new Course: ";
            cin >> s1[i].course;
            setColor(2);
            cout << "Details updated successfully!" << endl;
            return;
        }
    }
    setColor(4);
    cout << "Student not found!" << endl;
}
//function for complaint
void complaint() {
    string complaint_Text;
    setColor(6);
    cout << "Enter complaint: "<<endl;
    cin.ignore();
    getline(cin,complaint_Text);
    setColor(2);
    cout << "Your complaint has been recorded." << endl;
}
   
// Functions for Enrollment module
void enrollment() {
    string answer;
    setColor(11);
    cout << "Are you a user or an admin? : ";
    cin >> answer;
    setColor(4);
    if (answer == "user" || answer == "User") {  setColor(11);
        if (enrollmentCount == 0) {
            cout << "No enrollments to display.\n";
            return;
        }
         setColor(6);
        cout << "Enrollment Records:\n";
        cout << "Roll No" << setw(15) << "Course" << setw(15) << "Status\n";
        cout << "-----------------------------------\n";
         setColor(8);
        for (int i = 0; i < enrollmentCount; i++) {
            cout << enrollments[i].rollNo
                 << setw(15) << enrollments[i].field
                 << setw(15) << enrollments[i].status << '\n';
        }system("pause");
    } else if (answer == "admin" || answer == "Admin") {
        int choice;
        do {   setColor(10);
            cout << "\nAdmin Enrollment Menu\n";
            cout << "1. Enroll Student in a Course\n";
            cout << "2. Show Enrollments\n";
            cout << "3. Search Enrollment\n";
            cout << "4. Delete Enrollment\n";
            cout << "5. Back to Main Menu\n";
            cout<<endl<<endl;
             setColor(14);
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {   setColor(4);
                    if (enrollmentCount >= MAX_ENROLLMENTS) {
                        cout << "No space available for more enrollments.\n";
                        break;
                    }
                     setColor(14);
                    int rollNo;
                    cout << "Enter roll number to enroll: ";
                    cin >> rollNo;

                    int studentIndex = -1;
                    for (int i = 0; i < studentCount; i++) {
                        if (students[i].rollNo == rollNo) {
                            studentIndex = i;
                            break;
                        }
                    }

                    if (studentIndex == -1) {    setColor(4);
                        cout << "Student with roll number " << rollNo << " not found.\n";
                        break;
                    }
                  setColor(10);
                    cout << "Student Found:\n";
                    cout << "Name: " << students[studentIndex].name << '\n';
                    cout << "Available Courses:\n";
                    cout << "1. Mathematics\n";
                    cout << "2. Physics\n";
                    cout << "3. Chemistry\n";
                    cout << "4. Computer Science\n";
                    cout << "5. English\n";
                    cout<<endl<<endl;
                     setColor(4);
                    cout << "Enter the course to enroll in: ";

                    int courseChoice;
                    cin >> courseChoice;

                    string selectedCourse;
                    switch (courseChoice) {
                        case 1: selectedCourse = "Mathematics"; break;
                        case 2: selectedCourse = "Physics"; break;
                        case 3: selectedCourse = "Chemistry"; break;
                        case 4: selectedCourse = "Computer Science"; break;
                        case 5: selectedCourse = "English"; break;
                        default:  
						   setColor(4);
                            cout << "Invalid choice. Enrollment failed.\n";
                            break;
                    }

                    if (selectedCourse != "") {
                        enrollments[enrollmentCount].rollNo = rollNo;
                        enrollments[enrollmentCount].field = selectedCourse;
                        enrollments[enrollmentCount].status = "Enrolled";
                        enrollmentCount++; 
                        cout<<endl<<endl;
                         setColor(4);
                        cout << "Enrollment in " << selectedCourse << " completed successfully!\n";
                    }
                    break;
                }
                case 2:
                    if (enrollmentCount == 0) {  setColor(4);
                        cout << "No enrollments to display.\n";
                        break;
                    }
                   setColor(6);
                    cout << "Roll No" << setw(15) << "Course" << setw(15) << "Status\n";
                    cout << "-----------------------------------\n";
                    setColor(8);
                    for (int i = 0; i < enrollmentCount; i++) {
                        cout << enrollments[i].rollNo
                             << setw(15) << enrollments[i].field
                             << setw(15) << enrollments[i].status << '\n';
                    }
                    break;
                case 3: {
                    int rollNo;  setColor(14);
                    cout << "Enter roll number to search enrollment: ";
                    cin >> rollNo;

                    int enrollmentIndex = -1;
                    for (int i = 0; i < enrollmentCount; i++) {
                        if (enrollments[i].rollNo == rollNo) {
                            enrollmentIndex = i;
                            break;
                        }
                    }

                    if (enrollmentIndex == -1) {  setColor(4);
                        cout << "Enrollment not found for roll number " << rollNo << ".\n";
                    } else {  setColor(14);
                        cout << "Enrollment Found:\n";
                        cout << "Roll No: " << enrollments[enrollmentIndex].rollNo << '\n';
                        cout << "Course: " << enrollments[enrollmentIndex].field << '\n';
                        cout << "Status: " << enrollments[enrollmentIndex].status << '\n';
                    }
                    break;
                }
                case 4: {
                    int rollNo;
                   	 setColor(14);
                    cout << "Enter roll number to delete enrollment: ";
                    cin >> rollNo;

                    int enrollmentIndex = -1;
                    for (int i = 0; i < enrollmentCount; i++) {
                        if (enrollments[i].rollNo == rollNo) {
                            enrollmentIndex = i;
                            break;
                        }
                    }

                    if (enrollmentIndex == -1) { setColor(4);
                        cout << "Enrollment not found for roll number " << rollNo << ".\n";
                    } else {
                        for (int i = enrollmentIndex; i < enrollmentCount - 1; i++) {
                            enrollments[i] = enrollments[i + 1];
                        }
                        enrollmentCount--;   cout<<endl<<endl;
                        setColor(4);
                       
                        cout << "Enrollment deleted successfully.\n";
                    }
                    break;
                }
                case 5:
                    break;
                default:  setColor(4);
                    cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 5);
    } else {  setColor(4);
        cout << "Invalid entry! Exiting...\n";
    }
}

// Functions for Enrollment History module
void enrollmentHistory() {
    string role; setColor(9);
    cout << "Are you a user or an admin? ";
    cin >> role;

    if (role == "user" || role == "User") {
        if (enrollmentCount == 0) { setColor(4);
            cout << "No enrollment history to display.\n";
            return;
        }
        setColor(6);
        cout << "Enrollment History:\n";
        cout << "Roll No" << setw(15) << "Course" << setw(15) << "Status\n";
        cout << "-----------------------------------\n";

        for (int i = 0; i < enrollmentCount; i++) {  setColor(8);
            cout << enrollments[i].rollNo
                 << setw(15) << enrollments[i].field
                 << setw(15) << enrollments[i].status << '\n';
        }system("pause");
    } else if (role == "admin" || role == "Admin") {
        int choice;
        do {  setColor(7);
            cout << "\nAdmin Enrollment History Menu\n";
            cout << "1. Add Enrollment History\n";
            cout << "2. View Enrollment History\n";
            cout << "3. Update Enrollment History\n";
            cout << "4. Delete Enrollment History\n";
            cout << "5. Back to Main Menu\n";
            cout<<endl<<endl;
            setColor(4);
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: { // Add
                    if (enrollmentCount >= MAX_ENROLLMENTS) {  setColor(4);
                        cout << "No space available for more enrollment history.\n";
                        break;
                    }
                    setColor(1);
                    Enrollment &e = enrollments[enrollmentCount];
                    cout << "Enter roll number: ";
                    cin >> e.rollNo;
                    cout << "Enter course: ";
                    cin.ignore();
                    getline(cin, e.field);
                    cout << "Enter status (e.g., Enrolled, Completed): ";
                    getline(cin, e.status);

                    enrollmentCount++;
                    cout<<endl<<endl;
                    setColor(4);
                    cout << "Enrollment history added successfully!\n";
                    break;
                }
                case 2: { // View
                    if (enrollmentCount == 0) {  setColor(4);
                        cout << "No enrollment history to display.\n";
                        break;
                    }
                    setColor(6);
                    cout << "Roll No" << setw(15) << "Course" << setw(15) << "Status\n";
                    cout << "-----------------------------------\n";
                    setColor(8);
                    for (int i = 0; i < enrollmentCount; i++) {
                        cout << enrollments[i].rollNo
                             << setw(15) << enrollments[i].field
                             << setw(15) << enrollments[i].status << '\n';
                    }
                    break;
                }
                case 3: { // Update
                    int rollNo; setColor(14);
                    cout << "Enter roll number to update history: ";
                    cin >> rollNo;

                    int historyIndex = -1;
                    for (int i = 0; i < enrollmentCount; i++) {
                        if (enrollments[i].rollNo == rollNo) {
                            historyIndex = i;
                            break;
                        }
                    }

                    if (historyIndex == -1) {  setColor(4);
                        cout << "Enrollment history not found for roll number " << rollNo << ".\n";
                    } else { setColor(7);
                        cout << "Updating Enrollment History for Roll No: " << rollNo << '\n';
                        cout << "Enter new course: ";
                        cin.ignore();
                        getline(cin, enrollments[historyIndex].field);
                        cout << "Enter new status: ";
                        getline(cin, enrollments[historyIndex].status);
                        cout<<endl<<endl;
                        setColor(4);
                        cout << "Enrollment history updated successfully!\n";
                    }
                    break;
                }
                case 4: { // Delete
                    int rollNo;  setColor(14);
                    cout << "Enter roll number to delete history: ";
                    cin >> rollNo;

                    int historyIndex = -1;
                    for (int i = 0; i < enrollmentCount; i++) {
                        if (enrollments[i].rollNo == rollNo) {
                            historyIndex = i;
                            break;
                        }
                    }

                    if (historyIndex == -1) {  setColor(4);
                        cout << "Enrollment history not found for roll number " << rollNo << ".\n";
                    } else {
                        for (int i = historyIndex; i < enrollmentCount - 1; i++) {
                            enrollments[i] = enrollments[i + 1];
                        }
                        enrollmentCount--;
                        cout<<endl<<endl;
                        setColor(4);
                        cout << "Enrollment history deleted successfully.\n";
                    }
                    break;
                }
                case 5:
                    break;
                default:   setColor(4);
                    cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 5);
    } else {   setColor(4);
        cout << "Invalid entry! Exiting...\n";
    }
}

// Main menu
void displayMainMenu() {
    int choice;
    do {
        cout << "\n--- Finance Management Module ---\n";
        cout << "1. Fee Structure Management\n";
        cout << "2. Scholarship Program Management\n";
        cout << "3. Installment Facility Management\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manageFeeStructure();
                break;
            case 2:
                manageScholarshipProgram();
                break;
            case 3:
                manageInstallmentFacility();
                break;
            case 4:
               
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

// Fee Structure Management Functions
void manageFeeStructure() {
    int choice;
    do {
        cout << "\n--- Fee Structure Management ---\n";
        cout << "1. Add Fee Structure\n";
        cout << "2. Display Fee Structures\n";
        cout << "3. Update Fee Structure\n";
        cout << "4. Delete Fee Structure\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFeeStructure();
                break;
            case 2:
                displayFeeStructures();
                break;
            case 3:
                updateFeeStructure();
                break;
            case 4:
                deleteFeeStructure();
                break;
            case 5:
                cout << "Returning to main menu.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
}

void addFeeStructure() {
    if (feeCount >= MAX_FEES) {
        cout << "Cannot add more fee structures. Maximum limit reached.\n";
        return;
    }

    FeeStructure &fee = feeStructures[feeCount];
    cout << "Enter program name: ";
    cin.ignore();
    getline(cin, fee.programName);
    cout << "Enter fee amount: ";
    cin >> fee.feeAmount;

    feeCount++;
    cout << "Fee structure added successfully!\n";
}

void displayFeeStructures() {
    if (feeCount == 0) {
        cout << "No fee structures available.\n";
        return;
    }

    cout << "\n--- Fee Structures ---\n";
    for (int i = 0; i < feeCount; i++) {
        cout << "Program: " << feeStructures[i].programName 
             << ", Fee: " << feeStructures[i].feeAmount << '\n';
    }
}

void updateFeeStructure() {
    string programName;
    cout << "Enter program name to update: ";
    cin.ignore();
    getline(cin, programName);

    for (int i = 0; i < feeCount; i++) {
        if (feeStructures[i].programName == programName) {
            cout << "Enter new fee amount: ";
            cin >> feeStructures[i].feeAmount;
            cout << "Fee structure updated successfully!\n";
            return;
        }
    }
    cout << "Program not found.\n";
}

void deleteFeeStructure() {
    string programName;
    cout << "Enter program name to delete: ";
    cin.ignore();
    getline(cin, programName);

    for (int i = 0; i < feeCount; i++) {
        if (feeStructures[i].programName == programName) {
            for (int j = i; j < feeCount - 1; j++) {
                feeStructures[j] = feeStructures[j + 1];
            }
            feeCount--;
            cout << "Fee structure deleted successfully!\n";
            return;
        }
    }
    cout << "Program not found.\n";
}

// Scholarship Program Management Functions
void manageScholarshipProgram() {
    int choice;
    do {
        cout << "\n--- Scholarship Program Management ---\n";
        cout << "1. Add Scholarship\n";
        cout << "2. Display Scholarships\n";
        cout << "3. Update Scholarship\n";
        cout << "4. Delete Scholarship\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addScholarship();
                break;
            case 2:
                displayScholarships();
                break;
            case 3:
                updateScholarship();
                break;
            case 4:
                deleteScholarship();
                break;
            case 5:
                cout << "Returning to main menu.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
}

void addScholarship() {
    if (scholarshipCount >= MAX_SCHOLARSHIPS) {
        cout << "Cannot add more scholarships. Maximum limit reached.\n";
        return;
    }

    Scholarship &scholarship = scholarships[scholarshipCount];
    cout << "Enter grade: ";
    cin.ignore();
    getline(cin, scholarship.grade);
    cout << "Enter scholarship amount: ";
    cin >> scholarship.scholarshipAmount;

    scholarshipCount++;
    cout << "Scholarship added successfully!\n";
}

void displayScholarships() {
    if (scholarshipCount == 0) {
        cout << "No scholarships available.\n";
        return;
    }

    cout << "\n--- Scholarships ---\n";
    for (int i = 0; i < scholarshipCount; i++) {
        cout << "Grade: " << scholarships[i].grade 
             << ", Scholarship Amount: " << scholarships[i].scholarshipAmount << '\n';
    }
}

void updateScholarship() {
    string grade;
    cout << "Enter grade to update: ";
    cin.ignore();
    getline(cin, grade);

    for (int i = 0; i < scholarshipCount; i++) {
        if (scholarships[i].grade == grade) {
            cout << "Enter new scholarship amount: ";
            cin >> scholarships[i].scholarshipAmount;
            cout << "Scholarship updated successfully!\n";
            return;
        }
    }
    cout << "Grade not found.\n";
}

void deleteScholarship() {
    string grade;
    cout << "Enter grade to delete: ";
    cin.ignore();
    getline(cin, grade);

    for (int i = 0; i < scholarshipCount; i++) {
        if (scholarships[i].grade == grade) {
            for (int j = i; j < scholarshipCount - 1; j++) {
                scholarships[j] = scholarships[j + 1];
            }
            scholarshipCount--;
            cout << "Scholarship deleted successfully!\n";
            return;
        }
    }
    cout << "Grade not found.\n";
}

// Installment Facility Management Functions
void manageInstallmentFacility() {
    int choice;
    do {
        cout << "\n--- Installment Facility Management ---\n";
        cout << "1. Add Installment Plan\n";
        cout << "2. Display Installment Plans\n";
        cout << "3. Update Installment Plan\n";
        cout << "4. Delete Installment Plan\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addInstallmentPlan();
                break;
            case 2:
                displayInstallmentPlans();
                break;
            case 3:
                updateInstallmentPlan();
                break;
            case 4:
                deleteInstallmentPlan();
                break;
            case 5:
                cout << "Returning to main menu.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
}

void addInstallmentPlan() {
    if (installmentCount >= MAX_INSTALLMENTS) {
        cout << "Cannot add more installment plans. Maximum limit reached.\n";
        return;
    }

    InstallmentPlan &plan = installmentPlans[installmentCount];
    cout << "Enter plan name: ";
    cin.ignore();
    getline(cin, plan.planName);
    cout << "Enter total amount: ";
    cin >> plan.totalAmount;
    cout << "Enter number of installments: ";
    cin >> plan.installments;

    installmentCount++;
    cout << "Installment plan added successfully!\n";
}

void displayInstallmentPlans() {
    if (installmentCount == 0) {
        cout << "No installment plans available.\n";
        return;
    }

    cout << "\n--- Installment Plans ---\n";
    for (int i = 0; i < installmentCount; i++) {
        cout << "Plan: " << installmentPlans[i].planName
             << ", Total Amount: " << installmentPlans[i].totalAmount
             << ", Installments: " << installmentPlans[i].installments << '\n';
    }
}

void updateInstallmentPlan() {
    string planName;
    cout << "Enter plan name to update: ";
    cin.ignore();
    getline(cin, planName);

    for (int i = 0; i < installmentCount; i++) {
        if (installmentPlans[i].planName == planName) {
            cout << "Enter new total amount: ";
            cin >> installmentPlans[i].totalAmount;
            cout << "Enter new number of installments: ";
            cin >> installmentPlans[i].installments;
            cout << "Installment plan updated successfully!\n";
            return;
        }
    }
    cout << "Plan not found.\n";
}

void deleteInstallmentPlan() {
    string planName;
    cout << "Enter plan name to delete: ";
    cin.ignore();
    getline(cin, planName);

    for (int i = 0; i < installmentCount; i++) {
        if (installmentPlans[i].planName == planName) {
            for (int j = i; j < installmentCount - 1; j++) {
                installmentPlans[j] = installmentPlans[j + 1];
            }
            installmentCount--;
            cout << "Installment plan deleted successfully!\n";
            return;
        }
    }
    cout << "Plan not found.\n";
}

//main function
int main() {

	setColor(2);
	cout<<endl<<endl<<endl<<endl<<endl;
    cout << setw(75) << " ----------------------------------------------" << endl;
    cout << setw(74) << "  WELCOME TO EDUCATIONAL MANAGEMENT SYSTEM" << endl;
    cout << setw(75) << " ----------------------------------------------" << endl;
    cout<<endl<<endl;
     string Username = "admin"; string username;
    const int Pass = 12345;   int password;
    setColor(4);
    cout<< setw(55) << "Enter the username: ";
    cin >>username;
    cout << setw(55)<< "Enter the password: ";
    cin >> password;

    if (username ==Username && password == Pass) {
    	setColor(3);
    	cout<<endl<<endl;
        cout << setw(63)<< "Successfully logged in!" << endl;
        cout<<endl;
        setColor(14);
        cout << setw(55) << "" << endl;
        cout << setw(54) << "**** WELCOME " << username << "! ****" << endl;
        cout << setw(55) << "" << endl; system("pause");
    } else {
    	setColor(4);
    		cout<<endl<<endl;
        cout << "Incorrect username or password!" << endl;
        return 0; 
    }
     int wish;
      system("cls");
    cout<<endl<<endl;
     setColor(2);
     m:  setColor(2);
	
    cout << setw(75) << " ---------------------------------------" << endl;
    cout << setw(68) << "   EDUCATIONAL MANAGEMENT SYSTEM" << endl;
    cout << setw(75) << " ----------------------------------------" << endl;
     	 cout<<endl<<endl;
        cout << "1.Student management" << endl;
        cout << "2.Student service management" << endl;
        cout << "3.Finance management" << endl;
        cout << "4. Exit" << endl;
         cout<<endl<<endl;
         	setColor(3);
         cout<<"Which module would you like to visit:"<<endl;
         cin>>wish;
        
  switch ( wish){
case 1:
	
   system("cls");
        int choice;

    do {
        setColor(3);
       system("cls");
        cout << setw(55) << "*******************************" << endl;
        cout << setw(54) << "  STUDENT MANAGEMENT DEPARTMENT" << endl;
        cout << setw(55) << "*******************************" << endl;
		 cout<<endl<<endl;
		  setColor(2);
        cout << "1. Student Profiles\n";
        cout << "2. Enrollment\n";
        cout << "3. Enrollment History\n";
        cout << "4. Exit\n";
        cout << endl << endl;
        setColor(4);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system("cls");{
                int subChoice;
                do {
                    setColor(8);
                    cout << "\nStudent Profiles\n";
                    cout << "1. Show Students\n";
                    cout << "2. Add Student\n";
                    cout << "3. Search Student\n";
                    cout << "4. Delete Student\n";
                    cout << "5. Update Students\n";
                    cout << "6. Back to Student management Menu\n";
                    cout << endl << endl;
                    setColor(12);
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1:system("cls");
                            showStudents();
                            break;
                        case 2:
                            addStudent();
                            break;
                        case 3:
                            searchStudent();
                            break;
                        case 4:system("cls");
                            deleteStudent();
                            break;
                        case 5:system("cls");
                            updateStudent();
                            break;
                        case 6:
                            // This will break out of the Student Profiles menu and return to the main menu
                            break;
                        default:
                            cout << "Invalid choice! Try again.\n";
                    }
                } while (subChoice != 6); // Exit when subChoice is 6
                break;
            }
            case 2:system("cls");
                enrollment();
                break;
            case 3:system("cls");
                enrollmentHistory();
                break;
            case 4:system("cls");
                setColor(12); 
               
                goto m;
                break;
            default:
                setColor(12);
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4); // Exit when choice is 4
 break;
case 2: 

system("cls");
	
 cout << endl;
        setColor(1);
        cout << setw(55) << "-------------------------" << endl;
        cout << setw(55) << "STUDENT SERVICE DEPARTMENT" << endl;
        cout << setw(55) << "-------------------------" << endl;
    int choicet;
    do {
        setColor(3);
        cout << "Main Menu:\n";
        cout << "1. ID Card Service\n";
        cout << "2. Co-Curricular Activity\n";
        cout << "3. Student Complaints\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choicet;
     switch (choicet) {
            case 1: {
                int subChoice;
                do { 
                    setColor(6); system("cls");
                    cout << "\nID Card Service:\n";
                    cout << "1. Add Student\n";
                    cout << "2. Show All Students\n";
                    cout << "3. Search Student\n";
                    cout << "4. Update Student\n";
                    cout << "5. Delete Student\n";
                    cout << "6. Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1: Add();system("pause"); break;
                        case 2: Show(); setColor(6);
                                     cout << "\nPress Enter to return to the menu...";
                                     cin.ignore(); 
                                     cin.get();system("pause");  
                                     break;
                        case 3: Search(); system("pause");break;
                        case 4: Update(); system("pause");break;
                        case 5: Delete();system("pause"); break;
                        case 6: system("pause");break;
                        default: setColor(4); cout << "Invalid choice!" << endl;
                    }
                } while (subChoice != 6);
                system("pause");break;
            }
            case 2:
                	system("cls");
            	setColor(2);
                cout << "Co-Curricular Activity:" << endl;
                cout<<"========================="<<endl;
                cout << "1. Games" << endl;
                cout << "2. Stalls" << endl;  cout<<endl<<endl;
                int activity;
                cin >> activity;
                if (activity == 1) {
                	
                	setColor(6);
                    cout << "Choose Game: 1. Football  2. Cricket" << endl;
                    int gameChoice;
                    cin >> gameChoice;
                    if (gameChoice == 1) 
                    {	
                    	setColor(12);
                    	cout << "Football Activity selected" << endl;
					}
                  else {	
                    	setColor(12);
					cout << "Cricket Activity selected" << endl;
					}
                } else {
                	setColor(12);
                    cout << "Stalls selected" << endl;
                }
                break;
        case 3:
               	system("cls");
            setColor(2);
            cout<<"STUDENT COMPLAINTS"<<endl;
            cout<<"===================="<<endl;
			complaint();
			 break;
       
        case 4:
                setColor(2);
                
                goto m;
                break;
        default:
                setColor(4);
                cout << "Invalid choice!" << endl;
        }
    } while (choicet != 4);
 break;
case 3:  
           system("cls");
	displayMainMenu();
	goto m;
 break;

case 4: return 0;	
	
}
   return 0;       
	}
