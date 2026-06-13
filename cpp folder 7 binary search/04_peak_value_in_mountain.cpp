#include<iostream>
using namespace std;

int peak_value(int arr[],int size){
int s= 0 ,e=size-1;
int m = s+(e-s)/2;

while(s<e){
    
    if(arr[m] < arr[m+1] ){
        s= m+1;
    }
    else{e = m;}
    m = s+(e-s)/2;
}
return e;
//  if(arr[m] > arr[m+1] ){
//         e= m;
//     }
//     else{s = m+1;}
//     m = s+(e-s)/2;
// }
// return e;
}

int main(){
   int arr[4] = {100,12,11,10};
 int max = peak_value(arr,4);
cout<<"The max value is "<<arr[max];

}