#include <iostream>
using namespace std;
// how to check character is uppercase or lowercase??
int main()
{
    char ch;
    cout<<"Enter the character"<<endl;
    cin>>ch;
    if(ch>96 && ch<123){
        cout<<"character is lowercase\n";
    }
    else if(ch>64 && ch<91){
        cout<<"character is uppercase\n";
    }
    else if(ch>47 && ch<58){
        cout<<"character is number\n";
    }
    else{
    cout<<"character is not number and alphabet";
}
}