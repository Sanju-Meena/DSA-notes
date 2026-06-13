#include <bits/stdc++.h>
using namespace std;

int primef(int sum){
        int prime = 1;
       for(int k = 2;k<=sum/2;k++){
	                if(sum%k==0){
	                    prime = 0;
	                    break; }
                }
        return prime;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n; 
	    cin>>n;
	    int arr[n] ;
	    for(int i = 0; i<n;i++){
	        cin>>arr[i] ;
		}
		int prime = 1 ;                
			
		for(int i = 0,j = i + 1;j<n && i<n;j++){
			int sum = arr[i] + arr[j];
			prime = primef(sum);
			if(prime == 0){
				cout<<i+1<<" "<<j+1<<endl;
				break;} 
                if(j == n - 1){i++ ;
					j = i;
                }
	        }
	        
			if(prime == 1){cout<<-1<<endl;}
		}
}