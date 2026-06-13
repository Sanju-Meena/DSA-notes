#include<iostream>
using namespace std;
// size having datatype  int (4),float (4), char (1), long (12), bool (1);

void file1(){
    int d = 'A', cp = 100;
    cout << d <<", "<< cp << endl;

    char cm = 123;
    cout << cm << endl;

    unsigned int e = 12,f = -12;
    cout << e <<", "<< f << endl;
    cout<<endl;
}
int main(){
    file1();
}