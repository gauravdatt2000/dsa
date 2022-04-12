#include "bits/stdc++.h"
using namespace std ;

// considering 1 as island , 0 as water 


void dfs_recursion ( int x , int y ,  int& row , int& col, vector<vector<int> > &g1 , vector<pair<int , int >> &dir , string &ans ){

    if( x>=0  and x<row and y>=0  and y<col  and g1[x][y]==1 ){
        // cout<<x<<" ** "<<y<<endl;
        g1[x][y] = 0 ; 
        ans+='*' ;
        for(int i=0 ; i<4 ; i++ ){
           int X = dir[i].first + x ;
           int  Y = dir[i].second + y ;
           if(i==0){
               ans+='R' ;
           }
           else if (i==1){
               ans+='T' ;
           }
           else if (i==2){
               ans+='D' ;
           }
           else if (i==3){
               ans+='L' ;
           }
            dfs_recursion(X , Y , row , col , g1 , dir , ans )   ;
            ans+='b' ;
        }

    }

}

int main(void){
    
    int row , col ;
    cin>>row>>col ;

    vector<vector<int>> g1;
    

    for(int i=0 ; i<row ; i++){
        vector<int> tmp ;
        for(int j=0 , x ; j<col ; j++){
            cin>> x;
            tmp.push_back(x) ;
        }
        g1.push_back(tmp) ;
    }

    int islandCount = 0 ;

    vector<pair<int , int >> dir_tldr ;
    dir_tldr.push_back({0 , 1 } ) ;
    dir_tldr.push_back({1 , 0 } ) ;
    dir_tldr.push_back({ 0 , -1 } ) ;
    dir_tldr.push_back({-1 , 0 } ) ;

    set<string> distinctIsland ;

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            // cout<<g1[i][j]<<" ";
            if(g1[i][j] == 1 ){
                // cout<<i<<" "<<j<<endl;
                islandCount++;
                string tmp_ans = "" ;
                dfs_recursion(i , j , row , col , g1 , dir_tldr , tmp_ans ) ;
                distinctIsland.insert(tmp_ans) ;
            }
        }
        // cout<<endl;
    }

    

    cout<<distinctIsland.size()<<endl;
    

}