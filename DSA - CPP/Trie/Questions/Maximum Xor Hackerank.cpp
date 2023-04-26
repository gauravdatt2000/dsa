// root question : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// question : https://www.hackerrank.com/challenges/maximum-xor/problem

/*

Greedy sol  , Data Structure (Trie)

Bruteforce : will take n sqaure 
:take one number and check with all other number ;
:so to optimise it we have to find some thing n * O(1) 
: ...
: ...
: ...
: O(1) can be achive if we use Trie data structure and store it's binary in trie

: In which order we should store 
: From hingher bit to lower bit
: Because lower bit matter least
: but there could be a testcase where  ( Nth bit 2 power n )  < ( sum Remaining N-1th bit  of 2 pow n-1 )
:....(after observation)

Greedy observation : ( 2 power n )  > ( sum of 2 pow n-1 ) 
8 > 1+2+4 ===> ( 8 > 7 )
16 >  1+2+4+8 (16 > 15)

... can be done
... Lets write code 
... Finally Done

*/

/*

Testcase 1:

6
3 
10 
5 
25 
2 
8

Ans : 28

*/

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


    string maxXor(string s1 ){
        
        string ans = "" ;
        Node *tmpRoot = root ;

        for(auto x : s1 ){
            char need = '1' ;
            if(x=='1') need = '0' ;
            
            if(tmpRoot->Data[need]!=nullptr){
                ans += need ;
                tmpRoot =  tmpRoot->Data[need] ;
            }
            else{
                ans+=x;
                tmpRoot =  tmpRoot->Data[x] ;
            }

        }

        return ans ;

    }

};

string intToBinary(int num){
   
    string s1 = "" ;
   
    while(num){
        if(num&1) s1+='1' ;
        else s1+='0' ;
        num>>=1 ;
    }

    while(s1.size()< 31) s1+='0' ;

    reverse(s1.begin() , s1.end()) ;
    return s1 ;
}

int binaryToInt(string s1){
    
    int ans = 0 ;

    for(auto x : s1 ){
        ans<<=1 ;
        int  lastbit = int(x=='1') ;
        ans = ans | lastbit ; 
    }

    return ans ;

}

int main(){

    int testcase , testcase1 , num ;
    cin>>testcase ;
    Trie t1 ;
    vector<int> v1 ;

    while(testcase--){
        
        cin>>num ;
        v1.push_back(num) ;
        
        string ans = intToBinary(num) ;
        int num1 = binaryToInt(ans) ;        
        // cout<<ans<<" , "<<num1<< endl ;
        t1.insert(ans) ;
    }
    
    cin>>testcase1 ;

    while(testcase1--){
        int finalAns = 0 ; 
        int x ; cin>>x;
        string op1 = intToBinary(x) ;
        string maybeAns = t1.maxXor(op1) ;
        int maybeAnsInt = binaryToInt(maybeAns) ;
        int currAns = 0 ;
        currAns = maybeAnsInt^x ; 
        cout<<currAns<<endl;

    }

/*
    for(auto x : v1 ){
        string op1 = intToBinary(x) ;
        string maybeAns = t1.maxXor(op1) ;
        int maybeAnsInt = binaryToInt(maybeAns) ;
        int currAns = 0 ;
        currAns = maybeAnsInt^x ; 
        if( currAns > finalAns){
            finalAns = currAns ;
        }
        // cout<<op1<<" Int: "<<x<<" best : "<< maybeAns <<" "<<maybeAnsInt<<" xor : "<<(x^maybeAnsInt)<<" finalAns : "<<finalAns<<endl; 
    }*/

    // cout<<finalAns<<endl;

}