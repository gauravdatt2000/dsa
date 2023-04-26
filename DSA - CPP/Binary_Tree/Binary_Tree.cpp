// author gauravdatt2000

#include "bits/stdc++.h"
using namespace  std ;

class Tri_Data{
    public : 
    bool sol = true ;
    int MAX = INT_MIN ;
    int MIN = INT_MAX ;

};

class Tri_Data_mod{
    public : 
    bool sol = true ;
    int MAX = INT_MIN ;
    int MIN = INT_MAX ;
    int size = 0 ;
    int root_tmp = INT_MIN ;
};

class Binary_Tree{
    
    public :

    int val ;
    Binary_Tree *left , *right;  

    Binary_Tree(){
        val = 0 ;
        left =  nullptr ; 
        right = nullptr; 
    }

    static void  Build_Binay_Tree ( Binary_Tree *&root , vector<int>&inputs ){

        stack< pair < Binary_Tree* , int > > stk;
        int i = 0 , len = inputs.size() ;

        if( i < len ){
            root->val = inputs[i++] ; 
            stk.push({ root , 0 }) ;
        }

        while( !stk.empty() and i < len  ){

            // cout<<stk.top().first->val<<" "<<stk.top().second<<endl;

            if(stk.top().second==2){
                stk.pop() ;
                continue ;
            }

            if( stk.top().second == 0  ){

                if( inputs[i]!=-1 ){
                    
                    Binary_Tree *b1 = new Binary_Tree(); 
                    b1->val = inputs[i++];
                    stk.top().first->left = b1 ;
                    stk.top().second++;
                    stk.push( { b1 , 0 } ) ;

                }
                else{

                    stk.top().second++;
                    i++;

                }

                continue ;

            }


            if( stk.top().second == 1  ){

                if( inputs[i]!=-1 ){
                    
                    Binary_Tree *b1 = new Binary_Tree(); 
                    b1->val = inputs[i++];
                    stk.top().first->right = b1 ;
                    stk.top().second++;
                    stk.push( { b1 , 0 } ) ;

                }
                else{

                    stk.top().second++;
                    i++;

                }

                continue ;

            }



        }


    }

    static int size( Binary_Tree *node ){

        if( node == nullptr) return 0 ;
        int ans = 1;
        ans += size(node->left) + size(node->right) ;
        return ans ;
    }

    static int max(Binary_Tree *node ){
        
        int ans = INT_MIN ;

        if(node!=nullptr){
            ans= std::max( { ans , node->val , max(node->left)  , max(node->right) } ) ;
        }

        return ans ;

    }

    static int sum( Binary_Tree *node ){
        
        int ans =0 ;
        if(node!=nullptr) ans+= node->val + sum(node->left) +sum(node->right) ;
        return ans ;
    }

    static int height(Binary_Tree *node){  
        int ans = -1 ;
        if(node==nullptr) return ans ;
        ans = std::max( { height(node->left) , height(node->right) } ) ;
        return ans + 1 ; 
    }

    static bool find(Binary_Tree *root  , int data ){
        
        bool ans = false ;
        if(root==nullptr) return ans;
        
        if(root->val == data ) return true ;

        if(!ans){
            ans = ans or find(root->left , data) ;
        }

        if(!ans){
            ans = ans or find(root->right , data) ;
        }

        return ans ; 

    }

    static bool node_to_root_path (Binary_Tree *root  , int data  , vector<int> &v1){
        
        bool ans = false ;

        if(root==nullptr) return ans;
        
        if(root->val == data ) ans = true ;

        if(!ans){
            ans = ans or node_to_root_path(root->left , data , v1) ;
        }

        if(!ans){
            ans = ans or node_to_root_path(root->right , data , v1 ) ;
        }

        if(ans){
            v1.push_back(root->val) ;
        }

        return ans ; 

    }

    static void preorder_print(Binary_Tree *root ){
        if(root!=nullptr){
            cout<<root->val<<" ";
            preorder_print(root->left) ;
            preorder_print(root->right) ;
        }
    }

    static void postorder_print(Binary_Tree *root ){
        if(root!=nullptr){
            postorder_print(root->left) ;
            postorder_print(root->right) ;
            cout<<root->val<<" ";
        }
    }

    static void inorder_print(Binary_Tree *root ){
        if(root!=nullptr){
            inorder_print(root->left) ;
            cout<<root->val<<" ";
            inorder_print(root->right) ;
        }
    }

    static void level_order_print(Binary_Tree *root ){
        queue<Binary_Tree*> qu ;

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

    static void print_k_level_down( Binary_Tree *root , int k  ){

        if(root!=nullptr){
            if(k==0){
                cout<<root->val<<endl;
            }
            print_k_level_down(root->left , k-1) ;
            print_k_level_down(root->right , k-1) ;
        }

    }

    static bool is_leaf(Binary_Tree *root ){
        return root!=nullptr and root->left == nullptr and root->right== nullptr ;
    }

    static void remove_leaf(Binary_Tree *root){
        
        if(root!=nullptr){
            

            if( is_leaf(root->left) ){
                root->left = nullptr ; 
            }

            if( is_leaf(root->right) ){
                root->right = nullptr ; 
            }

            remove_leaf(root->left) ;
            remove_leaf(root->right) ;

        }

    }

    static Tri_Data is_bst__(Binary_Tree* root){
        
        if( root == nullptr){
            Tri_Data tmp ;
            return tmp ;
        }

        Tri_Data lft = is_bst__(root->left) ;
        Tri_Data rgt = is_bst__(root->right) ;

        Tri_Data current ;
        current.sol = ( lft.sol and rgt.sol and root->val > lft.MAX and rgt.MIN > root->val   ) ;
        current.MAX = std::max({ root->val , current.MAX , rgt.MAX , lft.MAX  }) ;
        current.MIN = std::min({ root->val , current.MIN , rgt.MIN , lft.MIN  }) ;

        return current;

    }

    static bool is_bst(Binary_Tree *root ){

        Tri_Data ans = is_bst__(root) ;
        return ans.sol ;
    }

    static void print_single_child( Binary_Tree *root  ){

        if(root!=nullptr){

            if(root->left ==nullptr and root->right!=nullptr){
                cout<<root->right->val<<endl;
            }

            if(root->left != nullptr and root->right==nullptr){
                cout<<root->left->val<<endl;
            }
            
            print_single_child(root->left) ;
            print_single_child(root->right) ;

        }

    }

    static pair< bool , int  > is_balanced__(Binary_Tree *root ){

        if( root == nullptr ){
            return {true , 0 } ;
        }

        pair<bool , int > left_subtree = is_balanced__(root->left) ;
        pair<bool , int > right_subtree = is_balanced__(root->right) ;

        bool ans = false ;
        int max_node_ht = 0 ;

        if(left_subtree.first and right_subtree.first and abs(left_subtree.second - right_subtree.second) <= 1 ){
            ans = true ;
        }

        max_node_ht = std::max( left_subtree.second   , right_subtree.second  ) +1 ;
        
        return { ans , max_node_ht } ;
    }

    static bool is_balanced(Binary_Tree *root ){
        pair< bool , int > ans = is_balanced__(root) ;
        return ans.first ;
    }

    static bool node_to_root_path_mod (Binary_Tree *root  , int data  , vector<Binary_Tree*> &v1){
        
        bool ans = false ;

        if(root==nullptr) return ans;
        
        if(root->val == data ) ans = true ;

        if(!ans){
            ans = ans or node_to_root_path_mod(root->left , data , v1) ;
        }

        if(!ans){
            ans = ans or node_to_root_path_mod(root->right , data , v1 ) ;
        }

        if(ans){
            v1.push_back(root) ;
        }

        return ans ; 

    }

    static void print_k_level_down_mod( Binary_Tree *root , int k , Binary_Tree *blocker ){

        if(root==blocker) return ;

        if(root!=nullptr){
            if(k==0 ){
                cout<<root->val<<endl;
            }
            print_k_level_down_mod(root->left , k-1 , blocker) ;
            print_k_level_down_mod(root->right , k-1 , blocker) ;
        }

    }

    static void k_away(Binary_Tree *root , int num , int k ){
        vector<Binary_Tree*>  paths ;
        Binary_Tree::node_to_root_path_mod(root , num , paths) ;
        int len = paths.size() ;
        Binary_Tree *blocker = nullptr ;

        for(int i=0 ; i<len and k>=0 ; i++){
            print_k_level_down_mod(paths[i] , k-- , blocker) ;
            blocker = paths[i] ;
        }

    }

    static void Path_To_Leaf_From_Root_In_Range(Binary_Tree *root , string ans , int sum   , int low , int high ){

        if(root!=nullptr){
            
            ans+= to_string(root->val);
            sum+= root->val ;

            if( is_leaf(root) ){

                if( low <= sum and sum<=high ){
                    cout<<ans<<endl;
                }

                return ;

            }

            if(root->left!=nullptr){
                Path_To_Leaf_From_Root_In_Range(root->left , ans+" " , sum , low , high) ;
            }

            if(root->right!=nullptr){
                Path_To_Leaf_From_Root_In_Range(root->right , ans+" " , sum , low , high) ;
            }



        }

    } 

    static void transform_left_clone(Binary_Tree *&root ){

        if(root!=nullptr){
            
            Binary_Tree *cp = new Binary_Tree() , *tmp =nullptr;
            cp->val = root->val ;
            transform_left_clone(root->left) ;
            transform_left_clone(root->right) ;

            // if(root->left!=nullptr){
                tmp = root->left ;
                root->left = cp ;
                cp->left = tmp ; 
            // }


        }

    }    

    static void transformback_left_clone(Binary_Tree *&root ){

        if(root!=nullptr){
            root->left = root->left->left ;

            transformback_left_clone(root->left) ;
            transformback_left_clone(root->right) ;
        }

    }

    static Tri_Data_mod largest_bst_subtree__(Binary_Tree *root){
        
        if( root == nullptr){
            Tri_Data_mod tmp ;
            return tmp ;
        }

        Tri_Data_mod lft = largest_bst_subtree__(root->left) ;
        Tri_Data_mod rgt = largest_bst_subtree__(root->right) ;

        Tri_Data_mod current ;
        current.sol = ( lft.sol and rgt.sol and root->val > lft.MAX and rgt.MIN > root->val   ) ;
        current.MAX = std::max({ root->val , current.MAX , rgt.MAX , lft.MAX  }) ;
        current.MIN = std::min({ root->val , current.MIN , rgt.MIN , lft.MIN  }) ;

        if(current.sol){
            current.size = lft.size + rgt.size + 1 ;
            current.root_tmp = root->val ;
        }
        else if(lft.size > rgt.size ){
            current.size = lft.size ;
            current.root_tmp = lft.root_tmp ;
        }
        else{
            current.size = rgt.size ;
            current.root_tmp = rgt.root_tmp ;
        }

        return current; 
    }

    static pair<int , int > largest_bst_subtree(Binary_Tree *root){
        pair< int , int > ans ;
        Tri_Data_mod tmp = largest_bst_subtree__(root) ;
        ans.first = tmp.root_tmp ;
        ans.second = tmp.size ;

        return ans ;

    }

};


void display(Binary_Tree* node) {
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

int string_to_int(string &s1){
    
    int ans = 0 ;


    for(auto x : s1 ){
        ans = ans*10 + (x-'0') ;
    }

    return ans ;
} 

vector<int> input_parser_Binary_tree(int n1 ){
    
    vector<int> v1 ;
    string tmp ;

    for(int i=0 ; i<n1 ; i++ ){
        cin>>tmp ;
        
        if(tmp=="n"){
            v1.push_back(-1) ;
            continue ;
        }
        v1.push_back( string_to_int(tmp)  ) ;

    }

    return v1 ;

}

void print_java_style(vector<int> &v1){
    
    int len = v1.size() ;
    cout<<"[";
    for(int i =0 ; i<len ; i++ ){
        cout<<v1[i] ;
        if(i==len-1){
            continue ;
        }
        cout<<", ";
    }
    cout<<"]";

}

string  java_bool(bool val){
    if(!val) return "false" ;
    return "true";
}

int main(){

    // input phase 

    int input_sz , n11  , n2  , k , n3; 
    cin>> input_sz ;
    vector<int> inputs = input_parser_Binary_tree(input_sz) ;

    // input phase end 

    Binary_Tree *root = new Binary_Tree() ;

    Binary_Tree::Build_Binay_Tree(root , inputs ) ;

    // cout<<Binary_Tree::size(root)<<endl;
    // cout<<Binary_Tree::sum(root)<<endl;
    // cout<<Binary_Tree::max(root)<<endl;
    // cout<<Binary_Tree::height(root)<<endl;
    // cout<< java_bool( Binary_Tree::find(root , n11 ) ) <<endl;
    // vector<int> path ;
    // Binary_Tree::node_to_root_path( root , n11, path ) ;
    // print_java_style(path) ; 
    // Binary_Tree::level_order_print(root) ;
    // Binary_Tree::preorder_print(root) ;
    // cout<<endl;
    // Binary_Tree::inorder_print(root) ;
    // cout<<endl;
    // Binary_Tree::postorder_print(root) ;
    // cout<<endl;
    // cin>>n11 ;
    // Binary_Tree::print_k_level_down(root , n11) ;
    // Binary_Tree::remove_leaf(root) ;
    // display(root) ;
    // Binary_Tree::print_single_child(root) ;
    // cout<< java_bool( Binary_Tree::is_bst(root) ) ;
    // cout<< java_bool( Binary_Tree::is_balanced(root) ) <<endl;
    // Binary_Tree::k_away(root , n2 , k ) ;
    // cin>>n2>>n3 ;
    // Binary_Tree::Path_To_Leaf_From_Root_In_Range(root , "" , 0  , n2 , n3 ) ;
    // Binary_Tree::transformback_left_clone(root) ;
    // display(root) ;
    // pair<int , int > ans = Binary_Tree::largest_bst_subtree(root) ;
    // cout<<ans.first<<"@"<<ans.second<<endl;

}