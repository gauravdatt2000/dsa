#include "bits/stdc++.h"
using namespace std;

int char_to_int (char k){
    return k-'0' ;
}

bool is_operator(char k){
    return k=='+' or k=='-' or k=='*' or k=='/' ;
}

int precedence(char k){
    
    if(k=='*' or k=='/')  return 2 ;
    if(k=='+' or k=='-')  return 1 ;
    return 0 ;

}

int apply_op(int v1 , int v2 , char k ){
    if(k=='*') return v1*v2 ;
    if(k=='/') return v1/v2 ;
    if(k=='+') return v1+v2 ;
    if(k=='-') return v1-v2 ;

    return  0 ;
}

void cal_val(string &s1){
    
    int ans = 0 , len = s1.size()  ;
    stack<int> val ;

    for(int i=len-1 ; i>=0  ; i-- ){
        char x = s1[i] ;

        if(is_operator(x)){
            int v1 =  val.top() ; val.pop() ;
            int v2 =  val.top() ; val.pop() ;
            val.push( apply_op(v1 , v2 , x )  ) ;
            continue ;
        }
        val.push(char_to_int(x)) ;
    }

    cout<<val.top()<<endl;

}

string open_close(string &s1 , string &s2 , char k){
    
    string ans = "(" ;
    
    ans+= s1;
    ans+= k ;
    ans+= s2;

    ans+=')';

    return ans ;

}

string fix(string &s1 , string &s2 , char k){
    
    string ans = "" ;
    
    ans+= s1;
    ans+= s2;
    ans+= k ;

    // ans+=')';

    return ans ;

}

void prefix_to_infix(string &s1){

    stack< string > stk ;
    int len=s1.size() ;

    for(int i= len-1 ; i>=0  ; i-- ){
        char x = s1[i] ;
        if( is_operator(x) ){
            
            string v1 = stk.top() ; stk.pop() ;
            string v2 = stk.top() ; stk.pop() ;
            string ans =   open_close(v1 , v2 , x) ;
            stk.push(ans) ;

        }
        else{
            string tmp = "" ;
            tmp+=x;
            stk.push(tmp) ;
        }

    }

    cout<<stk.top()<<endl;


}


void prefix_to_postfix(string &s1){

    stack< string > stk ;
    int len = s1.size()  ;


    for(int i=len-1 ; i>=0 ; i--){
        char x = s1[i] ;
        if( is_operator(x) ){
            
            string v1 = stk.top() ; stk.pop() ;
            string v2 = stk.top() ; stk.pop() ;
            string ans =   fix(v1 , v2 , x) ;
            stk.push(ans) ;

        }
        else{
            string tmp = "" ;
            tmp+=x;
            stk.push(tmp) ;
        }

    }

    cout<<stk.top()<<endl;


}


int main(void){
    
    string s1;
    getline(cin , s1) ;
    cal_val(s1); 
    prefix_to_infix(s1) ;
    prefix_to_postfix(s1) ;

}