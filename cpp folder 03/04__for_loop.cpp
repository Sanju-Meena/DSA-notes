#include<iostream>
using namespace std;

int main(){
    int a ;
    cout<<"enter the value of a\n";
    cin>>a ;
    int i = 1;
    for(;;){
        if(i<=a){
                    cout<<i<<endl;
        } else{
            break;//used to break the loop.
        }
            i++ ;
    }
}