#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
// question is lowest common prefix;(Hint: find childcount and also check it root trinode is terminal node or not;)


class trinode{
    public :
    char data;
    trinode* children[26];
    int cc;
    bool isterminal;

    trinode(char ch ){
        this->data = ch;
        for(int i = 0;i<26;i++){children[i] = NULL;}
        this->isterminal = false;
        this->cc = 0;
    }
};

class trie{
    public:
    trinode* root = new trinode('\0');
    // trinode *root ;
    // trie(){root = new trinode('\0');}

    void insertutil(trinode* root,string word){
        if(word.length() == 0){
            root->isterminal = true; return;
        }
        // Assume that word is in capital letter(CAPS);
        int index = word[0] - 'a';
        trinode* child;

        // present
        if(root ->children[index] != NULL){
            child = root->children[index];
        }else{
            // absent
            child = new trinode(word[0]);
            root->children[index] = child;
            root->cc++;
        }

        insertutil(child,word.substr(1));
        // word.substr(1)
    }

    void insertword(string word){
        insertutil(root,word);
    }
    
    void lcp(string strs,string &ans){
        
        for(int i = 0;i<strs.size();i++){
            int c = root->cc;
            if(c == 1){
                ans.push_back(strs[i]);
                int ind = strs[i] - 'a';
                root = root->children[strs[i] - 'a'];
            }else return ;

            if(root->isterminal == true){return ;}
            
        }
    }


};

int main(){
    trie* t = new trie();
    vector<string> strs ={"a","ab"};
    // vector<string> strs ={"flower","flow","flight"};
     for(int i = 0;i<strs.size();i++){
         t->insertword(strs[i]);
    }
    string st;
    
    t->lcp(strs[0],st);
    cout<<st<<endl;
}