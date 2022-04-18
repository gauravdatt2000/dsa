// question : https://leetcode.com/problems/word-search-ii/


/*

edge case : TLE 

12
12
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaa
10
a
aa
aaa
aaaa
aaaaa
aaaaaa
aaaaaaa
aaaaaaaa
aaaaaaaaa
aaaaaaaaaa


*/

#include"bits/stdc++.h"
using namespace std ;

class  Node {
    public :
    map<char , Node* > Data ; 
    bool IsEnd = false ;
};

set<string> finalAns ;
vector<pair<int , int>> dir{{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1} } ;

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

    Node* getRoot(){
        return root ;
    }

};

void dfs(Node *tmp , vector<string> &vs , int x , int y , int &row , int &col , string ss , map<pair<int , int> , bool > isVisited ){

    if(x>=0 and x<row and y>=0 and y<col and !isVisited[{x , y}] and tmp!=nullptr and tmp->Data.find(vs[x][y] )!=tmp->Data.end() ){
        isVisited[{x , y}] = true ;
        ss+= vs[x][y] ;
        
        if(tmp->Data[vs[x][y]]->IsEnd){
            finalAns.insert( ss );
        }
        
        tmp =  tmp->Data[vs[x][y]] ;

        for(int i=0 ; i<4; i++){
            dfs(tmp , vs , x+dir[i].first , y+dir[i].second , row , col , ss , isVisited) ;
        }

    }

}


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

            map<pair<int , int> , bool > isVisited ;
            Node *tmp_root = t1.getRoot() ;
            dfs( tmp_root , vs , i , j , n , m , "" , isVisited ) ;

        }

    }

    int len = finalAns.size() ;
    auto p1 = finalAns.begin() ;
    cout<<"[";
    for(int i=0 ; i<len ; i++ ){
        cout<< *p1;
        if(i==len-1) continue ;
        cout<<", ";
        p1++;
    }
    cout<<"]";

}