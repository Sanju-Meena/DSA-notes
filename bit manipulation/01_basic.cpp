#include<bits/stdc++.h>
using namespace std;

// find xor of 1 to r;
int findxor(int r){
    int ans = 0;
    if(r % 4 == 0)ans = r;
    else if(r % 4 == 1)ans = 1;
    else if(r % 4 == 2)ans = r+1;
    else ans = 0;
    
    return ans;
}

// print vector;
void printvec(vector<int> &ans,int size, int i){
    cout<<"[";
    for(auto i = 0;i<ans.size();i++){cout<<ans[i]; if(i!= ans.size()-1)cout<<",";}
    cout<<"]"; 
    if(i != size - 1) cout<<","; 
}

int main(){
    // convert a number into binary;
    int n = 13;
    string st;
    while(n > 0){
        if(n%2 == 1)st.push_back('1');
        else st.push_back('0');
        n = n/2;
        cout<<st<<endl;
    }
    reverse(st.begin(),st.end());
    cout<<st<<endl;

    // now binary to number conversion;
    n = 0;
    int j = 1;
    for(int i = st.length()-1;i>=0;i--){
        int a = st[i] - '0';
        if(a == 1)n = n + j ;
        j = j*2;
    }
    cout<<n<<endl<<endl;

    // logical operation;
    int a = 13 , b = 7;
    cout<< (a & b) <<endl;
    cout<< (a | b) <<endl;
    cout<< (a ^ b) <<endl<<endl; // if same than 0;
     
    // shift operator;
    // 1. right shift -> '>>' means adding 0 at starting place;
    a = a >> 1;  cout<<a<<endl;
    a = a >> 2;  cout<<a<<endl;
    // 2. leftt shift -> '<<' means adding 0 at last palce and remove first place;
    a = a << 1; cout<<a<<endl;
    a = a << 2; cout<<a<<endl;
    a = a << 2; cout<<a<<endl;  //if we do left shift of INT_MAX than it can be overflow;
    a = INT_MAX;
    cout<<(a<<1)<<endl<<endl;
    // 3. not operator;
    n = -5;
    cout<<~(n)<<endl; // first it flip the bit , than if it is -ve than it take 2's complement otherwise it is stop;
    n = 13;
    cout<<~(n)<<endl<<endl;

    // Q1; swap two no.
    a = 4 , b = 5;
    a = a^b;
    b = a^b;
    a = a^b;
    cout<<a<<" "<<b<<endl;
    
    // ith bit is set or not;
    int i = 4;
    n = 13;
    if((n>>(i-1))&1 == 0)cout<<"ith bit is not set;"<<endl;
    else cout<<"ith bit is set;\n";

    //   set the ith bit;
    n = 4, i = 4;
    n = n | (1<<(i-1));
    cout<<"set the ith bit of 4 that is "<<n<<endl;

    // clear the ith bit; means put value 0 on ith place;
    i = 3;
    n = 13;
    n = (~( 1<<(i-1) )) & n ;
    cout<<"clear the 3rd bit of 3 is" <<n<<endl;

    // Toggle the ith bit;
    n = 6;
    i = 4;
    n = n^(1<<(i-1));
    cout<<"Toggle the 4 bit of 6 is "<<n<<endl;

    // remove the rightmost set bit;
    n = 12;
    n = (n-1) & n;
    cout<<n<<endl;

    // check if a no. is power of 2 or not;
    n = 62;
    if((n & (n-1)) == 0)cout<<"yes\n";
    else cout<<"no\n";

    // count the no. of set bit;
    int c = 0;
    n = 13;
    while(n!=0){
        n = n & (n-1);
        c++; 
    }
    cout<<c<<endl;
    
    // Minimum Bit Flips to Convert Number; method 2 is more optimal;
    int s = 10, e = 7;
    c = 0;
    // method 1; 
    // while(s != 0 || e != 0){
    //     if((1 & s) != (1 & e))c++;
    //     s = s>>1;
    //     e = e>>1;
    // }
    
    //  method 2;
    s = s^e;
    while(s != 0){
        s = s & (s-1);
        c++;
    }
    cout<<c<<endl<<endl;


    // print power set of the following array;
    vector<int> nums = {1,2,3}; 
    n = nums.size();
    int size = 1<<n;
    vector<int> an;
    for(int i = 0;i<size;i++){
        // int a = i;
        for(int j = 0;j<n;j++){
            if(i & (1<<j) ) an.push_back(nums[j]);
            // if(1 & (a>>j) ){an.push_back(nums[j]);}
            // if(a>>j == 0)break;
        }
        printvec(an,size,i);
        an.clear();
    }
    cout<<endl;

    // find the number which occour only once;
    nums = {1,2,4,1,2};
    a = 0;
    for(int i = 0;i<nums.size();i++) a = a^nums[i];
    cout<<endl<<a<<endl;
    
    // find the number which occour only once;
    // nums = {1,2,3,1,2,1,2};
    // method 1;
    // a = 0;
    // for(int i = 0;i<32;i++){
        //     int c = 0;
        //     for(int j = 0;j<nums.size();j++){
            //         if(nums[j] & (1<<i))c++;
            //     }
            //     if(c % 3 != 0)a = a | (1<<i);
            // }
            // cout<<endl<<a<<endl;
    // iska main target hai joo bit 3 baar aa rhi hai usse ones and twos mai se hatana;       
    nums = {1,2,3,1,2,1,2};
    int ones = 0, twos = 0;
    for(int i = 0;i<nums.size();i++){
        ones = (ones^ nums[i]) & ~(twos);
        twos = (twos^ nums[i]) & ~ones;
    }
    cout<<endl<<ones<<endl;
    
     // find which 2 no. occour ones;
    nums = {1,2,3,4,1,2,5,3};
    a = 0;
    for(auto i:nums) a = a^i;
    a = (a & (a-1)) ^ a; //jha ye one de rha hai vaha pr hamare 2 no. ki bit diff hai;

    int one = 0, zero = 0;
    for(int i = 0;i<nums.size();i++){
        if(a & nums[i]) one = one^nums[i];
        else zero = zero^ nums[i]; 
    }
    cout<<endl<<one<<" "<<zero<<endl;

    // XOR of given range from l to r;
    int l = 7, r = 15;
    int ans = findxor(r);
    int aa = findxor(l-1);
    cout<<(aa^ans)<<endl<<endl;

    // 29. "Divide Two Integers" in leetcode is done go through it;

    

}