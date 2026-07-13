#include<iostream>
using namespace std;

int search(int qw[],int size){
int s = 0 , e = size-1;
int m  = s+(e-s)/2 ;
while(s<e){
    if(qw[0] <= qw[m]){ s = m +1; }
     else{ e = m;  }
    m = s + (e-s)/2;
}
cout<<"pivert element is "<<qw[e]<<endl;
return e;
}

int binary(int zx[],int s,int e,int key){
     int m = s+(e-s)/2;
     while(s<=e){
        if(zx[m]==key){return 1;}
        else if (zx[m] < key){s = m+1;}
        else{e = m-1;}
        m = s+(e-s)/2;
     }
     return -1;
}

int main(){
int arr[6]={7,8,9,2,3,4};
int p = search(arr,6);
int k,l = 5;
cout<<"enter the key and check present or not.\n";
cin>>k;
if(arr[0]<= k && arr[p-1]>=k ){
   int x = binary(arr,0,p,k);
   cout<<x;
}else{
   int x = binary(arr,p,l,k);
   cout<<x;
}
}