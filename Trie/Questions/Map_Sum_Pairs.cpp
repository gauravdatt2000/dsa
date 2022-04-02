// question: https://leetcode.com/problems/map-sum-pairs/

#include "bits/stdc++.h"
#define usll long
using namespace std ;


class  Node {
    public :
    map<char , Node* > Data ; 
    bool IsEnd = false ;
    usll contribution = 0 ;
    usll value = 0 ; 
};

class Trie{
    
    public :    
    Node *root = nullptr ;
    
    Trie(){
        root = new Node() ;
    } 

    void insert_mod(string &s1 , usll val){
        Node *tmp_root = root ;

        for(auto x : s1 ){
            
            if(tmp_root->Data[x]==nullptr){
                tmp_root->Data[x] = new Node()  ;
            }
            tmp_root = tmp_root->Data[x]  ;
            tmp_root->contribution += val ;
        }
        tmp_root->value = val;
        tmp_root->IsEnd = true  ;

    }

    void update_value(string &s1 , usll val){
        Node *tmp_root = root ;

        for(auto x : s1 ){
            
            if(tmp_root->Data[x]==nullptr){
                tmp_root->Data[x] = new Node()  ;
            }
            tmp_root = tmp_root->Data[x]  ;
        }
        tmp_root->value = val;
        tmp_root->IsEnd = true  ;

    }

    pair<bool , usll > search(string &s1){
        
        Node *tmp_root = root ;

        for(auto x : s1 ){
            
            if(tmp_root->Data[x]==nullptr){
                return pair <bool , usll> (false , 0);
            }
            tmp_root = tmp_root->Data[x]  ;
        }

        return pair <bool , usll> (tmp_root->IsEnd , tmp_root->value) ;

    }

    usll startsWith_Mod(string &s1){
        
        Node *tmp_root = root ;

        for(auto x : s1 ){
            
            if(tmp_root->Data[x]==nullptr){
               return 0 ;
            }
            tmp_root = tmp_root->Data[x]  ;
        }

        return tmp_root->contribution  ;

    }

};

usll str_to_usll(string s1){
    usll ans = 0 ;

    for(auto x : s1 ){
        ans = ans*10  + int(x-'0') ;
    }

    return ans ;
}

int main(void){
    
    string str ;
    Trie t1 ;

    while(true){
        
        getline(cin , str) ;
        string chardata = "" , numdata = "" ;
        if(str=="exit") return 0;

        // process start
        int len = str.length() , i = 0 ;

        // word
        while( i < len and str[i]!=' ' ){
            chardata+= str[i] ;
            i++;
        }

        // space
        while( i < len and str[i]==' ' ){
            i++;
        }

        while( i < len and str[i]!=' ' and str[i] <= '9' and str[i] >= '0' ){
            numdata+= str[i] ;
            i++;
        }

        // process end 

        // cout<<str<<endl;
        // cout<<chardata<<","<<numdata<<endl;
        
        if( numdata.length() ){
            usll num = str_to_usll( numdata ) ;
            
            // cout<<"pair ==> "<<chardata<<" "<<num<<endl;
            pair <bool , usll> chk_data = t1.search(chardata) ;

            if( !chk_data.first ){
                t1.insert_mod(chardata , num ) ;
            }
            else{

                t1.insert_mod(chardata , chk_data.second * (-1) ) ;
                t1.update_value(chardata , 0);
                t1.insert_mod(chardata , num ) ;
            }

            continue ;   
        }

        usll ans = 0 ;
        ans = t1.startsWith_Mod(chardata) ;
        cout<<ans<<endl;

        // cout<<"check ==>"<<chardata<<endl;

    }

}