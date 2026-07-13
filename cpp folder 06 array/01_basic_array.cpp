#include<iostream>          
using namespace std;

int main(){
int first[10] = {0}; // all value of array first is zero. 
// it is only valid for 0(zero) no. only.
int dost[10] = {1,2,3,4,5,6,7,88,0,76}; 
// dost hame pahele location ka naam deta hai.
for(int i = 7;i<10;i++){
    cout<<dost[i]<<" ";
}   
cout<<endl;
int second[10]={2,3,4,5,6};
for(int i = 0;i<10;i++){
    cout<<second[i]<<" ";
}   
cout<<endl;
cout<<"value at 15 number is "<<second[15]<<endl;
// char third[5] =  {'k','a','j','a','l'}; --->aise bhi likh sakte hai.
char school_friend[20] = "kajal khandewal";
for(int i = 0;i<15;i++){
    cout<<school_friend[i];
}
cout<<endl;
// char third[3] =  {'k','a','j','a','l'};// --->error batayega.
float fourth[] = {0.0,4.5,5,1,2.987};
for(int i = 0;i<5;i++){
    cout<<fourth[i]<<" ";
}   
cout<<endl;
}
// arr ki index 0 se start hoti hai.
// in array values stores in contiguous location.