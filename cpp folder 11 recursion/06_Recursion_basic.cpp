#include<bits/stdc++.h>
using namespace std;
// When a function calling itself is called recursion.
// Q. How to write recursion function?
// ans : step 1- Write base condition with something return value.
// ans : step 2- write choti problem like factorial(n-1), function(2^n-1);
// ans : step 3- write badi problem;
// ans : step 4- write return answer;

int factorial(int n){
    if(n == 1){return 1;}
    // n! = n * n-1!  ;
    else{
        int chotiproblem = factorial(n-1);
        int badiproblem = n * chotiproblem;
        return badiproblem;
    }
} 

/* Start explanation:-
   1. In recursion base case se pata chalta hai ki rukna kb hai agar nhi likhoge too segmentation fault aayega.                      
   2. In base case return likhna mandatory hai.
   3. We required recursive relation.
   4. function call, stack memory mai jati hai.
  //  Recursion are of 2 type:-
  1 Initial base case then processing and then recursive relation.
  1.1 This type is called tail recursion bcz RR is appear in end . 

  2 Initial base case then recursive relation and then processing.   
  2.1  This type is called head recursion bcz recursive relation is before processing. 
   ****matlab RR last too tail recursion nahi too head recursion;****
*/

int power(int n){
    if(n == 1){return 2;}
    else{
        int choti = power(n-1);
        int badi = 2 * choti;
        return badi;
    }
}

void counting(int n){
    if(n == 0){
        cout<<endl;
        return ;
    }
    cout<<n<<" ";
    counting(n-1);  // Tail recursion ;

}

void printno(int n){
    if(n == 0){
        return ;
    }
    printno(n-1);
    cout<<n<<" "; // Head recursion;
}

 int fibonacchi(int n){
    if(n == 1){return 0;}
    if(n == 2){return 1;}
    return fibonacchi(n-1) + fibonacchi(n-2);
}

// if i/p is 412 then o/p is "four one two" by recursion;
void say_digit(int n, string arr[]){
    if(n == 0){return ;}
    else{int a = n %10;
    n = n/10;
    say_digit(n , arr);
    cout<<arr[a]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int ans = factorial(n);
    cout<<"ans = "<<ans<<endl;

    int m;
    cin>>m;
    int answer = power(m);
    cout<<"2 ki power m : "<<answer<<endl;
    
    // Print counting ex: n = 5 then  ans: 5 4 3 2 1;
    int l;
    cin>>l;
    counting(l); //tail recursion;

    // Print counting ex: n = 5 then  ans: 1 2 3 4 5;
    printno(l); //head recursion.

    int o;
    cin>>o;
    int answer = fibonacchi(o);
    cout<<"answer : "<<answer<<endl;   

    int p;
    cin>>p;
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    say_digit(p,arr);
    
}