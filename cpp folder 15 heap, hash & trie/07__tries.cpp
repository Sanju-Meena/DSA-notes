#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
/*
string word = "power";
word.substr(0)	Kuch nahi chhodna (index 0 se shuru)	"POWER"
word.substr(1)	Pehla character chhodna (index 1 se shuru)	"OWER"
word.substr(2)	Pehle 2 character chhodna (index 2 se shuru)	"WER"
word.substr(3)	Pehle 3 character chhodna (index 3 se shuru)	"ER"
*/

// class trinode{
//     public :
//     char data;
//     trinode* children[26];
//     bool isterminal;

//     trinode(char ch ){
//         this->data = ch;
//         for(int i = 0;i<26;i++){children[i] = NULL;}
//         this->isterminal = false;
//     }
// };

class trie{
    private:
    class trinode{
        public :
        char data;
        trinode* children[26];
        bool isterminal;
        
        trinode(char ch ){
            this->data = ch;
            for(int i = 0;i<26;i++){children[i] = NULL;}
            this->isterminal = false;
        }
    };
    
    public:
    trinode* root = new trinode('\0');
    // trinode *root ;
    // trie(){root = new trinode('\0');}

    void insertutil(trinode* root,string word){
        if(word.length() == 0){
            root->isterminal = true; return;
        }
        // Assume that word is in capital letter(CAPS);
        int index = word[0] - 'A';
        trinode* child;

        // present
        if(root ->children[index] != NULL){
            child = root->children[index];
        }else{
            // absent
            child = new trinode(word[0]);
            root->children[index] = child;
        }

        insertutil(child,word.substr(1));
        // word.substr(1)
    }

    void insertword(string word){
        insertutil(root,word);
    }

    bool searchutil(trinode* root,string word){
        if(word.length() == 0){
            return root->isterminal;
        }
        int ind = word[0] - 'A';
        trinode* child;

        if(root->children[ind] != NULL){
            child = root->children[ind];
        }else return false;

        return searchutil(child,word.substr(1));
    }

    bool searchword(string word){
        return searchutil(root,word);
    }

    void completeremove(string word, trinode* root){
        if(word.length() == 0){root ->isterminal = false; return ;}

        int ind = word[0] - 'A';
        trinode *child = root->children[ind];
        if(child == NULL){return ;}
        completeremove(word.substr(1),child);
    }
    void remove(string word){
        completeremove(word,root);
    }
};

int main(){
    trie* t = new trie();
    // is similar too node* t = new node(d); d = \0;

    t->insertword("ABCD");
    t->insertword("ARM");
    t->insertword("TIMER");
    cout<<"Present or Not ABCD "<<t->searchword("ABCD")<<endl;
    cout<<"Present or Not ABC "<<t->searchword("ABC")<<endl;
    cout<<"Present or Not TIMER "<<t->searchword("TIMER")<<endl;
    cout<<"Present or Not TIM "<<t->searchword("TIM")<<endl;
    
    // REMOVE ABCD;
    t->remove("ABCD");
    cout<<"Present or Not ABCD "<<t->searchword("ABCD")<<endl;
}


