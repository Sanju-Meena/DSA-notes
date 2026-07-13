#include <iostream>
using namespace std;

void operators(){
    int a = 3/7;
    float b = 3.0/7;
    cout <<a<<", "<<b <<endl;
    int c = 8 , d = 9 ;
    bool first = (c == d) ;
    bool second = c>d ;
    bool third = c<d ;
    bool fourth = c!=d ;
    cout << first<<", "<< second<<", "<< third<<", "<< fourth<<", "<<endl;
    cout<<"if c = "<<c<<" then !c is = "<< !c << endl;
    int e = 0 ;
    cout<< !e << endl ;
}

int main()
{
     // 1 byte = 8 bit.
     int a = 5;        
     char ch = 'v';    
     float b = 7.5;    
     double c = 8.987; 
     cout<<sizeof(a)<<", "<<sizeof(ch)<<", "<<sizeof(b)<<", "<<sizeof(c)<<", "<<endl; //4,1,4,8 is ans;
     // bool is also a datatype having size 1 by", "
     bool bl = true, cl = false,cd = 34,dd= 0, od = " maya";
     cout<<bl<<", "<<cl<<", "<<cd<<", "<<od<<", "<<dd<<endl;
     cout<<sizeof(bl)<<", "<<sizeof(c)<<endl;
     cout<<"\n";


     // **** type casting****
     int d = 'A', cp = 100;
     cout << d <<", "<< cp << endl;

     char cm = 123;
     cout << cm << endl;

     unsigned int e = 12,f = -12;
     cout << e <<", "<< f << endl;
     cout<<endl;
     operators() ;
}