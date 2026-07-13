#include<iostream>
using namespace std;
// pivert element meaning ex.{1,2,4,6,7}
// hamne rotate kiya ex..{6,7,1,2,4}
// now pivert element is 1.
// find pivert element using binary search.
int pivert_element(int arr[],int size){
int s= 0 ,e=size-1;
int m = s+(e-s)/2;

while(s<e){
   if(arr[0] <= arr[m]){s = m +1;
   }
   else{
    e = m;
   }
   m = s+(e-s)/2;
}
return e;
}

int main(){
int arr[5]= {7,8,9,10,1};
int x = pivert_element(arr,5);
cout<<"The index "<<x<<" has pivert element is "<<arr[x];

}