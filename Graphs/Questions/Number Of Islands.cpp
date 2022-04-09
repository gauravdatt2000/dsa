#include "bits/stdc++.h"
using namespace std ;

// considering 0 as island , 1 as water 


void dfs_recursion ( int x , int y ,  int& row , int& col, vector<vector<int> > &g1 , vector<pair<int , int >> &dir ){

    if( x>=0  and x<row and y>=0  and y<col  and g1[x][y]==0 ){
        // cout<<x<<" ** "<<y<<endl;
        g1[x][y] = 1 ; 

        for(auto pr : dir ){
           int X = pr.first + x ;
           int  Y = pr.second + y ;
            dfs_recursion(X , Y , row , col , g1 , dir )   ;
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


    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            // cout<<g1[i][j]<<" ";
            if(g1[i][j] == 0 ){
                // cout<<i<<" "<<j<<endl;
                islandCount++;
                dfs_recursion(i , j , row , col , g1 , dir_tldr ) ;
            }
        }
        // cout<<endl;
    }

    

    cout<<islandCount<<endl;
    

}