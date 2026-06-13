#include <iostream>
using namespace std;

int main()
{
    int rupee ;
    cout<<"enter the amount"<<endl;
    cin>>rupee;
    int n;
    n = rupee ;
    switch (100){
        case 100:cout<<"no. of hundred notes is "<<(n/100)<<endl ;
                 n = n%100;
        case 50:cout<<"no. of fifty notes is "<<(n/50)<<endl ;
                 n = n % 50;
        case 20:cout<<"no. of twenty notes is "<<(n/20)<<endl ;
                 n = n%20;
        case 1:cout<<"no. of one rupees notes is "<<(n/1)<<endl ;
                 n = n%1;

    }
}
