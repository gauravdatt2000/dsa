#include "bits/stdc++.h"
using namespace std;

vector<pair<int , int >> dir{ {1,0} , {0,1} , {-1,0} , {0,-1}  } ;


void dfs(int x , int y , int &row , int  &col , vector<vector<int>> &v1 ,  map<pair<int , int > , bool > &component1 ){
    pair<int , int > curr(x , y) ;
    if(x>=0 and x<row and y>=0 and y<col and component1.find({x , y}) == component1.end() and v1[x][y]==1  ){
        // cout<<curr.first<<" "<<curr.second<<endl;
        component1[curr] = 1 ;
        for(int i=0 ; i<4 ; i++){
            dfs(x + dir[i].first , y + dir[i].second , row , col , v1 , component1 ) ;
        }
    }
}

int main(void){
    
    int row , col ;
    cin>>row ;
    col = row ;

    vector < vector < int > > v1(row , vector<int>(col) ) ;
    
    queue< pair < pair<int , int > , int > > qu ;
    map<pair<int , int > , bool > visited ;
    map<pair<int , int > , bool > component1 ;
    pair<int , int > starter ;


    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            cin>>v1[i][j] ;
            if(v1[i][j]==1){ starter.first = i ; starter.second = j ; }
        }
    }

    

    // put one component in map ;
    // cout<<starter.first<<" "<<starter.second<<endl;;
    int ans = -1 ;
    // if(starter.first!=INT_MAX){
        dfs(starter.first , starter.second , row , col , v1 , component1 ) ;
    // }

    // saved the component1
    visited = component1 ;

    pair<pair<int , int> , int> pp ;

    for(auto x1 : component1 ){
        // cout<<x1.first.first <<" "<<x1.first.second<<endl;
        pp.first = { x1.first.first , x1.first.second } ;
        qu.push(pp) ;
    }

    // applying bfs 

    while(!qu.empty()){
        
        pair<pair<int , int> , int > curr = qu.front() ;
        qu.pop() ;
        pair<int , int > cord = curr.first ;
        int lvl = curr.second ;

        // cout<<cord.first<<" "<<cord.second<<endl;

        if( v1[cord.first][cord.second]==1 and  component1.find(cord) == component1.end()  ){
            cout<<lvl-1<<endl;
            return 0 ;
        }

        for(int i=0  ; i<4 ; i++){

            int X = dir[i].first + cord.first;
            int Y = dir[i].second + cord.second ;
            pair<int , int > p1 = {X, Y} ;
                // cout<<X<<" "<<Y<<endl;

            if( X>=0 and X<row and Y>=0 and Y<col and visited.find(p1) == visited.end() ){
                visited[p1] = 1  ;
                qu.push({p1 , lvl+1}) ;
            }

        }

    }


    // cout<<ans<<endl;

    
}