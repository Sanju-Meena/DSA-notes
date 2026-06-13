#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
// baad mai vapis karna;

class trinode{
    public:
    char data ;
    trinode* children[26];
    bool isterminal;
    int cc;
    
    trinode(char da){
        this->data = da;
        for(int i = 0;i<26;i++){children[i] = NULL;}
        this->isterminal = false;
    }
};

class trie{
    public:
    trinode* root = new trinode('\0');
    void isinser(trinode* root,string st){
        if(st.length() == 0){ root->isterminal = true; return ;}
        int ind = st[0] - 'a';
        trinode* child;
        if(root->children[ind] == NULL){
            child = new trinode(st[0]);
            root->children[ind] = child;
        }else{
            child = root->children[ind];
        }
        isinser(child,st.substr(1));
    }
    
    void insert(string st){isinser(root,st);}
    
    void printallsugg(trinode* curr,vector<string> &temp,string prefix){
        if(curr->isterminal){temp.push_back(prefix);}
        
        for(char ch = 'a'; ch<='z';ch++){
            trinode* next =  curr->children[ch-'a'];
            if(next != NULL){
                prefix.push_back(ch);
                printallsugg(next,temp,prefix);
                prefix.pop_back();
            }
        }
        
    }
    
    void pdi(string s,vector<vector<string>> &v){
        trinode* prev = root;
        string prefix = "";
        
        for(int i = 0;i<s.length();i++){
            char lastch = s[i];
            prefix.push_back(lastch);
            // prev = updataed root;
            vector<string> temp;
            trinode* curr;
            if(prev == NULL){curr = NULL;}
            else{curr = prev->children[lastch - 'a'];}
            if(curr == NULL){
                temp.push_back("0");
                v.push_back(temp);
                prev = NULL;
            }
            else{
            printallsugg(curr,temp,prefix);
            if(temp.size() == 0)temp.push_back("0");
            v.push_back(temp);
            temp.clear();
            prev = curr;
            }
        }
        return ;
    }
    
};

int main(){
        // code here
        int n = 3;
        string contact[] = {"sanj", "sund", "sanday"};
        string s = "sand";

        trie* t = new trie();
        vector<vector<string>> v;
            
        for(int i = 0;i<n;i++){
            t->insert(contact[i]);
        }
            
        t->pdi(s,v);
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<v[i].size();j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
}