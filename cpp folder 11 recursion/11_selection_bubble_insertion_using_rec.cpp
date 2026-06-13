#include<iostream>
using namespace std;

void selectionsort(int arr[], int n){
    if(n == 1){return ;}
    int min = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]<arr[min]){min = i;}
    }
    swap(arr[0] , arr[min]);
    selectionsort(arr+1,n-1);
    
}

void bubblesort(int arr[], int n){
    if(n <= 1){return ;}
    else{
        for(int i = 0 ;i<n-1;i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i],arr[i+1]); }
                // for(int i = 0 ; i < n ; i++){cout<<arr[i]<<" ";}cout<<endl;
        }
        bubblesort(arr,n-1);
        return ;
    }
}

// void insertionsort(int arr[], int n,int i){
//     if(i > n ){return ;}
//     int j = i-1;;
//     for(int k = i ; j > -1;j--){
//         if(arr[j] > arr[k]){
//             swap(arr[j] ,arr[k]);
//             k--;
//             // for(int i = 0 ; i < n ; i++){cout<<arr[i]<<" ";}cout<<endl;
//         }else{break;}
//     }
//     i++;
//     insertionsort(arr,n,i);
//     return ;
// }

void insort(int arr[],int n,int in){
    if(in >= n){return ;}

    for(int j = in;j>0;j--){
        if(arr[j] < arr[j-1]){swap(arr[j],arr[j-1]);}
        else{break;}
    }
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;
    insort(arr,n,in+1);

}


int main(){
    int n = 5;
    int arr[5] = {9,4,7,5,8};
    // selectionsort(arr,n); //find minimum no. and place it into first index;
    // bubblesort(arr,n);       //find max no. and put it into right place by swaping;
    insort(arr,n,1);/* compare each element(start with index 1) by previous one
                              put on write palace and then again compare index 2; */

    for(auto i : arr){cout<<i<<" ";}
}