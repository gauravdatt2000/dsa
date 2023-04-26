#include "bits/stdc++.h"
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
    
    string cmd , str ;
    Trie t1 ;

    while(cin>>cmd>>str){

        if(cmd == "insert"){
            t1.insert(str) ;
            continue ;
        }
        else if(cmd == "search"){
            cout<< ( (t1.search(str) ) ? "true" : "false" )<<endl;
            continue ;
        }
        else if(cmd == "startsWith"){
            cout<< ( (t1.startsWith(str) ) ? "true" : "false" )<<endl;
            continue ;
        }
        return 0 ;

    }

}