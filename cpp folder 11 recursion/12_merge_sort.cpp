#include<iostream>
#include <vector>
using namespace std;
// find weather the order of number is sorted or not using recursion;

bool issorted(int arr[],int n){
    int ans;
    if(n<2){return true;}
    else if(arr[0] > arr[1] ){
       return false;
    }
    else{
        ans = issorted(arr+1,n-1);
        //  return ans;
    }
    return ans;

}

int main(){
    int n = 5 ;
    // cin>>n;
    int arr[5];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    cout<< issorted(arr,n);
}

using namespace std;
// TC = n*log(n);
// sc = O(n);
/* mergesort mai base case likhte hai fir arrary ko do part mai divide kiya jata hai right part
   array and left part array,fir left part array ko sort karne k liye mergesort array mai send karte
   hai and then fir again mergesort call karte right part array ko mergesort function mai send karte
   hai and atlast dono sorted hue array ko part ko merge kr dete mai merge function ki help se. */

void merge(int arr[],int s,int e){    
    int mid = s+(e-s)/2;
    int s1 = mid - s + 1;
    int s2 = e - mid ;
    vector<int> v1(s1,0);
    vector<int> v2(s2,0);

    //copy both array in vector v1 and v2;
    int mai = s;  //imp step.
    for(int i = 0;i<s1;i++){
        v1[i] = arr[mai++];
    }
    for(int i = 0;i<s2;i++){
        v2[i] = arr[mai++];
    }

    // now merge both sorted array;
    int id1 = 0,id2 = 0;
    mai = s; //imp step
    while(id1<s1 && id2<s2 ){
        if(v1[id1] < v2[id2]){arr[mai++] = v1[id1++];}
        else{arr[mai++] = v2[id2++];}
    }
    while(id1<s1){arr[mai++] = v1[id1++];}
    while(id2<s2){arr[mai++] = v2[id2++];}
}

void mergesort(int arr[], int s,int e){
    if(s>=e){return ;}
    cout<<"Hello\n";
    int mid = s + (e-s)/2;
        
    // Left vala part sort;
    mergesort(arr,s,mid);

    // Right vala part sort;
    mergesort(arr,mid+1,e);
    // for(int i = 0;i<=e;i++){cout<<arr[i]<<" ";}cout<<endl; 

    // merge both sorted array;
    merge(arr,s,e);
}

int main(){
    // int arr[5] = {2,5,1,6,8,};
    // int n = 5;
    
    // mergesort(arr,0,n-1) ;
    // for(int i = 0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;
    // cout<<endl<<endl;
    
    int arr1[6] = {9,0,7,3,1,6} ;
    int n = 6;
    mergesort(arr1,0,n-1) ;
    for(int i = 0;i<n;i++){cout<<arr1[i]<<" ";}cout<<endl;
}