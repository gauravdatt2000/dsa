#include "bits/stdc++.h"
using namespace std;

bool is_operator(char k){
    return k=='+' or k=='-' or k=='*' or k=='/' or k=='(' or k==')'  ; 
}

int precedence(char k){

    if(k=='*' or k=='/' ) return 2 ;
    if(k=='+' or k=='-' ) return 1 ;
    return 0 ;

}



void postfix(string &s1){

    stack<char> op_stk ;
    stack< string > var_stk ;

    int i=0  , len = s1.size() ;

    while( i < len ){

        if( is_operator(s1[i]) ){

            if( s1[i]== '(' ){
                op_stk.push( s1[i]  ) ;
            }
            else if(s1[i]==')'){
               
                while(  op_stk.size()>0 and op_stk.top()!= '(' and var_stk.size()>=2 ){
                    string tmp = "" ;
                    string v2 = var_stk.top(); var_stk.pop() ;
                    string v1 = var_stk.top(); var_stk.pop() ;
                    tmp+=v1 ;
                    tmp+=v2;                 
                    tmp+=op_stk.top() ;
                    op_stk.pop();
                    var_stk.push(tmp);
                }

                if(op_stk.size()){
                    op_stk.pop() ;
                }


            }
            else{

                while( op_stk.size() > 0 and  precedence(op_stk.top()) >= precedence( s1[i] )  and var_stk.size()>=2 ){
                    string tmp = "" ;
                    string v2 = var_stk.top(); var_stk.pop() ;
                    string v1 = var_stk.top(); var_stk.pop() ;
                    tmp+=v1 ;
                    tmp+=v2;                 
                    tmp+=op_stk.top() ;
                    op_stk.pop();
                    var_stk.push(tmp);
                }

                op_stk.push( s1[i] );

            }


        }
        else{
            string tmp="";
            tmp += s1[i] ;
            var_stk.push( tmp  ) ;
        }

        i++;
    }

    while(!op_stk.empty() ){
        
        string tmp = "" ;
        string v2 = var_stk.top(); var_stk.pop() ;
        string v1 = var_stk.top(); var_stk.pop() ;
        tmp+=v1 ;
        tmp+=v2;                 
        tmp+=op_stk.top() ;
        op_stk.pop();
        var_stk.push(tmp);

    }

    cout<<var_stk.top()<<endl;



}

void prefix(string &s1){

    stack<char> op_stk ;
    stack< string > var_stk ;

    int i=0  , len = s1.size() ;

    while( i < len ){

        if( is_operator(s1[i]) ){

            if( s1[i]== '(' ){
                op_stk.push( s1[i]  ) ;
            }
            else if(s1[i]==')'){
               
                while(  op_stk.size()>0 and op_stk.top()!= '(' and var_stk.size()>=2 ){
                    string tmp = "" ;
                    string v2 = var_stk.top(); var_stk.pop() ;
                    string v1 = var_stk.top(); var_stk.pop() ;
                    tmp+=op_stk.top() ;
                    op_stk.pop();
                    tmp+=v1 ;
                    tmp+=v2;                 
                    var_stk.push(tmp);
                }

                if(op_stk.size()){
                    op_stk.pop() ;
                }


            }
            else{

                while( op_stk.size() > 0 and  precedence(op_stk.top()) >= precedence( s1[i] )  and var_stk.size()>=2 ){
                    string tmp = "" ;
                    string v2 = var_stk.top(); var_stk.pop() ;
                    string v1 = var_stk.top(); var_stk.pop() ;
                    tmp+=op_stk.top() ;
                    op_stk.pop();
                    tmp+=v1 ;
                    tmp+=v2;                 
                    var_stk.push(tmp);
                }

                op_stk.push( s1[i] );

            }


        }
        else{
            string tmp="";
            tmp += s1[i] ;
            var_stk.push( tmp  ) ;
        }

        i++;
    }

    while(!op_stk.empty() ){
        
        string tmp = "" ;
        string v2 = var_stk.top(); var_stk.pop() ;
        string v1 = var_stk.top(); var_stk.pop() ;
        tmp+=op_stk.top() ;
        op_stk.pop();
        tmp+=v1 ;
        tmp+=v2;                 
        var_stk.push(tmp);

    }

    cout<<var_stk.top()<<endl;



}


int main(void){
    
    string s1;
    cin>>s1;

    postfix(s1) ;
    prefix(s1) ;

}