#include<iostream>
using namespace std;
// find 1 st and last occurrance and also no. of occurance.

int firstoccurance(int arr[],int n,int key){
    int s = 0,e = n-1;
    int m = s+(e-s)/2;
    int ans = -1;
        while(s<=e){
           if(arr[m] == key){
              ans = m;
              e = m-1;    }

           if(arr[m]<key){
             s=m+1;  }

           if(arr[m]>key){  e = m-1;   }

           m = s+(e-s)/2; 
        }
        return ans;
}
int lastoccurance(int arr[],int n,int key){
    int s = 0,e = n-1;
    int m = s+(e-s)/2;
    int ans = -1;
        while(s<=e){
           if(arr[m] == key){
              ans = m;
              s = m+1;    }

           if(arr[m]<key){
             s=m+1;  }

           if(arr[m]>key){  e = m-1;   }

           m = s+(e-s)/2; 
        }
        return ans;
}

int main(){
    int arr[7]= {2,2,4,4,5,6,6};
    //array must  be sorted .
   int x= firstoccurance(arr,7,6);    
   cout<<x<<endl; 
  int y= lastoccurance(arr,7,6);    
   cout<<y<<endl;  
   cout<<"No. of occurance is "<<y-x+1;                  
}