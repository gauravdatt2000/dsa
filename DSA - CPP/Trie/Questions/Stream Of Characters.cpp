#include "bits/stdc++.h"
using namespace std ;

// question : https://leetcode.com/problems/stream-of-characters/

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

    bool search_mod(string s1){
        
        reverse(s1.begin() , s1.end()) ;
        // cout<<s1<<" ";

        Node *tmp_root = root ;

        for(auto x : s1 ){
            
            if(tmp_root->Data[x]==nullptr){
                return false;
            }

            if(tmp_root->Data[x]!=nullptr and tmp_root->Data[x]->IsEnd ){
                return true ;
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

    // while(cin>>cmd>>str){

    //     if(cmd == "insert"){
    //         t1.insert(str) ;
    //         continue ;
    //     }
    //     else if(cmd == "search"){
    //         cout<< ( (t1.search(str) ) ? "true" : "false" )<<endl;
    //         continue ;
    //     }
    //     else if(cmd == "startsWith"){
    //         cout<< ( (t1.startsWith(str) ) ? "true" : "false" )<<endl;
    //         continue ;
    //     }
    //     return 0 ;

    // }

    int n1 , n2 ;
    cin>>n1 ;

    for(int i=0 ; i<n1 ; i++ ){

        string tmp ;
        cin>>tmp;
        reverse(tmp.begin() , tmp.end()) ;
        t1.insert(tmp) ;

    }

    cin>>n2 ;
    string worldStream = "" ;

    for(int i=0 ; i<n2 ; i++){
        char tmpChar ;
        cin>>tmpChar ;
        worldStream+=tmpChar ;
        // reverse(worldStream.begin() , worldStream.end()) ;
        bool ans = t1.search_mod(worldStream) ;
        // cout<<worldStream<<" ";
        cout<< ( ans ? "true" : "false" ) <<endl;
        // reverse(worldStream.begin() , worldStream.end()) ;
    }



}