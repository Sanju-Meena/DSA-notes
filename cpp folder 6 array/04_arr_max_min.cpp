#include<iostream> 
#include<climits>
using namespace std ;

int getmax(int arr[] , int n){
int max = INT_MIN;
// yaha int_min minimum value hai integer ki. 

for(int i = 1;i<n;i++){
   if(max<arr[i]){
    max = arr[i] ;
   }
}
cout<< "max value is "<<max <<endl;
}

int min(int arr[] , int n){
int min = INT_MAX;
for(int i = 1;i<n;i++){
   if(min>arr[i]){
    min = arr[i] ;
   }
}
cout<< "min value is "<<min <<"."<<endl; 
}

int main(){
int arr[5]={2,5,4,3,1} ;
 getmax(arr , 5) ;
min(arr , 5) ;
}
