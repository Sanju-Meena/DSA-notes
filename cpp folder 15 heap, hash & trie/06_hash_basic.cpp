#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int main(){
    string st = "mera naam sanjay hai";
    // question is maximum occuring word konsa hai;
    // yaha hum fas gaye hai yaha use hoga map joo key value pair store karta hai;
    // unordered map mai maping according to hashtable k hisaab se hoti hai;
    
    // creation;
    unordered_map<string,int> m;   
    // method 1
    // pair<string,int> p = {"mera",2};
    pair<string,int> p = make_pair("mera",2); 
    m.insert(p);
    pair<string,int> pa("sanjay",3);
    m.insert(pa);

    m["naam"] = 5;
    m["hai"] = 6;
    m["naam"] = 4;
    //  map mai pahele check hota ki key present hai ya nahi if key present hai too value update hoti hai and
    //  absent hai too new key value pair bn jata hai;
    
    // display function;
    cout<<"mera = "<<m["mera"]<<endl;
    cout<<"naam = "<<m["naam"]<<endl;
    
    // at function ka use karke ;
    cout<<"sanjay = "<<m.at("sanjay")<<endl;
    cout<<"meena = "<<m["meena"]<<endl;       // meena k corresspondig entry nhi thi ab new entry bn jati hai kuch is prakaar m["meena"] = 0;
    cout<<"meena = "<<m.at("meena")<<endl;    //upar vali line koo nhi likhte too ye line segmentation fault deti but meena key exist than it gave ans ;
    
    // check size of map;
    cout<<"size of map is "<<m.size()<<endl;
    
    // check absence or present of a key;
    cout<<"is meena present "<<m.count("meena")<<" means yes; "<<endl; //present hai too 1 dega;
    cout<<"is ramdi present "<<m.count("ramdi")<<endl; //absence mai 0 dega;
    
    //erase function;
    m.erase("meena");
    cout<<"is meena present "<<m.count("meena")<<endl;;
    cout<<"size of map is "<<m.size()<<endl;
    
    // to check key is present or not;
    auto i = m.find("amisha"); // TC = O(log(n))
    if(i == m.end()){cout<<"amisha is not present\n";}//m.find take only key value.
    else{cout<<(*i).first<<" "<<(*i).second<<endl;}
    
    auto its = m.find("sanjay"); // TC = O(log(n));
    if(its == m.end()){cout<<"no value\n";}//m.find take only key value.
    else{cout<<(*its).first<<" "<<its->second<<endl;}
    
    // display entry;
    cout<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;
    
    //method 2;
    unordered_map<string,int> ::iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }cout<<endl;
    
    // count all the number which have maximum frequency;
    vector<int> nums = {10,12,11,9,6,11,19};
    unordered_map<int,int> ma;
   for(int i = 0;i<nums.size();i++){ma[nums[i]]++;}
   
   int max = 0;
   for(auto i:ma){if(i.second > max){max = i.second;}}
   int c = 0;
   for(auto j :ma){if(j.second == max){c++;}}
    cout<< max*c<<endl;
    
}
/*
**** basic hash map;
unordered_map mai insertion, deletion and searching ki TC = O(1);
ordered map k case mai hai TC = O(log(n));

There are two main parts to a hash map:
An Array (or Buckets): This is the underlying storage. You can imagine it as a list of empty slots,
like mailboxes in a post office.

A Hash Function: It's a special function that takes your key (which can be a string, a number, or any
object) and converts it into an integer. This integer(this integer is called hash code) corresponds 
to an index in the array.

In hash function there are two main step:
1st step is done by hash code (like sum of ASCII value code,or any other code);
Be Consistent: hash code Always produce the same integer for the same key. 

The compression function is the second step. Its job is to take that large, unbound integer (the hash code) and
 "compress" it down into a small, valid index that fits within your array.
Input: The hash code (e.g., 48392019)
Output: A valid array index (e.g., 9)
The most common and simple compression function is the modulo (%) operator.
If you have an array of size N, your compression function is just: index = hash_code % N;

A collision happens when the hash function generates the same array index for two or more different keys.
This is a normal and expected part of hash maps. The goal is not to prevent collisions (that's impossible 
with a limited array size) but to manage them efficiently.
There are two primary ways to solve this problem:

## 1. Separate Chaining (open hashing) best method;
This strategy solves the problem by not storing the items directly in the array slot. Instead, 
each array slot holds a pointer to another data structure usually a linked list.

## 2. Open Addressing (Probing)
This strategy solves the problem by storing all items directly in the main array. When a collision
happens, it just finds the next open slot and puts the item there.
Probing Method	How It Finds the Next Slot (for probe i)
Linear Probing	(hash + i)	Primary Clustering (Bad)
Quadratic Probing	(hash + i^2)	Secondary Clustering (Okay)
Double Hashing	(hash1 + i * hash2)	None (Excellent)


## The Load Factor (α)
One final, important concept is the Load Factor. This is the key metric that helps a hash map decide
when it's "too full" and needs to fix itself to prevent the worst-case scenario.

Load Factor (α) = (Number of items stored) / (Total number of slots in the array)
If α is low (e.g., 0.2), the map is mostly empty. Operations are fast, but you're wasting a lot of space.
If α is high (e.g., 2.0), the map is very full. Collisions are frequent, and performance starts to slow down, approaching O(n).
Most hash map implementations (like std::unordered_map) have a target load factor (<= 0.75).
When the load factor gets higher than this, the map automatically performs a rehashing:
It creates a new, bigger array (e.g., double the size).
It goes through all the old items, re-hashes them for the new size, and inserts them into the new array.
This rehashing operation itself is slow (it's an O(n) operation), but it only happens occasionally and 
ensures that the average case performance remains O(1) over the long run.
*/