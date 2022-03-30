#include "bits/stdc++.h"
using namespace std ;

// question : https://leetcode.com/problems/longest-word-in-dictionary/

class  Node {
    public :
    map<char , Node* > Data ; 
    bool IsEnd = false ;
};

class FinalAns{
    public :
    string ans = "" ;

    void update(string &s){      
        if(s.size() > ans.size() ){
            ans = s ;
            return ;
        }
        vector<string> v1;
        v1.push_back(ans) ;
        v1.push_back(s) ;
        sort(v1.begin() , v1.end()) ;
        ans = v1[0] ;
    }

    void print(){
        cout<<ans<<endl;
    }

};

class Trie{
    
    public :    
    Node *root = nullptr ;
    
    Trie(){
        root = new Node() ;
    } 

    void insert(string &s1){
        Node *tmp_root = root ;

        for(auto x : s1 ){
            
            if(tmp_root->Data[x]==nullptr){
                tmp_root->Data[x] = new Node() ;
            }
            tmp_root = tmp_root->Data[x]  ;
        }

        tmp_root->IsEnd = true  ;

    }

    bool search(string &s1){
        
        Node *tmp_root = root ;

        for(auto x : s1 ){
            
            if(tmp_root->Data[x]==nullptr){
                return false;
            }
            tmp_root = tmp_root->Data[x]  ;
        }

        return tmp_root->IsEnd ;

    }

    bool startsWith(string &s1){
        
        Node *tmp_root = root ;

        for(auto x : s1 ){
            
            if(tmp_root->Data[x]==nullptr){
               return false ;
            }
            tmp_root = tmp_root->Data[x]  ;
        }

        return true  ;

    }


};


void longestword(Node *root , Trie &t1 , FinalAns &Ans , string s1 ){
    
    bool pre = false ;

    if(root == t1.root or root->IsEnd){
        pre = true ;
    }
    Ans.update(s1) ;
    
    for(auto x : root->Data ){
        char k = x.first ;
        Node *n1 = x.second ;
        if(n1->IsEnd and pre){
            string newStr = s1 ;
            newStr+=k ; 
            longestword(n1 , t1 , Ans , newStr );
        }

    }

}




int main(void){

    int num;
    cin>>num ;
    string s1;

    Trie t1 ;
    FinalAns Ans ;
    
    while(num--){
        cin>>s1 ;
        t1.insert(s1) ;
    }

    longestword(t1.root , t1 , Ans , "") ;

    Ans.print() ;


}