// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<int> v;
//         for(int i = 0;i<n;i++){
//             int a;
//             cin>>a;
//             v.push_back(a);
//         }
//         sort(v.begin(),v.end());
//         int min = v[0],max = v[n-1];
//         cout<<min<<" "<<max<<endl;
//         int c1 = 0,c2 = 0;
//         int ch =0;

//         if((min + max)% 2 == 0){cout<<0<<endl;}
//         else if(min % 2 == 0){
//             for(int i = 0,j = n-1;i<n ;i++,j--){
//                 if(v[j]%2 == 1){c1++;}
//                 else{cout<<c1<<endl;ch = 1; break;}
       
//                 if(v[i]%2 == 0){c2++;}
//                 else{cout<<c2<<endl;ch = 1; break;}

//             }
//         }
//         else if(min % 2 == 1){
//             for(int i = 0,j = n-1;i<n ;i++,j--){
//                 if(v[j]%2 == 0){c1++;}
//                 else{cout<<c1<<endl;ch = 1; break;}
//                 if(v[i]%2 == 1){c2++;}
//                 else{cout<<c2<<endl;ch = 1; break;}

//             }
//         }
//         cout<<endl;
//     }
// }


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        if(n == 1){cout<<0<<endl;}
        else if(n<=k){cout<<1<<endl;}
        else{
            int c = 0;
            while(n > k*k){
                n = n - (k*(k-1));
                c+=k;
            }

            if(n>1){
                if(n <= k){c = c + 1;}
                else if(n == k*k){ c = c + k + 1 ;}
                else if(n%k == 0){ c = c + n/k + 1 ;}
                else if(n%k != 0){
                    int ans = n/k; 
                    int rem = n % k;
                    int uo = k - ans;
                    if(uo>= rem){c = c + n/k +1;}
                   else{c= c + n/k + 2; } 
                } 
            }
            cout<<c<<endl;
        }
    }
}