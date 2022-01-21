#include"bits/stdc++.h"
using namespace std;

bool is_operator(string &s1){
    return (s1=="+" or s1=="-" or  s1=="*" or s1=="/" or s1=="(" or s1==")") ;
}

int precedence(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/')
	return 2;
	return 0;
}

int apply_op(int a, int b, char op){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}

    return 0 ;

}


int str_to_int(string &s1){
    
    int ans = 0 , len = s1.size() , i = 0  ;

    bool neg =  false;

    while( i < len ){
        
        if(i==0 and s1[i]=='-'){
            neg = true ;
            i++;
            continue ;
        } 

        ans = ans*10 + int( s1[i]-'0' ) ;
        i++;
    }
    
    if(neg) ans*=-1;

    return ans ;

}

int eval( string &s1 ){

    int len = s1.size() , i = 0 ;

    stack<int> stk_val ;
    stack<char> stk_op ;

    while(i<len){

        string token = "" ;

        while(s1[i]==' '){
            i++;
        }

        while( i<len and s1[i]!=' '){
            token+=s1[i] ;
            i++;
        }
        i++ ;

        if(is_operator(token)){

            
            if(token=="("){
                stk_op.push(token[0]) ;
            }
            else if(token==")"){



                while(  stk_op.size()>0 and stk_op.top()!= '(' and stk_val.size()>=2 ){
                    int val2 = stk_val.top() ; stk_val.pop() ;
                    int val1 = stk_val.top() ; stk_val.pop() ;
                    int ans = 0 ;
                    char op = stk_op.top() ; stk_op.pop() ;
                    ans = apply_op(val1 , val2 , op ) ;
                    stk_val.push(ans) ;
                }

                if(stk_op.size()){
                    stk_op.pop() ;
                }

            }
            else{

                while(  !stk_op.empty() and precedence( stk_op.top() ) >= precedence(token[0]) and stk_val.size()>=2 ){

                    int val2 = stk_val.top() ; stk_val.pop() ;
                    int val1 = stk_val.top() ; stk_val.pop() ;
                    int ans = 0 ;
                    char op = stk_op.top() ; stk_op.pop() ;
                    ans = apply_op(val1 , val2 , op ) ;
                    // debug
                    // cout<<op<< " "<<" val1 = "<<val1<<" val2 = "<<val2<<" "<<ans<<" ** \n";
                    stk_val.push(ans) ;
                
                }

                stk_op.push(token[0]) ;

            }

        }
        else{
            // cout<<str_to_int(token)<<endl;
            stk_val.push( str_to_int(token) ) ;
        }

    }

    while(!stk_op.empty() ){
         int val2 = stk_val.top() ; stk_val.pop() ;
        int val1 = stk_val.top() ; stk_val.pop() ;
        int ans = 0 ;
        char op = stk_op.top() ; stk_op.pop() ;
        ans = apply_op(val1 , val2 , op ) ;
        stk_val.push(ans) ;
    }


    return stk_val.top() ;
}

// testcase 1 
// 3 / ( 6 * 8 - 4 ) + 9
// ans = 9
 
int main(void){

    string s1 , s2 = "";
    getline(cin , s1) ;

    //  added extra space just to pass testcase ;
    // since then number is form (0 to 9) thats why 

    for(auto x : s1 ){
        if(x!=' '){
            s2+=x;
            s2+=' ';
            continue ;
        }
        s2+=x;
    }

    // cout<<s2<<endl;

    int ans = eval(s2) ; 
    cout<<ans<<endl;

}