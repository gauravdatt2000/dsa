#include "bits/stdc++.h"
using namespace std ;

class max_heap{
    
    public :

    vector<int> data ;
    int size = 0 ;

    max_heap(){
        data.push_back(INT_MAX) ;
    }

    void check_up(int index){
        if( index > 0 and data[index/2] < data[index] ){
            swap(data[index] , data[index/2] ) ;
            check_up(index/2) ;
        }
    }

    void add(int d1){
        data.push_back(d1) ;
        size++;
        check_up(size) ;
    }

    int peek(){
        
        if(size==0){
            cout<<"Underflow"<<endl; 
            return -1;
        }
        return data[1] ; 

    }

    int size1(){
        return size ;
    }

    void check_down(int index){
       
       if(index<= size){

            int swap_index = index ;
            int right =  2*index +1 ;
            int left =  2*index  ;
            int current_val = data[index] ;

            if(right <= size and data[right] >= current_val ){
                swap_index = right ;
                current_val = data[right] ;
            }

            if(left <= size and data[left] >= current_val ){
                swap_index = left ;
                current_val = data[left] ;
            }   

            if(index!=swap_index){
                swap(data[index] , data[swap_index]) ;
                check_down(swap_index) ;
            }

       }



    }

    int remove(){
       
        if( size==0 ){
            cout<<"Underflow"<<endl; 
            return -1;
        }
        int tmp = data[1] ;
        swap(data[1] , data[size] ) ;
        data.erase(data.end()-1) ;
        size--;

        if(size){
            check_down(1) ;
        }

        return tmp ;

    }

};


int main(void){
    
    string s1 ;
    int tmp;

    max_heap m1 ;

    while(cin>>s1){
        
        if(s1=="add"){
            cin>>tmp;
            m1.add(tmp) ;
            continue ;
        }

        if(s1=="remove"){
            tmp = m1.remove() ;
            if(tmp!=-1){
                cout<<tmp<<endl;
            }
            continue ;
        }

        if(s1=="peek"){
            tmp = m1.peek() ;
            if(tmp!=-1){
                cout<<tmp<<endl;
            }
            continue ;
        }

        if(s1=="size"){
            tmp = m1.size1() ;
            cout<<tmp<<endl;
            continue ;
        }

        break ;

    }

}