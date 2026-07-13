
    // time complexity means---->
    // it is the amount of time taken by an algorithm to run.
    // represent by BIG(O)--->it describe maximum time taken by a program.
    // time complexcity as ascending order like
    // O(1) < O(n) < O(log n) < O(n^2).........
    // time taken more aage jayega jb.
    
    // SPACE COMPLEXICITY--->
    // kitni memory aapki algorithm lene vali hai as a function of an input.
    // int a,b,c,d,arr[1000]... -->constant input then space complexcity is O(1).
    // O(n) --->  int n;  cin>> n;  int arr[n];
    #include <bits/stdc++.h>
using namespace std;

int sum(int arr[] , int n){
    int sum = 0 ;
    for(int i = 0;i<n;i++){
        sum = sum + arr[i] ;
    }
    return sum ;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;   cin>>n;   int arr[n] ;
	    for(int i = 0;i<n;i++){   cin>>arr[i] ; }
	    
	    int c = 0;
	    for(int i = 0;i<n;i++){
	        if(arr[i] < 0){ c++ ;}
	    }
	    
	    if(c == 0){int ans =  sum(arr,n); cout<<ans<<endl;}
	    
	   else if( c % 2 == 0 ){
	    for(int i = 0;i<n;i++){
	        if(arr[i] < 0){ arr[i] = -arr[i] ;}
	    }
	    int ans = sum(arr,n) ;
        cout<<ans<<endl;
	    }
	    
	    else if(c %2 == 1 ){
	       for(int i = 0;i<n;i++){
	        if(arr[i] < 0){ arr[i] = -arr[i] ;}
	        }

	        int min = 0 ;
	        for(int i = 0;i<n;i++){
	        if(arr[min] > arr[i]){ min = i;}
	    }

	    arr[min] = - arr[min] ;
	    int ans =   sum(arr,n) ;
          cout<<ans<<endl;
	    }
	   
}
}
