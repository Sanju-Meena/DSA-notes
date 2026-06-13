#include<iostream>
using namespace std;

int main(){
    // Question 1.
    // int *q = 0;
    // int f = 110;
    // *q = f;
    // cout<<*q<<endl;

    // Question 2.
    cout<<"Ans of question no. 2 : \n";
    int arr[] = {1,2,3,4};
    cout<<arr<<" "<<&arr<<endl; 
    int *p = arr;
    cout<<p[2]<<endl;

    // Question 3.
    // int arr[] = {1,2,3,4};
    // int *p = arr++;
    // cout<<*p<<endl;

    // Question 4.
    cout<<"Ans of question no. 4 : \n";

    char ar[] = {"sanjay"};
    char *s = ar;
    cout<<ar[0]<<" "<<ar<<" "<<s[0]<<" "<<s<<endl;
    s++;
    cout<<*s<<" "<<s<<endl;

    // Question 5.
    cout<<"Ans = 5 :  ";
    int firs = 110;
    int *poi = &firs;
    int **qi = &poi;
    int secon = (**qi)++ + 9;
    cout<<firs<<" "<<secon<<endl;




    /*
    1. segmentation fault;
    2. solution : p[2] = *(arr+2) or p[2] = arr[2];
    3. solution : symbol table update nahi hoti hai, so error in line no. 19.
    */
}