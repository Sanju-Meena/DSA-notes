#include<iostream>
using namespace std;
// 1D char array is known as string;
// char array always add null character in last;
// char array terminate with null character '\0' having ASCII value 0;
void reverse(char cp[],int l){
for(int i = 0;i<l/2;i++){
    swap(cp[i],cp[l-1-i]);
}
}

int length_of_string(char bz[]){
    int count = 0;
    for(int i = 0;bz[i] != '\0';i++){
         count++ ;
    }
    return count ;
}
int main(){
    int atr[5] = {1,2,3,4,5};
    cout<<atr<<endl; //ye hame address print karega;

    char ar[20];
    cout<<"enter char array : ";
    cin>>ar; 
    cout<<ar[1]<<endl;
    ar[5] = '\0';
    cout<<ar<<endl; 

    char arrr[20] = {"mahi maar raha hai "} ;
    cout<<arrr<<"\n";
    char brr[21] = {'k','a','j','a','l','\0','g','f'} ;
    cout<<brr<<endl;
    char arr[22] ;
    cin>>arr ;
    // cin stop kr deta hai yadi hum usse tab,enter,space de too.
    // arr[2] = '\0' ; ----> Null character aise dalte hai.
    cout<<"Name is : ";
    cout<<arr<<endl; 

    int l = length_of_string(arr);
    cout<<"Length of arr is : "<<l<<endl;

    reverse(arr,l);
    cout<<arr<<endl;

    char as = 'A' + 1;
    cout<<as<<endl;

    int one = as  ;
    cout<<one<<endl;

    char onet = as + 2 ;
    cout<<onet<<endl;
    int oet = as + 2 ;
    cout<<oet<<endl;
}