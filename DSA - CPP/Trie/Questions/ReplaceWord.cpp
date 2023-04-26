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
    
    
    string Replacement(string &s1){
        
        string ans = "" ;
        
        Node *tmp_root = root ;

        for(auto x : s1 ){
            
            if(tmp_root->Data[x]==nullptr){
             if(tmp_root->IsEnd){
                    return ans ;
                }
               return s1 ;
            }
            
           
            if(tmp_root->IsEnd){
                return ans ;
            }
             ans+= x ;
            tmp_root = tmp_root->Data[x]  ;
            
            
        }
        
        return s1  ;
        
    }

};

int main(void){
    
    string cmd , str ;
    Trie t1 ;
    
    int num ;
    cin>>num;
    
    while(num--){
        cin>>cmd;
        t1.insert(cmd) ;
    }
    
    vector<string> vs ;
    while(cin>>str){
        vs.push_back(str) ;
    }
    
    int len = vs.size() ;
    
    for(int i=0 ; i<len ; i++ ){
        
        if(i==len-1){
            cout<<t1.Replacement( vs[i] ) ;
            continue ;
        }
        
        cout<<t1.Replacement( vs[i] ) ;
        cout<<" ";
        
        
    }
 

}