#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(a!=0 && b!=0){
        if(a>b){a = a-b;}
        else{b = b-a;}
    }

    if(a == 0){return b;}
    else{return a;}
}

void erase(vector<int> &v,int n){
    for(int i = 0;i<v.size();i++){
        if(v[i] == n){v.erase(v.begin()+i); break;}
    }
}

int main(){
    // vector<bool> p(1001,true);
    // p[0] = 0,p[1] = 1,p[2] = true;
    // for(int i = 2;i<=p.size();i++){
    //     if(p[i] == 1){
    //         for(int j = i*2;j<=p.size();j+=i){
    //             p[j] = false;
    //         }
    //     }
    // }
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        vector<int> v;
        for(int i = l;i<=r;i++){
            v.push_back(i);
        }
        int s = 0, ch = 0;
        for(int i = 0;i<v.size();i++){
            for(auto i:v){cout<<i<<" ";}cout<<endl;
            int a = 0,b = 0,c = 0;
            // choose a;
            a = v[i];
            // erase(v,a);
            i++;

            // choose b;
            while(i<v.size()){
                if(gcd(v[i],a == 1)){b = v[i]; break;}
                i++;
            }
            if(b == 0){erase(v,a); i--;}
            else{

                
                // choose c;
                int j = i;
                while(gcd(v[j],a) != 1 || gcd(v[j],b)!= 1){
                    j++;
                }  
                if(j<v.size()){
                    c = v[j];
                    erase(v,c);
                    erase(v,a);
                    erase(v,b);
                    s++;
                }
                else{erase(v,a);}
                
            }
        }
        if(ch == 0){cout<<"ans = "<<s<<endl;}
    }
}





// #include<bits/stdc++.h>
// using namespace std;
// int gcd(int a,int b){
//     while(a!=0 && b!=0){
//         if(a>b){a = a-b;}
//         else{b = b-a;}
//     }

//     if(a == 0){return b;}
//     else{return a;}
// }

// void erase(vector<int> &v,int n){
//     for(int i = 0;i<v.size();i++){
//         if(v[i] == n){v.erase(v.begin()+i); break;}
//     }
// }

// int main(){
//     vector<bool> p(1001,true);
//     p[0] = 0,p[1] = 1,p[2] = true;
//     for(int i = 2;i<=p.size();i++){
//         if(p[i] == 1){
//             for(int j = i*2;j<=p.size();j+=i){
//                 p[j] = false;
//             }
//         }
//     }
//     int t;
//     cin>>t;
//     while(t--){
//         int l,r;
//         cin>>l>>r;
//         vector<int> v;
//         for(int i = l;i<=r;i++){
//             v.push_back(i);
//         }
//         int s = 0,q = l;
//         int ch = 0;
//         for(int i = 0;i<v.size();){
//             for(auto i:v){cout<<i<<" ";}cout<<endl;
//             int a = 0,b = 0,c = 0;
//             // choose a;
//             for(q;q<=r;q++){
//                 if(p[q] == 1){a = q; erase(v,a); break;}
//             }
//             if(a == 0 || v.size() == 0){cout<<s<<endl;ch = 1;break;}
//             for(auto i:v){cout<<i<<" ";}cout<<endl;
            
//             // choose b;
//             while(v[i] == 1 && i<= r || v[i]/a == 0){i++;}
//             if(i<v.size()){b = v[i]; erase(v,b);}
//             else{
//                 int add = 0;
//                 while(q<=r){
//                     if(v[q] == 1){add ++;}
//                 }
//                 if(add >= 2){s++; add = add - 2; s = s + (add/3); cout<<s<<endl;ch = 1;break;}
//                 else{cout<<s<<endl;ch = 1; break;}
//             }
//             for(auto i:v){cout<<i<<" ";}cout<<endl;
            
//             // choose c;
//             for(int j = i;j<v.size();j++){
//                 if(v[j] == 1 || v[j]/a == 0 || v[j]/b==0){j++;}
//                 else if(gcd(b,v[j]) == 1){c = v[j]; erase(v,c); s++; break;}
//             }
//             if(c == 0){
//                 for(q;q<=r;q++){
//                     if(p[q] == 1){c = q; s++; erase(v,c); break;}
//                 }
//             }
//             if(c == 0){cout<<s<<endl;ch = 1;break;}
//             cout<<s<<endl;

//         }
//         if(ch == 0){cout<<"ans = "<<s<<endl;}
//     }
// }