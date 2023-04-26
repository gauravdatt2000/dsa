#include "bits/stdc++.h"
using namespace std ;

// queue to stack push efficient

class virtual_stack{
    
    public:
    queue<int> mn , hlp ;
    virtual_stack(){}

    // functions 

    int size(){
        return mn.size() ;
    }

    void push(int data ){
        mn.push(data) ;
    }

    int top(){

        int ans = INT_MIN  ;
        
        while( mn.size() > 0 ){
            int data = mn.front() ; mn.pop() ;
            hlp.push(data) ;
            ans = data ;
        }


        while( hlp.size() > 0 ){
            int data = hlp.front() ; hlp.pop() ;
            mn.push(data) ;
        }

        return ans ;

    }


    void pop(){

        
        while( mn.size() > 0 ){
            if(mn.size()==1){
                cout<<mn.front()<<endl;
                mn.pop();
                break ;
            }
            int data = mn.front() ; mn.pop() ;
            hlp.push(data) ;
        }


        while( hlp.size() > 0 ){
            int data = hlp.front() ; hlp.pop() ;
            mn.push(data) ;
        }


    }


};



// queue to stack pop efficient

class virtual_stack1{
    
    public:
    queue<int> mn , hlp ;
    virtual_stack1(){}

    // functions 

    int size(){
        return mn.size() ;
    }
    
    void push(int data ){

        while(mn.size()){
            int data = mn.front() ; mn.pop() ;
            hlp.push(data) ;
        }

        mn.push(data) ;

        while(hlp.size()){
            int data = hlp.front() ; hlp.pop() ;
            mn.push(data) ;
        }


    }

    int top(){
        if(size()){
            return mn.front() ;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
        return -1;

    }


    int pop(){

        if(size()){
            int data = mn.front();
            mn.pop();
            return data ;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
        return -1;


    }


};


int main(void){
    
    string s1 ;
    int n1 ;

    virtual_stack1 stk ;

    while( cin>>s1 ){
        
        if(s1=="quit") return 0 ;

        else if(s1=="push"){
            cin>>n1 ;
            stk.push(n1) ;

        }
        else if(s1=="pop"){
            cout<<stk.pop()<<endl ;
        }
        else if(s1=="top"){
            cout<<stk.top()<<endl;
        }
        else if(s1=="size"){
            cout<<stk.size()<<endl;
        }

    }


}