#include<iostream>
using namespace std;
int main()
{
   int rows , columns;
  int avg=0.0;
 
   int sum=0;
   
   //define the size of array
   cout<<"Enter the number of rows :";
   cin>>rows;
   cout<<"Enter the number of columns: ";
   cin>>columns;
   
   //declare a 2D array
   int array[rows][columns];
    
  //Input elements in 2D array
  //cout<<"Enter elements of the array:\n";
  
  for(int i=0; i<rows; i++){
  	for(int j=0; j<columns; j++){
  		cout<<"Elements ["<<i<<"]["<<j<<"]:";
  		cin>>array[i][j];
  			sum+=array[i][j];
  			
  		avg=sum/array[i][j];
	  }
  }	
 //Display the 2D array;

  cout<<"\n The 2D array is:\n";
   for(int i=0; i<rows; i++){
   	for(int j=0; j<columns; j++ ){
   		cout<<array[i][j]<<" ";
   		
  	
	   }
	   cout<<endl;
	   
   }
   
  cout<<"sum is: "<<sum<<endl;
  cout<<"Average is: "<<avg;
	return 0;
}