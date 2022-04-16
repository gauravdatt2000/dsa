#include "bits/stdc++.h"
using namespace std;

// find the nearest 0  build  a matrix and return 

int main(void){
    
    int row , col ;
    cin>>row>>col ;

    vector <vector<int> > v1(row , vector<int>(col) ) ;
    vector<vector<int>> ans( row , vector<int>(col) ) ;
    
    for(auto &x : v1){
        for(auto &y :x){
            cin>>y ;
        }
    }



    
}