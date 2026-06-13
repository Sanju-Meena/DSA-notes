#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter the value of num\n ";
    cin >> num;
    if (num > 0)
    { cout << num << " is positive" << endl; }
    else if(num < 0)
    { cout << num << " is negative" << endl; }
    else{
        cout<<"number is 0"<<endl;
    }
    
}