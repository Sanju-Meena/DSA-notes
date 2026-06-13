#include<bits/stdc++.h>
using namespace std;

int main(){
    int *p;
    cout<<"garbage value is "<<*p<<endl;
    // int *d = 0;
    // cout<<"*d is = "<< *d <<endl; 
    //Ye kuch bhi print nahi krega or memory ko kahi or le jayega jisse bache hue bhi instruction follow nahi honge.

    cout<<"Start Program\n";
    int i = 5;
    int *ptr = 0;
    cout<<"Address of i is = "<<ptr<<endl;
    ptr = &i;
    cout<<"Address of i is = "<<ptr<<endl<<endl;
    // *ptr = &i; ye nahi likh sakte error dikhayega;

    int num = 99;
    int *asd = &num;
    cout<<"Address of num is "<<asd<<endl;
    cout<<"Value of num is "<<*asd<<endl;
    (*asd)++;
    cout<<"Value of num is "<<num<<endl<<endl;
     
    //Copy a pointer.
    int *np = asd;  //Yaha pr np = asd hoo gaya hai mtlb yaha pr doo naam de diye ek he location k.
    cout<<np<<" "<<asd<<endl;
    cout<<*np<<" "<<*asd<<endl<<endl;

    int a = 5;
    int *t = &a;
    cout<<t<<endl;
    cout<<++(*t)<<endl;
    cout<<(*t)++<<endl;
    cout<<(*t)++<<endl;
    t+=1;
    cout<<" t is "<<t<<endl;
    t+=1;
    cout<<" t is "<<t<<endl;
    t+=1;
    cout<<" t is "<<t<<endl;
  
}