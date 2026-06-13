#include<iostream>
#include<stack>
#include<vector>

using namespace std;
/* Q1: delete middle element from stack;
   Q2: valid paranthesis: ([{()}]){} is balanced;
   Q3: Reverse stack using recursion;***
   Q4: Sort a stack using recursion; 
   Q5: Redundant bracket; means extra bracket used in expression;
   Q6: Minimum cost to make valid expression; {{}{ -->cost = 1; 
   Q7: Print next smaller element in stack; *********
*/
void print(stack<int> s){
    int l = s.size();
     for(int i = 0;i<l;i++){
        cout<<s.top()<<" ";
        s.pop();
    } 
    cout<<endl;
} 

void reverse_print(stack<char> s){
    if(s.empty()){return ;}
    char a = s.top();
    s.pop();
    reverse_print(s);
    cout<<a;
}

//ans - 1 by sir step;
// void middledelete(stack<int> &st,int mid,int l){
//     if(st.size() == l/2+1 && l%2 == 1 ){st.pop(); return ;}
//     else if(st.size() == l/2 ){st.pop(); return ;}
//     int a = st.top();
//     st.pop();
//     middledelete(st,mid,l);
//     st.push(a);
// } 


// // ans -3 by me;
// void insert_at_bottom(stack<int> &s,int ele){
    
//     if(s.size() == 0){s.push(ele); return;}
//     int a = s.top();
//     s.pop();
//     insert_at_bottom(s,ele);
//     s.push(a);
//     return ;
// }

// void reverse(stack<int> &s){
//     if(s.empty()){return ;}
//     int a = s.top();
//     s.pop();
//     reverse(s);
//     insert_at_bottom(s,a);
// }

// ans -4 by me;
// void insert_at_correct_pos(stack<int> &s,int ele){
    
//     if(s.size() == 0){s.push(ele); return ;}
//     if(s.top() < ele){s.push(ele); return;}
//     int b = s.top();
//     s.pop();
//     insert_at_correct_pos(s,ele);
//     s.push(b);
//     return ;
// }

// void sort(stack<int> &s){
    //     if(s.size() == 1 || s.size() == 0){return ;}
//     int a = s.top();
//     s.pop();
//     sort(s);
//     insert_at_correct_pos(s,a);
// }

/*ans - 7 by sir*/
void nextsmaller(vector<int> v,stack<int> s,int n,vector<int> &ns){
    if(n == 0){return ;}

    int curr = v[n-1];
    while(s.top() > curr){s.pop();}
    ns.push_back(s.top());
    s.push(curr);
    n--;
    nextsmaller(v,s,n,ns);
}

void prevsmaller(vector<int> v,stack<int> s,int n,vector<int> &ps){
    if(n == v.size()){return ;}

    int curr = v[n];
    while(s.top() > curr){s.pop();}
    ps.push_back(s.top());
    s.push(curr);
    n++;
    prevsmaller(v,s,n,ps);
}

int main(){
/* ans = 1*/
    // By me;
    // stack<int> s;
    // int n;
    // cin>>n;
    // for(int i = 0;i<n; i++){
    //     int a;
    //     cin>>a;
    //     s.push(a);
    // }
    // int l = s.size();
    // stack<int> str;
    // for(int i = 0;i<l/2;i++){
    //     str.push(s.top());
    //     s.pop();
    // }
    // s.pop();
    // int le = str.size();
    // for(int i = 0;i<le;i++){
    //     s.push(str.top());
    //     str.pop();
    // }
    // print(s);
    // By sir; good because minimum space they taken;

    // stack<int> s;
    // int n;
    // cin>>n;
    // for(int i = 0;i<n; i++){
    //     int a;
    //     cin>>a;
    //     s.push(a);
    // }
    // int l = s.size();
    // middledelete(s,l/2,l);
    // print(s);

    /*ans  -> 2*/
    // My approach is same but i take string + vector ;
    // int t;
//     cin>>t;
//     while(t--){
//         stack<char> v;
//     string st;
//     cin>>st;
//     int n = st.length();
//     int check = 0;
//     for(int i = 0;i<n;i++){
//         char ch = st[i],c;
//         if(v.size() != 0){c = v.top();}
        
//         if(ch == '{' || ch == '[' || ch == '('){v.push(st[i]);}
//         else if(c =='(' && ch == ')' || c =='[' && ch == ']' || c =='{' && ch == '}' ){v.pop();}
//         else{check = 1; break;}
//     }
//     if(check == 0 && v.size() == 0 ){cout<<"Balanced\n";}
//     else{cout<<"Not Balances\n";}
// }

/*ans  -> 3 method 1; aap empty stack loo and usmai value dalwa loo or atlast original stack = joo empty stack banaya tha;*/ 
    // stack<int> s;
    // int n;
    // cin>>n;
    // for(int i = 0;i<n; i++){
    //     int a;
    //     cin>>a;
    //     s.push(a);
    // }
    // print(s);
    // reverse(s);
    // print(s);
    

    /*ans  -> 4 method 1; by recursion;*/ 
    // stack<int> s;
    // int n;
    // cin>>n;
    // for(int i = 0;i<n; i++){
    //     int a;
    //     cin>>a;
    //     s.push(a);
    // }
    // print(s);
    // sort(s);
    // print(s);

    /*ans  -> 5 method 1; by recursion;*/ 
    // Redundant bracket is present or not;
    // int test ;
    // cin>>test;
    // while(test--){
    // string st;
    // cin>>st;
    // stack<char> s;
    // int n = st.length();
    // int check = 0;
    // for(int i = 0;i<n; i++){
    //     char ch = st[i];
    //     if(ch >= 'a' && ch<='z'){continue;}
    //     else if(s.size() == 0 && ch == ')' ){check = 1; break;}
    //     else if(ch == '(' ){s.push(ch);}
    //     else if(s.size() == 0 ){continue;}
    //     else{
    //         char t = s.top();
    //         if((ch == '+' || ch == '-' || ch == '*' || ch == '/') &&
    //         (t == '+' || t == '-' || t == '*' || t == '/')){continue;}
    //         if((ch == '+' || ch == '-' || ch == '*' || ch == '/') && (t == '(') ){s.push(ch);}
            
    //         else if(ch == ')' &&  (t == '+' || t == '-' || t == '*' || t == '/') ){s.pop(); s.pop();}
    //         else if(ch == ')' && t == '('){check = 1; break;}
    //     }
    // }
    // if(check == 1){cout<<"Redundant bracket is present;\n";}
    // else if(check == 0 && s.size() == 0){cout<<"Redundant bracket is not present;\n";}
    // }
    
    /*ans  -> 6 */ 
    // minimum cost to make valid expression;
    // int test ;
    // cin>>test;
    // while(test--){
    // string str;
    // cin>>str;
    // stack<char> s;
    // int n = str.length();
    // int a = 0;
    // if(n%2 == 1){cout<<-1<<endl; return -1;}
    // else{
    //     for(int i = 0;i<n; i++){
    //         char ch = str[i];
    //         if(ch == '{'){a++;}
    //         else if(ch == '}'){a--;}
            
    //         if(a<0){s.push(ch); a = 0;}
    //     }

    //     while(a!= 0 ){s.push('{'); a--;}
    //     reverse_print(s);
    //     cout<<endl;
    //     int l = s.size();
    //     if(l%2 == 1){cout<<"-1";}
    //     else{
    //         int p = 0,q = 0;
    //         while(s.size() != 0){
    //             char ch = s.top();
    //             s.pop();
    //             if(ch == '{'){q++;}
    //             else{p++;}
    //         }
    //         int ans = ((p+1)/2 ) + ((q+1)/2);
    //         cout<<ans<<endl;
    //         // if(p%2 == 1 && q%2 == 1){cout<<((p+q)/2)+1<<endl;}
    //         // else{cout<<(p+q)/2<<endl;}
    //     }
    // }   
    

    /*ans -> 7 Next smaller element print;*/
    // int n;
    // cin>>n;
    // stack<int> s;
    // for(int i = 0;i<n;i++){
    //     int a;
    //     cin>>a;
    //     s.push(a);
    // }
    // reverse_stack(s);
    // print(s);
    // if(s.size() > 1 ){print_next_greater(s);}
    // else{cout<<-1<<endl;}

    // method -2 by sir ;
    // next smaller element store in stack;
    // int n;
    // cin>>n;
    // vector<int> v;
    // for(int i = 0;i<n;i++){
    //     int a;
    //     cin>>a;
    //     v.push_back(a);
    // }
    // stack<int> s;
    // int ch = 0;
    // if(v.size() > 1 ){
    //     for(int i = n-1;i>=0;i--){
    //         ch = 0;
    //         for(int j = i;j<n-1;j++){
    //             int curr = v[i];
    //             if(v[i] >v[j+1]){
    //                 s.push(v[j+1]);
    //                 ch = 1;
    //                 break;
    //             }
    //         }            
    //         if(ch == 0){s.push(-1);}
    //     }
    //     // for(int i = n-1;i>=0;i--){
    //     //     int curr = v[i];
    //     //     while(s.top() >= curr){
    //     //         s.pop();
    //     //     }
    //     //     curr = s.top();
    //     //     s.push(curr);
    //     // }
    //     print(s);
    // }
    // else{cout<<-1<<endl;}

    // method:-3 by sir;
      int n;
    cin>>n;
    vector<int> v;
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    vector<int> ns;
    stack<int> s;
    s.push(-1);
    nextsmaller(v,s,n,ns);
    for(auto i: ns){cout<<i<<" ";}
    cout<<endl;
    
    vector<int> ps;
    stack<int> p;
    p.push(-1);
    prevsmaller(v,p,0,ps);
    for(auto i: ps){cout<<i<<" ";}
    cout<<endl;


}