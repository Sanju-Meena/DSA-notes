#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int d = 0;
        int num1,num2 ;
        long long ans = 0;

        for(int i = 0;i<n;i++){
            cin>>arr[i];
            if(i >= 1){
                int diff = arr[i-1] - arr[i];
                if(diff < 0){diff = diff*-1;}
                if(d < diff){d = diff; num1 = i-1; num2 = i;}
                ans +=diff;
            }
        }
    
        int dfnum1 = 0;
        if(num1 == 0){
            dfnum1 = arr[0] - arr[1]; 
            if(dfnum1 < 0){dfnum1 = dfnum1*-1;}
        }
        else{
            int v1 = arr[num1] - arr[num1-1] ;
            int v2 = arr[num1] - arr[num1+1] ;
            int v3 = arr[num1-1] - arr[num1+1] ;
            if(v1 < 0){v1 = v1*-1;}
            if(v2 < 0){v2 = v2*-1;}
            if(v3 < 0){v3 = v3*-1;}
            dfnum1 = v1 + v2 - v3;
        }
        

        int dfnum2 = 0;
        if(num2 == n-1){
            dfnum2 = arr[n-2] - arr[n-1]; 
            if(dfnum2 < 0){dfnum2 = dfnum2*-1;}
        }
        else{
            int v1 = (arr[num2] - arr[num2-1]) ;
            int v2 = (arr[num2] - arr[num2+1]) ;
            int v3 = arr[num2-1] - arr[num2+1] ;
            if(v1 < 0){v1 = v1*-1;}
            if(v2 < 0){v2 = v2*-1;}
            if(v3 < 0){v3 = v3*-1;}
            dfnum2 = v1 + v2 - v3;
        }
        
        long long maxi = max(dfnum1,dfnum2);
        ans = ans - maxi;
        cout<<ans<<endl;


    }
}

// 10 30 10 100 500 600 failed for this case