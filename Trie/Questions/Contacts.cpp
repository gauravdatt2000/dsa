/*

Tries Ds question 1
 
Question Name : Contact
Question Link : https://www.hackerrank.com/challenges/contacts/problem?isFullScreen=true
Question From : Hackerrank
*/

#include "bits/stdc++.h"
using namespace std ;

class Node{
    
    public : 
    map<char , pair <int , Node*> > Data ;
    bool IsEnd = false ;
    
};

class Mod_Trie{
    public :
  Node* root = nullptr ;
  
  Mod_Trie(){ root = new Node() ; }
  
 
  void add(string &s1){
    Node *curr_root = root ;
      
    for(auto x : s1 ){
        
        if(curr_root->Data[x].second == nullptr ){
            curr_root->Data[x].first++;
            curr_root->Data[x].second = new Node() ;
        }
        else{
            curr_root->Data[x].first++;    
        }
        
        curr_root =curr_root->Data[x].second ;
        
    }
      
  }  
  
  int find( string &s1){
    
    Node *curr_root = root ;
    char k = '\0' ;
    int ans = 0 ; 
    for(auto x : s1 ){
        
        k = x ;
        if(curr_root->Data[x].second == nullptr ){
            return 0 ;
        }
        
        ans =  curr_root->Data[x].first ;
        curr_root =curr_root->Data[x].second ;
        
    }
    
    return ans ;
    
  }
  
  
};

int main(void){
    
    int t;
    cin>> t ;
    
    string cmd , s1 ;
    
    Mod_Trie t1 ;
    
    while(t--){
        
        cin>>cmd>>s1 ;
        
        if(cmd=="add"){
            t1.add(s1) ;
        }
        else if(cmd=="find"){
            cout<<t1.find(s1)<<endl;
        }
                
    }
    
}
