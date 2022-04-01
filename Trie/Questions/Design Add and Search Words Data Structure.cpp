// question : https://leetcode.com/problems/design-add-and-search-words-data-structure/

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

    bool mod_search(string &s1 , int index , Node *next ){

        bool sol = true ;
        
        if( index == s1.size() ){
            return next->IsEnd ;
        } 
        
        bool future_sol = false ;

        if( s1[index]=='.'){

            bool maybe = false;

            for(auto x : next->Data ){
                maybe = maybe or mod_search(s1 , index+1 , x.second ) ;
                if(maybe){
                    return maybe ;
                }
            }
            return false ;

        }
        else if( next->Data.find(s1[index]) != next->Data.end() ){
            future_sol = true and mod_search(s1 , index+1 , next->Data[ s1[ index ] ] ) ;
        }
        
        return sol and future_sol  ;

    }

};


int main(void){
    
    
    string cmd , str ;
    Trie t1 ;

    while(cin>>cmd>>str){

        if(cmd == "addWord"){
            t1.insert(str) ;
            continue ;
        }
        else if(cmd == "search"){
            cout<< ( (t1.mod_search(str , 0 , t1.root) ) ? "true" : "false" )<<endl;
        }

    }

}