#include "bits/stdc++.h"
using namespace std ;

// we need to find the mst (Minimum Spanning Tree) 
// here i have used prims algo instead of kruskals algo


// To Do
// make a generic graph 
// inside that implement prims , and kruskals 
//  prims and kruskals should return a new Graph *** IMP 

// here I have implemented directly 


int prims(vector<vector< pair<int , int > >> &myGraph , int  numberOfNode , int numberOfEdges){
    
    int minCost = 0 ;

    // minimum heap or min. priority queue 
    vector<bool> isVisited(numberOfNode+2 , false) ;
    
    // i have used min.priority queue 
    // priority_queue<int, vector<int>, greater<int> > gquiz;
    // since i dont wanted to write comparator on my own i have tweek the graph pair<> , 
    // since the sorting is on the basis of first value of the pairs

    priority_queue< pair<int , int >, vector< pair<int , int >>, greater< pair<int , int >> > pq;

    // since prims algo give the same ans , irrespectable form where we start 
    // we shart form the node 0 
    pq.push({0 , 0 }) ;

     while (pq.size() > 0) {
            
            //remove
            pair<int , int > rem = pq.top();
            pq.pop() ;

            //mark*
            if (isVisited[rem.second] == true) {
                continue;
            }
            isVisited[rem.second] = true;

            //work
            minCost += rem.first ;

            //add unvisited nbr
            for (auto edge: myGraph[rem.second]) {
                int nbr = edge.second;
                int wt = edge.first;

                if (isVisited[nbr] == false) {
                    pq.push( { wt , nbr });
                }
            }
        }



    return minCost ;

}


int main(void){
    
    int N_node , edges ;
    
    cin>>N_node>>edges ;

    vector<vector< pair<int , int > >> my_graph(N_node+2) ; 

    for(int i=0 ; i<edges ; i++ ){
        int n1 , n2 , wt ;
        cin>>n1>>n2>>wt ;
        my_graph[n1].push_back({wt , n2}) ;
        my_graph[n2].push_back({wt , n1}) ;
    }

    int mst_cost = prims(my_graph , N_node , edges ) ;
    cout<<mst_cost<<endl;

}