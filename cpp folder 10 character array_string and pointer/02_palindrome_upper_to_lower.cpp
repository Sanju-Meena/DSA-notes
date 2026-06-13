#include<iostream>
using namespace std;
/* palindrome check karne ki 1st approach hai ki compare kr loo first and last index koo
   and soo on 2nd approach hai ki hum new string banaye 1st ko reverse kr ke or dono ko
   compare kr le but ismai extra space legega.*/
   
// Noon palindrome hai .

int changecase(char asd[] , int s){
   for(int i = 0 ;i<s;i++){
      if(asd[i]  >= 'A' && asd[i]<='Z'){ 
            asd[i] = asd[i] - 'A' + 'a' ; 
        }
    }    
}

int main(){
    char ch[20];
    cin>>ch; 
    int l = 0;
    for(int i = 0;ch[i]!='\0';i++){ l++; }
    cout<<"length is : "<<l<<endl;

// convert into lowercase;
changecase(ch,l);
//ch send kiya mtlb hamne address diya hai, joo bhi change karoge address mai change hoga.
cout<<ch<<endl;

// palindrome check;
bool flag = 1;
    for(int i = 0;i<l/2;i++){
        if(ch[i] != ch[l-i-1]){
            flag = 0 ;
            break;
        }
    }
    if(flag == 1){cout<<"palindrome\n";}
    else{cout<<" not palindrome \n";}
    
    char as = '9' ;
    cout<<as<<endl;
    as = as + 1; //ismai next character aayega.
    cout<<as<<endl;
    int one = as  ; //yaha character ki ascii value aayegi.
    cout<<one<<endl;
    one+= 1;
    cout<<one<<endl;
    char onet = as + 2 ;
    int oet = as + 2 ;
    cout<<onet<<endl;
    cout<<oet<<endl;
}