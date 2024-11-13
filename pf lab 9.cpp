#include<iostream>
using namespace std;
int main()
{
  int sum=0;
  int var[5]={2,3,4,5,6};
   
   // cout<<"Elements of array are:";
   for(int i=0; i<5; i++)//i used for iteration
   {
   	cout<<var[i]<<" ";
   	sum+=var[i];
   	
   }
   cout<<endl;	
	cout<<"Sum of above values is : "<<sum;

	return 0;
}
