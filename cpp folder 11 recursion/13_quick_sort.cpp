#include<iostream>
using namespace std;
/*quicksort mai hum pahele partition ftnction likhte hai jisme starting index ko right index(pi) pr dalte hai,
  and then swap karte hai jo ki arr[pi] k aage chote element hai and arr[pi] k pahele bade element hai .
  matlab {>=a .... a......<a } and partition function se return karvate hau pi index .fir hum qs function koo
  call karte hai jo ki pi se pahele vale array ko sort karta hai and the hum qs function koo fir call karte hai 
  jisse pi k baad  vala array bhi sort hoo jata hai;*/

int partition(int arr[],int s ,int e){
    int pivot = arr[s];
    int c = 0;
    for(int i = s+1 ;i<=e;i++){
        if(pivot >= arr[i]){c++;}  
    }    

    int pi = c+s; //imp hai s plus karna;
    swap(arr[s],arr[pi]);  

    while(s<pi && e>pi){
        while(arr[s] <= pivot){ s++; }
        while(arr[e] > pivot){ e--;}

        if(s < pi && e > pi){ 
            swap(arr[s++],arr[e--]);
        }   
    }
    return pi;
}

void quicksort(int arr[], int s, int e){
    if(s>=e)return ;
    // partition karte hai;
    int pi = partition(arr,s,e);
    
    // left vala part sort;
    quicksort(arr,s,pi-1);
    
    // right vala part sort;
    quicksort(arr,pi+1,e);
}

int main(){
    // int n;
    // cout<<"Enter size of array\n";
    // cin>>n;
    // int arr[n] ;
    int arr[10] = {4,5,2,9,1,0,8,7,3,4};
    int n = 10;
    // for(int i = 0;i<n;i++){cin>>arr[i];}
    quicksort(arr,0,n-1);
    
    for(int i = 0 ;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;
    return 0;
}

/*Quick sort is prefer over merge sort bcz merge sort require
  more storage than quick sort and both have same time complexicity 
  TC = O(nlogn);
  Quick sort is also called as in place algorithm. */