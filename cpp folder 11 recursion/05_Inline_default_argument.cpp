#include<iostream> 
using namespace std;
// Inline function : it is used to reduce the function calls time.
// it work like macro means before compile it puts the body of function where it is call.
// it work when it's body is 1 line, 2 se 3 line ki body ho to pata nahi manega ya nahi or 3 se jayada pr nahi work karega. 
/*  fayada kya hai?
    1. redeability increase and function call nahi karni padh rahi hai baar baar jisse time complexiblity reduce hogi.
*/
inline int getmax(int &a,int &b){
    return a>b ? a:b ;
}

// start is a default argument when user give it's value then take otherwise default too hai he;
// default argument is always written in right corner and it may be more than one or all also ; 
void print(int arr[],int si = 5,int st = 0){
    for(int i = st;i<si;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    int a = 10,b = 11; 
    if(a>b){cout<<a<<endl;}
    else{cout<<b<<endl;}
    int ans ;
    ans = a>b ? a:b ;
    cout <<"value that is greater than "<<a<<" and "<<b<<" is "<<ans<<endl;
    a+=5;
    b+=3;
    ans = a>b ? a:b ;
    cout <<"value that is greater than "<<a<<" and "<<b<<" is "<<ans<<endl;
    a+=3;
    b+=4;
    cout <<"value that is greater than "<<a<<" and "<<b<<" is "<<getmax(a,b)<<endl;        
    cout<<endl;

    // Default arguments
    int arr[5] = {1,2,3,4,5};
    print(arr,5,2);
    print(arr);
    print(arr,3);

    // const keywords
    const int no = 3;
    cout<<"no is "<<no<<endl;
    // no+=1; not valid error aayega .
}