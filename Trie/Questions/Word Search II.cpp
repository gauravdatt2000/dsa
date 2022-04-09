// question : https://leetcode.com/problems/word-search-ii/

#include"bits/stdc++.h"
using namespace std ;

class  Node {
    public :
    map<char , Node* > Data ; 
    bool IsEnd = false ;
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



int main(void){
    
    int n , m , x ;
    cin>>n>>m ;
    
    Trie t1 ;
    vector<string> vs ;
    string sn;
    
    for(int i=0 ; i<n ; i++){
        cin>>sn;
        vs.push_back(sn) ;
    }

    cin>>x;

    for(int i=0 ; i<x; i++){
        cin>>sn;
        t1.insert(sn) ;
    }

    vector<string> ans ;

    for(int i = 0 ; i<n ; i++){

        for(int j = 0 ; j<m ; j++){


        }

    }

}