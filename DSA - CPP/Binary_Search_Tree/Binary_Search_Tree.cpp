#include "bits/stdc++.h"
using namespace std ;

class Binary_Search_Tree{
    
    public :
    
    int val ;
    Binary_Search_Tree *left  , *right ;

    Binary_Search_Tree(){
        val = 0 ;
        left = nullptr ;
        right = nullptr ;
    }

    static Binary_Search_Tree* Build(vector<int>&v1){

        Binary_Search_Tree *root = nullptr ;
        stack< pair< Binary_Search_Tree* , int  > > stk ;

        int len = v1.size() ;
        int i=0;

        while(i<len){
            
            if( i==0 and v1[i]!=-1){
                root = new Binary_Search_Tree() ;
                root->val = v1[i] ;
                stk.push({root , 0}) ;
                i++;
                continue ;
            }

            if( stk.size() > 0 and   stk.top().second==2 ){
                stk.pop() ;
                continue ;
            }

            if( stk.size() > 0 and stk.top().second==0 ){

                if( v1[i]!=-1 ){
                    Binary_Search_Tree *tmp = new Binary_Search_Tree() ;
                    stk.top().second++;
                    stk.top().first->left = tmp ;
                    tmp->val = v1[i] ;
                    stk.push({ tmp , 0 }) ;
                }
                else{
                    stk.top().second++;
                }
                
                i++;
                continue ;
            }

            if( stk.size() > 0 and stk.top().second==1 ){

                if( v1[i]!=-1 ){
                    Binary_Search_Tree *tmp = new Binary_Search_Tree() ;
                    stk.top().second++;
                    stk.top().first->right = tmp ;
                    tmp->val = v1[i] ;
                    stk.push({ tmp , 0 }) ;
                }
                else{
                    stk.top().second++;
                }
                
                i++;
                continue ;
            }

        }


        return root ;

    }

    static int size( Binary_Search_Tree *node ){
        if( node == nullptr) return 0 ;
        int ans = 1;
        ans += size(node->left) + size(node->right) ;
        return ans ;
    }

    static int sum( Binary_Search_Tree *node ){
        
        int ans =0 ;
        if(node!=nullptr) ans+= node->val + sum(node->left) +sum(node->right) ;
        return ans ;
    }

    static int min(Binary_Search_Tree *node){
        int ans = INT_MAX ;
        if(node==nullptr) return ans ;
        ans = std::min( { ans , min(node->left) , node->val } ) ;
        return ans ;
    }

    static int max(Binary_Search_Tree *node){
        int ans = INT_MIN ;
        if(node==nullptr) return ans ;
        ans = std::max( { ans , max(node->right) , node->val } ) ;
        return ans ;
    }

    static bool find(Binary_Search_Tree *root , int v1 ){
        
        bool ans= false;
        if(root==nullptr) return ans ;

        if(root!=nullptr){
            
            if(root->val ==v1)  return true ;

            if( v1  < root->val ){
                ans = ans or find(root->left , v1) ; 
            }
            else{
                ans = ans or find(root->right , v1);
            }
        }


        return ans ;

    }

    static void insert(Binary_Search_Tree *&root , int v1 ){


        if(root == nullptr ){
            root = new Binary_Search_Tree() ;
            root->val = v1;
            return  ;
        }

        if(v1== root->val) return ;

        if( v1  <  root->val ){
            insert(root->left , v1) ;
        }
        else{
            insert(root->right , v1 );
        }

    }

    static void preorder_print(Binary_Search_Tree *root ){
        if(root!=nullptr){
            cout<<root->val<<" ";
            preorder_print(root->left) ;
            preorder_print(root->right) ;
        }
    }

    static void postorder_print(Binary_Search_Tree *root ){
        if(root!=nullptr){
            postorder_print(root->left) ;
            postorder_print(root->right) ;
            cout<<root->val<<" ";
        }
    }

    static void inorder_print(Binary_Search_Tree *root ){
        if(root!=nullptr){
            inorder_print(root->left) ;
            cout<<root->val<<" ";
            inorder_print(root->right) ;
        }
    }

    static void level_order_print(Binary_Search_Tree *root ){
        queue<Binary_Search_Tree*> qu ;

        if(root!=nullptr) qu.push(root) ;
        int count =0 ;

        while(!qu.empty()){
            
            count = qu.size() ;

            for(int i=0 ; i<count ; i++ ){
                cout<<qu.front()->val<<" ";

                if(qu.front()->left!=nullptr ){
                    qu.push( qu.front()->left ) ;
                }

                if(qu.front()->right!=nullptr ){
                    qu.push( qu.front()->right ) ;
                }

                qu.pop();

            }

            cout<<endl;
        }


    }

    static Binary_Search_Tree* delete_node(Binary_Search_Tree *node ,  int num ){
        
        if( node == nullptr) return nullptr ;

        if(  num ==  node->val ){

            // 2 child 
            if(node->left!=nullptr and node->right!=nullptr){

                if(node->left!=nullptr){
                    // find the left max 
                    int max_val  = Binary_Search_Tree::max(node->left) ; 
                    node->val = max_val;
                    node->left = delete_node(node->left , max_val ) ;

                }
                else{
                    // dinf right min 
                    int max_val  = Binary_Search_Tree::min(node->right) ; 
                    node->val = max_val;
                    node->right = delete_node(node->right , max_val ) ;

                }

                return node ;

            }
            // 1 child
            if(node->left!=nullptr ){
                return node->left ;
            }
            if(node->right!=nullptr){
                return node->right ;
            }
            // 0 child 
            return  nullptr ;

        }

        else if(num < node->val ){
            node->left = delete_node(node->left  , num ) ;
        }
        else if(num > node->val  ){
            node->right = delete_node(node->right  , num ) ;
        }

        return node ;

    }

    static void Replace_with_sum_larger(Binary_Search_Tree *node , int &cal ){
        
        if(node==nullptr) return  ;
        Replace_with_sum_larger(node->right , cal ) ;
        cal+=node->val;
        node->val = cal -node->val ;
        Replace_with_sum_larger(node->left  , cal ) ;

    }

    static bool node_to_root_path(Binary_Search_Tree *root   , int node , vector<int> &ans  ){
       

        bool sol = false ;
        if(root == nullptr ) return sol;
    //    cout<<root->val<<endl;

        if( root->val == node  ){
            ans.push_back(node) ;
            return true ;
        }
        else if(node < root->val  ){
            sol = sol or node_to_root_path(root->left , node , ans ) ;
            if(sol){
                ans.push_back(root->val) ;
            } 
        }
        else if(node > root->val  ){
            sol = sol or node_to_root_path(root->right , node , ans ) ;
            if(sol){
                ans.push_back(root->val) ;
            } 
        }

        return sol ;


    }

    static int longest_common_ancestor(Binary_Search_Tree *root , int a1 , int a2){
        
        vector<int> v1 , v2 ;
        int ans = INT_MIN ;
        bool s1 = node_to_root_path(root , a1 , v1 ) ;
        bool s2 = node_to_root_path(root , a2 , v2 ) ; 
        
        if( s1 and s2 ){
            
            int len1 = v1.size() , len2 = v2.size()  , i=0  , j=0  ;
            i = len1-1 ;
            j = len2-1 ;

            while(i>=0 and j>=0 and v1[i]==v2[j] ){
                i--;
                j--;
            }

            i++ ;
            j++;

            return v1[i] ;
        }
        cout<<"NO LCA Found "<<endl;
        return ans ;

    }

    static void print_in_range(Binary_Search_Tree *root , int &a1 , int &a2){

        if(root){
            print_in_range(root->left , a1 , a2) ;
            if( a1 <= root->val  and root->val <=a2){
                cout<<root->val<<endl;
            }
            print_in_range(root->right , a1 , a2) ;
        }

    }

    static void Target_sum(Binary_Search_Tree*&root , Binary_Search_Tree*node , int &Tar ){
        if(node){
            Target_sum(root , node->left , Tar ) ;
            
            int first_val = node->val ;
            int second_val = Tar - first_val ;
            bool status = false;
            status = find(root , second_val) ;

            if( first_val < second_val and status){
                cout<<first_val<<" "<<second_val<<endl;
            }

            Target_sum(root , node->right , Tar ) ;
        }
    }

};

int str_to_int(string &s1){
    int ans = 0 ;
    for(auto x : s1){
        ans = ans*10 + int(x-'0') ;
    }  
    return ans ;
}

vector<int> parser_tree(int n){
    
    vector<int> ans ;

    for(int i=0 ; i<n ; i++){
        string s1;
        cin>>s1 ;
        if(s1=="n"){
            ans.push_back(-1) ;
            continue ;
        }
        ans.push_back(str_to_int(s1)) ;
    }

    return  ans ;

}

void print(vector<int>&v1){
    for(auto x : v1 ){
        cout<<x<<" ";
    }
    cout<<endl;
}

string java_boolean(bool b1){
    if(b1) return "true" ;
    return "false";
}

void display(Binary_Search_Tree* node) {
  if (node == nullptr) {
    return;
  }

  string str = "";
  str += node->left == nullptr ? "." : to_string(node->left->val) + "";
  str += " <- " + to_string(node->val) + " -> ";
  str += node->right == nullptr ? "." : to_string(node->right->val) + "";
  cout << str << endl;

  display(node->left);
  display(node->right);
}

int main(){
    
    int n , n1 , n2;
    cin>>n ;
    vector<int> inputs = parser_tree(n);
    // print(inputs) ;
    Binary_Search_Tree *root = nullptr ;
    root =  Binary_Search_Tree::Build(inputs) ;
    cin>>n1;
    // Binary_Search_Tree ::inorder_print(root) ;
    // cout<<Binary_Search_Tree::size(root)<<endl;
    // cout<<Binary_Search_Tree::sum(root)<<endl;
    // cout<<Binary_Search_Tree::max(root)<<endl;
    // cout<<Binary_Search_Tree::min(root)<<endl;
    // cout<< java_boolean( Binary_Search_Tree::find(root , n1) )<<endl;
    // root = Binary_Search_Tree::delete_node(root ,n1) ;
    // cin>>n2;
    // int sum =  Binary_Search_Tree::longest_common_ancestor(root, n1 , n2) ;
    // cout<<sum<<endl;
    // Binary_Search_Tree::print_in_range(root , n1 , n2) ;
    Binary_Search_Tree::Target_sum(root , root , n1) ;
}