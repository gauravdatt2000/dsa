#include "bits/stdc++.h"
using namespace std ;

class dual_stack{
    
    public :

    vector<int> v1 ;
    int top1_pt = -1 ;
    int  top2_pt = INT_MAX;

    
    dual_stack(int sz){
        vector<int> tmp(sz) ;
        v1= tmp ;
        top2_pt = sz ;
    }

    void push1(int data ){
       
        if( top1_pt +1 == top2_pt  ){
            cout<< "Stack overflow"<<endl;
            return ;
        }
        v1[++top1_pt] = data ; 
    }

    void push2(int data ){
       
        if( top1_pt == top2_pt -1  ){
            cout<< "Stack overflow"<<endl;
            return ;
        }
        v1[--top2_pt] = data ; 
    }

    int size1(){
        return top1_pt+1 ;
    }

    int size2(){
        return v1.size() - top2_pt ;
    }

    int pop1(){

        if(size1()==0){
            cout<<"Stack underflow"<<endl;
            return -1 ;
        }
        return v1[top1_pt--] ;

    }

    int pop2(){

        if(size2()==0){
            cout<<"Stack underflow"<<endl;
            return -1 ;
        }
        return v1[top2_pt++] ;

    }

    int top1(){

        if(size1()){
            return v1[top1_pt] ;
        }
        cout<<"Stack underflow"<<endl;
        return -1;

    }


    int top2(){
        
        if(size2()){
            return v1[top2_pt] ;
        }
        cout<<"Stack underflow"<<endl;
        return -1;

    }


};


int main(void){
    
    int n1 , tmp ;
    cin>>n1 ;

    dual_stack stk(n1);

    string s1;

    while(cin>>s1){

        if(s1 == "push1"){
            cin>>tmp;
            stk.push1(tmp) ;
            continue ;
        }

        if(s1 == "push2"){
            cin>>tmp;
            stk.push2(tmp) ;
            continue ;
        }

        if(s1 == "pop1"){

            tmp = stk.pop1() ;
            
            if(tmp!=-1){
                cout<<tmp<<endl;
            }

            continue ;
        }

        if(s1 == "pop2"){

            tmp = stk.pop2() ;
            
            if(tmp!=-1){
                cout<<tmp<<endl;
            }
            
            continue ;
        }

        if(s1 == "top1"){

            tmp = stk.top1() ;
            
            if(tmp!=-1){
                cout<<tmp<<endl;
            }
            
            continue ;
        }

        if(s1 == "top2"){

            tmp = stk.top2() ;
            
            if(tmp!=-1){
                cout<<tmp<<endl;
            }
            
            continue ;
        }

        if(s1=="size1"){
            cout<<stk.size1()<<endl;
            continue ;
        }


        if(s1=="size2"){
            cout<<stk.size2()<<endl;
            continue ;
        }

        break ;
    }




}