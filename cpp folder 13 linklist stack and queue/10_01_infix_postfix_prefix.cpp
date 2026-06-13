#include<iostream>
#include<string>
#include<stack>
using namespace std;

int prio(char ch){
    if(ch == '^')return 3;
    else if(ch == '*' || ch == '/')return 2;
    else if(ch == '+' || ch == '-')return 1;
    return 0;
}

int main(){
    /*
    Q1. first question infix to postfix;
    ex: a+b*(c^d-e)^(f+g*h)-i 
    ans :abcd^e-fgh*+^*+i-
    
    ex:2 h^m^q^(7-4)
    ans:hmq74-^^^
    */

    string s = "a+b*(c^d-e)^(f+g*h)-i ";
    stack<char> sta;
    string ans;
    for(int i = 0;i<s.length();i++){
        char ch = s[i];
        if((ch >= 'a' && ch<='z') || (ch>='0' && ch<='9') || ch >= 'A' && ch <= 'Z'){ans.push_back(ch);}
        else if(ch == '(' ){sta.push(ch);}
        else if(ch == ')'){
            while(sta.size() != 0 && sta.top() != '(' ){
                ans.push_back(sta.top());
                sta.pop();
            }
            sta.pop();
        }
        else{
            // The power operator (^) is right-associative means 2^3^1 = 2^3 = 8; ans unlike other operator;
            if(sta.empty() || sta.top() == '(' || prio(sta.top()) < prio(ch) || (ch == '^' && sta.top() == '^')) sta.push(ch);
            else{
                while(sta.size() != 0 && prio(sta.top()) >= prio(ch)){
                    ans.push_back(sta.top());
                    sta.pop();
                }
                sta.push(ch);
            }
            
        }
    }
    
    while(sta.size()){
        ans.push_back(sta.top());
        sta.pop();
    }
    cout<<ans<<endl<<endl;
    
    /* Q2. Infix to prefix; */
    reverse(s.begin(),s.end());
    for(int i = 0;i<s.length();i++){
        if(s[i] == '(')s[i] = ')';
        else if(s[i] == ')')s[i] = '(';
    }
    
    stack<char> st;
    ans = "";
    for(int i = 0;i<s.length();i++){
        char ch = s[i];
        if((ch >= 'a' && ch<='z') || (ch>='0' && ch<='9') || (ch >= 'A' && ch <= 'Z') ){ans.push_back(ch);}
        else if(ch == '('){st.push(ch);}
        else if(ch == ')'){
            while(st.size() != 0 && st.top() != '('){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            if(ch == '^'){
                while(!st.empty() && prio(st.top() ) >= prio(ch)){ans.push_back(st.top()); st.pop();}
            }
            else{
                while(!st.empty() && prio(st.top() ) > prio(ch)){ans.push_back(st.top()); st.pop();}  
            }
            st.push(ch);
        }
    }
    
    
    while(st.size()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl<<endl;
    
    // Q3.postfix to infix;
    
        

}