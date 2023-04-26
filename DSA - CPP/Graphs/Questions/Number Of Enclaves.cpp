#include "bits/stdc++.h"
using namespace std;

void mybfs(vector<vector<int>> &v1 , vector<pair<int , int >> &dir , int &row , int &col ,int x , int y  ){

    if(x>=0 and x<row and y>=0 and y<col and v1[x][y] ){

        v1[x][y] = 0 ;
        // cout<<x<<" "<<y<<endl;
       
        for(int j=0 ; j<3 ; j++){
            int X = x + dir[j].first ;
            int Y = y + dir[j].second ;
            mybfs(v1 , dir , row , col , X , Y) ;
        }

    }

}

int main(void){

    int row , col ;
    cin>>row>>col ;

    vector< vector <int > > v1(row , vector<int> (col ,0) ) ;
    vector<pair<int , int>> dir = { {1 , 0} , {-1 , 0} , {0 , 1} , { 0 , -1}  } ;

    for(auto &x: v1){
        for(auto &y : x){
            cin>>y;
        }
    }

// first row 
    for(int i=0 ; i<1 ; i++ ){
        for(int j=0 ; j<col  ; j++){
            int r = i , c = j ;
            // cout<<r<<" "<<c<<endl;
            mybfs(v1 , dir ,  row , col , r , c) ;
        }
    }

// first col 
    for(int i=0 ; i<1 ; i++ ){
        for(int j=0 ; j<row   ; j++){
            int r = j , c = i ;
            mybfs(v1 , dir ,  row , col , r , c) ;
        }
    }

// last row 
    for(int i=row-1 ; i<row  ; i++ ){
        for(int j=0 ; j<col  ; j++){
            int r = i , c = j ;
            mybfs(v1 , dir ,  row , col , r , c) ;
        }
    }

// last col 
    for(int i=col-1 ; i<col ; i++ ){
        for(int j=0 ; j<row   ; j++){
            int r = j , c = i ;
            mybfs(v1 , dir ,  row , col , r , c) ;
        }
    }



    
    int ans = 0 ;

    for(auto x: v1){
        for(auto y : x){
            // cout<<y<<" " ;
            ans+= y ;
        }
        // cout<<endl;
    }

    cout<<ans<<endl;
    
}