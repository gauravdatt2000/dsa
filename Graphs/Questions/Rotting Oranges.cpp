#include "bits/stdc++.h"
using namespace std ;

// 0 represent empty space 
// 1 represent fresh orange 
// 2 reprent roten orange 

// In case if all the oranges can't become rotten print -1


int main(void){
    
    int row , col ;
    cin>>row>>col; 

    vector<vector<int>> g1 ;
    queue<pair<int , int >> gp;
    int fresh  = 0 ; 

    vector<pair<int , int >> dir_tldr ;
    dir_tldr.push_back({0 , 1 } ) ;
    dir_tldr.push_back({1 , 0 } ) ;
    dir_tldr.push_back({ 0 , -1 } ) ;
    dir_tldr.push_back({-1 , 0 } ) ;

    for(int i=0 ; i<row ; i++){
        vector<int> tmp1 ;
        for(int  j=0 , x ; j<col ; j++){
            cin>>x; 
            if( x==1 ) fresh++;
            else if(x==2) gp.push({i , j}) ;
            tmp1.push_back(x) ;
        }
        g1.push_back(tmp1) ;
    }

    int time  = 0 ;

    while(!gp.empty()){

        bool lvl = false;
        queue<pair<int , int >> helper ;

        while (!gp.empty())
        {
            pair<int , int > cord = gp.front() ;
            gp.pop() ;

            if(g1[cord.first][cord.second]==1 or g1[cord.first][cord.second]==2 ){

                int x = cord.first ;
                int y = cord.second ;

                // cout<<x<<" "<<y<<endl;

                for(int i=0 ; i<4 ; i++ ){

                    int del_X = dir_tldr[i].first ;
                    int del_Y = dir_tldr[i].second  ;

                    int newx = x + del_X ;
                    int newy = y + del_Y ;

                    if( newx>=0 and newx < row and newy>=0 and newy<col and g1[newx][newy]==1 ){
                        helper.push({newx , newy}) ;
                        lvl = true ;
                    }

                }

                g1[cord.first][cord.second] = 0;
            }

        }
        // cout<<helper.size()<<endl;
        gp = helper ;
        if(lvl){
            time++;
        }
    }

// check condition 
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if( g1[i][j] == 1 ){
                cout<<-1<<endl;
                return 0 ;
            }
        }
    }

    cout<<time<<endl;

}