#include "bits/stdc++.h"
using namespace std ;

// NOTE : java style queue 

// queue to stack push-(add) efficient

class virtual_queue{
    
    public:
    stack<int> mn , hlp ;
    virtual_queue(){}

    // functions 

    int size(){
        return mn.size() ;
    }

    void add(int data ){
        mn.push(data) ;
    }

    int peek(){


        while(!mn.empty()){
            hlp.push(mn.top()); 
            mn.pop() ;
        }

        if(!hlp.empty()){
            
            int ans = hlp.top() ;

            while(!hlp.empty()){
                mn.push(hlp.top()); 
                hlp.pop() ;
            }

            return ans ;

        }

        cout<< "Queue underflow"<<endl;
        return -1;

    }


    int remove(){
        
        while(!mn.empty()){
            hlp.push(mn.top()); 
            mn.pop() ;
        }

        if(!hlp.empty()){
            
            int ans = hlp.top() ;
            hlp.pop() ;

            while(!hlp.empty()){
                mn.push(hlp.top()); 
                hlp.pop() ;
            }

            return ans ;

        }
        cout<< "Queue underflow"<<endl;
        return -1;

    }


};



// queue to stack pop-(remove) efficient

class virtual_queue1{
    
    public:
    stack<int> mn , hlp ;
    virtual_queue1(){}

    // functions 

    int size(){
        return mn.size() ;
    }

    void add(int data ){

        while(!mn.empty()){
            hlp.push(mn.top()) ;
            mn.pop() ;
        }

        mn.push(data) ;

        while(!hlp.empty()){
            mn.push(hlp.top()) ;
            hlp.pop() ;
        }


    }

    int peek(){

        if(!mn.empty()){
            return mn.top() ;
        }

        cout<< "Queue underflow"<<endl;
        return -1;

    }


    int remove(){
        
        if(!mn.empty()){
            int data = mn.top() ;
            mn.pop() ;
            return data ;
        }

        cout<< "Queue underflow"<<endl;
        return -1;


    }


};


int main(void){
    
    string s1 ;
    int n1 ;

    virtual_queue1 qu ;

    while( cin>>s1 ){
        
        if(s1=="quit") return 0 ;

        else if(s1=="add"){
            cin>>n1 ;
            qu.add(n1) ;

        }
        else if(s1=="remove"){
            
            int val = qu.remove() ;

            if(val!=-1){
            cout<< val <<endl ;

            }  

        }
        else if(s1=="peek"){
            int val = qu.peek() ;

            if(val!=-1){
            cout<< val <<endl ;

            }  
        }
        else if(s1=="size"){
            cout<<qu.size()<<endl;
        }

    }


}