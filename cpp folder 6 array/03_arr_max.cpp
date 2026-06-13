#include<iostream> 
using namespace std ;

int getmax(int arr[] , int n){
int max = arr[0];
int count = 0 ;
for(int i = 1;i<n;i++){
   if(max < arr[i]){
    max = arr[i] ;
    count = i ;
   }
}
cout<< "max value is "<<max <<endl;
cout<<"position of max is "<<(count + 1)<<endl;
return max ;
}

int min(int arr[] , int n){
int min = arr[0];
int count = 0 ;
for(int i = 1;i<n;i++){
   if(min > arr[i]){
    min = arr[i] ;
    count = i ;
   }
}
cout<< "min value is "<<min <<"."<<endl;
cout<<"position of min is "<<(count + 1)<<endl;
return min ;
}

int main(){
int arr[5]={2,5,4,3,1} ;
getmax(arr , 5) ;
min(arr , 5) ;
}
// hame variable size ka array nahi banana hota hai. 
// int arr[n] where n is  a variable ; --- > bad practise.