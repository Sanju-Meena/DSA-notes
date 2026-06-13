#include<iostream>
using namespace std;

int main(){
int x ;
cout<<"Enter he value of x : ";
cin>>x;
int st = 0,en = x,ans;
int m = st+(en-st)/2;
while(st<en){
    if(m*m<=x){
        ans = m;
        st = m+1;
    }
    else{en= m;}
    m =  st+(en-st)/2;
}

double s = ans; 
double e = s+1;
double mid = s +(e-s)/2 ;
double  sol;
while(e>s){
    if(mid*mid <= x){
       sol = mid;
       s = mid + 0.000001 ;
    }
    else{
        e = mid - 0.000001;
    }
    mid = s+(e-s)/2;
}
cout<<sol;
}