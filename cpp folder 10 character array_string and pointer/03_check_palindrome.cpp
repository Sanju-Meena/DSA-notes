#include<iostream>
using namespace std;
// check palindrome or not;
// only consider character and number.
// upper and lower case assume to be same.


int main(){
    char zx[20] = {"F?3A@rra?4f"};
    
    // convert it into lower case.
    for(int i = 0;zx[i] != '\0';i++){
        if( zx[i] >= 'A' && zx[i]<='Z' ){
            zx[i] = zx[i]-'A'+ 'a' ;
        }
    }
    cout<<zx<<endl;

    // faltu character hata doo.
    char arr[20];
    int j = 0;
    for(int i = 0 ;zx[i] != '\0' ;i++){
         if(zx[i]>='0' && zx[i]<='9' || zx[i]>='a' && zx[i]<='z') { 
            arr[j] = zx[i];
            cout<<arr[j]<<" " ;
            j++;
            }
    }
    cout<<endl<<arr<<endl;
    cout<<"length is : "<<j<<endl;

    bool flag = 1;
    for( int s= 0 ,e = j-1; e>=s ;s++,e--){
        if(s<=e){
              if(arr[s] != arr[e]){ 
              flag = 0;
              break;
        }
        }
    }
    if(flag == 1){cout<<"palindrome\n";}
    else{cout<<" not palindrome \n";}   
}