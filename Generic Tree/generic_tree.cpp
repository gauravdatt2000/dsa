/**
 * @ Author: Gaurav Datt ( gauravdatt2000 )
 * @ Time: 2022-01-16 00:09:24
 * @ Motivation: BELIEVE IN THE PROCESS
 * @ Website: http://gauravdatt.in
 **/

#include "bits/stdc++.h"
using namespace std ;

class generic_tree {
    
    public :
    int val ;
    vector < generic_tree* > children ;
    
    static  generic_tree* build( vector<int> &v1 ) {
        
        generic_tree *root = nullptr ;
        stack< generic_tree* > stk ;

        for(auto x : v1 ){

            if(x!=-1){
                // push
                generic_tree *tmp = new generic_tree() ;
                tmp->val = x ;

                if(stk.size()==0){      
                    root = tmp ;
                    stk.push( tmp );
                }
                else{
                    stk.top()->children.push_back( tmp );
                    stk.push( tmp );
                }
            }
            else{
                // pop 
                if(stk.size()){
                    stk.pop();
                }
            }
        }

        return root ;
    } 

    static void  print( generic_tree *p1 ){

        if(p1!= nullptr){
            cout<<p1->val<<" ";
            for(auto x : p1->children ){
                print(x) ;
            }
        }

    }

    static int size( generic_tree *p1 ){
        
        int cur = 0 ;
        if(p1!=nullptr){
            cur++;
            
            for(auto x : p1->children ){
                cur+= size(x) ;
            }

        }

        return cur ;

    }

    static int max( generic_tree *p1 ){
        
        int cur = INT_MIN ;
        if(p1!=nullptr){
            cur = p1->val ;
            
            for(auto x : p1->children ){
                int v00 = max(x) ;
                if(v00 > cur) cur =  v00 ;
            }

        }

        return cur ;

    }

    static int height( generic_tree *p1 ){
        
        int cur = 0 , update = 0 ;

        if(p1!=nullptr){
            // cur = p1->val ;
            if(p1->children.size()) cur++ ;

            for(auto x : p1->children ){
                int tph = 0 ;
                tph = height(x) ;
                if( tph > update){
                    update = tph ;
                 }
            }

        }

        return cur +  update ;

    }

    static void pre_post( generic_tree *p1 ){

        if(p1!= nullptr){
            cout<<"Node Pre "<<p1->val<<endl;
            for(auto x : p1->children ){
                cout<<"Edge Pre "<<p1->val<<"--"<<x->val<<endl;
                pre_post(x) ;
                cout<<"Edge Post "<<p1->val<<"--"<<x->val<<endl;
            }
            cout<<"Node Post "<<p1->val<<endl;
        }

    }
    
    static void lvlorder( generic_tree *p1 ){

        queue< generic_tree* > qu ;

        if(p1!=nullptr) qu.push(p1) ;

        while( qu.size() >0 ){
            
            cout<<qu.front()->val<<" " ;

            for( auto x : qu.front()->children ){
                qu.push(x) ;
            }
            qu.pop();

        }
        cout<<"."<<endl;


    }

    static void lvlorder_nl( generic_tree *p1 ){

        queue< generic_tree* >  vqu ;

        if(p1!=nullptr) vqu.push(p1) ;

        while( vqu.size() >0 ){

            queue< generic_tree* > qu ;
            // put all child in  qu 

            while(vqu.size()){

                // print vqu all element  ;
    
                cout<<vqu.front()->val<<" " ;

                for( auto x : vqu.front()->children ){
                    qu.push(x) ;
                }

                vqu.pop() ;

            }
            cout<<endl;
            // empty vqu and copy all qu elemnt in vqu 
            
            vqu = qu ;    

        }


    }

    static void lvlorder_nl1( generic_tree *p1 ){
        
        queue< generic_tree* > qu ;
        if(p1!=nullptr) qu.push(p1) ;

        while(qu.size()){
            
            int count = qu.size();
            
            for(int i=0 ; i<count ; i++){
                
                cout<<qu.front()->val<<" ";


                for(auto x : qu.front()->children ){
                    qu.push(x) ;
                }

                qu.pop() ;
            }

            cout<<endl;

        }

    }

    static void lvlorder_nl_zigzag( generic_tree *p1 ){
        
        queue< generic_tree* > qu ;
        if(p1!=nullptr) qu.push(p1) ;
        int times =0 ;

        while(qu.size()){

            int count = qu.size();
            vector<int> tmp_data ;

            for(int i=0 ; i<count ; i++){
                
                tmp_data.push_back(qu.front()->val) ;

                for(auto x : qu.front()->children ){
                    qu.push(x) ;
                }

                qu.pop() ;
            }

            // printing 
            if(times%2==0){
                
                for(auto x : tmp_data ){
                    cout<<x<<" ";
                }

            }
            else{

                for(int i = tmp_data.size()-1 ;  i>=0 ; i-- ){
                    cout<<tmp_data[i]<<" ";
                }

            }

            cout<<endl;

            times++;

        }

    }

    static void mirror(generic_tree *p1){
        for(auto x : p1->children ){
            mirror(x) ;
        }
        reverse(p1->children.begin(), p1->children.end() ) ;
    }

    static bool is_leaf(generic_tree *node ){
        return node->children.size()==0 and node!=nullptr ;
    }

    static void del_leaf( generic_tree *node ){
        if(node){

            for (auto &child : node->children) {
                
                
                if(generic_tree::is_leaf(child)){
                    // delete it ;
                    child = nullptr;    
                }
                else{
                    del_leaf(child) ;
                }


            }

        }
    }

    static void display(generic_tree *node) {
        
        // if(node!=nullptr){

            string str = to_string(node->val) + " -> ";
            for (auto child : node->children) {
                str += to_string(child->val) + ", ";
            }
            str += ".";
            // System.out.println(str);
            cout<<str<<endl; ;

            for (auto child : node->children) {
            display(child);
            }
            
        // }
        

    }
    
    static void Linearize( generic_tree *node ){

        while(node->children.size() > 1 ){
           
            generic_tree *lst_child =  node->children[ node->children.size()-1 ] ;
            generic_tree *second_lst_child = node->children[ node->children.size()-2] ;
            second_lst_child->children.push_back(lst_child) ;
            node->children.erase( node->children.begin() +   node->children.size()-1  ) ;

        }
        
        for(auto x : node->children ){
            Linearize(x) ;
        }
       


    }

    static bool isLeaf(generic_tree *node ){
        return node!=nullptr and node->children.size()==0 ;
    }

    static void delete_leaf( generic_tree *node ){

        // vector<int> index_to_be_del ;
        // int len = node->children.size() ;

        for( int i=0  ; i < node->children.size()  ; i++ ){
            if( isLeaf( node->children[i] )  ){
                // index_to_be_del.push_back(i) ;
                node->children.erase(node->children.begin()+i) ;
                i--;
            }
        }

        for(auto x  : node->children ){
            delete_leaf(x) ;
        }

    }

    static  bool are_same( generic_tree *p1 , generic_tree *p2){
        

        if(p1!=nullptr and p2!=nullptr){
            
            bool ans = true  ;
            int len1 = p1->children.size() ;
            int len2 = p2->children.size() ;

            if(len1!=len2) return false ;


            for(int i=0 ; i<len1 and ans ; i++ ){
                ans = ans and are_same(p1->children[i] , p2->children[i] );
            }

            return ans ;

        }
        else if(p1==nullptr and p2==nullptr){
            return true ;
        }
        return false ;
    }

    static  bool are_mirror_same( generic_tree *p1 , generic_tree *p2){
        

        if(p1!=nullptr and p2!=nullptr){
            
            bool ans = true  ;
            int len1 = p1->children.size() ;
            int len2 = p2->children.size() ;

            if(len1!=len2) return false ;


            for(int i=0 ; i<len1 and ans ; i++ ){
                ans = ans and are_mirror_same(p1->children[i] , p2->children[len1-i-1] );
            }

            return ans ;

        }
        else if(p1==nullptr and p2==nullptr){
            return true ;
        }
        return false ;
    }

    static bool is_symmetric(generic_tree *node){
        return  are_mirror_same(node , node) ;
    }

    static vector<int> node_to_root( generic_tree *node  , int num ){
        
        if(node->val == num ){
            vector<int> v1 ;
            v1.push_back( node->val ) ;
            return v1 ;
        }

        for(generic_tree* x : node->children ){
            
            vector<int> tmp = node_to_root( x , num) ;
            if( tmp.size() > 0   ){
                tmp.push_back( node->val ) ;
                return tmp ;
            }
        }

        return vector<int>()  ;

    }

    int ceil( int val1  , int ceil_val = INT_MAX  ){

        if( val > val1) ceil_val = val ;

        for( auto x : children ){
            
            int ans  = x->ceil(val1) ;

            if( ans > val1  ){
                ceil_val = min(ceil_val , ans  ) ;
            }

        }

        return ceil_val ;

    }

    int floor( int val1  , int floor_val = INT_MIN  ){

        if( val < val1) floor_val = val ;
        
        for( auto x : children ){
            
            int ans  = x->floor(val1) ;

            if( ans < val1  ){
                floor_val = std::max(floor_val , ans  ) ;
            }

        }

        return floor_val ;

    }

    static int longest_common_ancestor(generic_tree *root , int A , int B ){
        
        vector<int> v1 = node_to_root(root, A) ;
        vector<int> v2 = node_to_root(root, B) ;

        int len1 = v1.size() , len2 = v2.size() ;
        int i = len1-1 , j = len2-1 ;  

        while(i >=0 and j>=0  and v1[i] == v2[j]){
            i--;
            j--;
        }
        i++; j++ ;
        
        if( i<len1 and i>= 0 and j<len2 and j>=0 and v1[i] == v2[j]){
            return v1[i] ;
        }
        cout<<"NO found LCA" ;
        return INT_MIN ;
    }

    static int distance_between_two_node(generic_tree *root , int A , int B  ){
        
        vector<int> v1 = node_to_root(root, A) ;
        vector<int> v2 = node_to_root(root, B) ;

        int len1 = v1.size() , len2 = v2.size() ;
        int i = len1-1 , j = len2-1 ;  

        while(i >=0 and j>=0  and v1[i] == v2[j]){
            i--;
            j--;
        }
        i++; j++ ;

        if( i<len1 and i>= 0 and j<len2 and j>=0 and v1[i] == v2[j]){
            return i+j ;
        }
        cout<<"NO found LCA" ;
        return INT_MAX ;
    }

    static int Kth_max(generic_tree *root , int k){

        int ans = INT_MAX ;

        for(int i=0 ; i< k ; i++){
            ans = root->floor(ans) ;
        }

        return ans ;

    }

    static void Predecessor_Successor(generic_tree *root , int &num , vector<int> &v1 , int &state){

        if(state==0 and root->val != num ){
            v1[0] =  root-> val ;
        }
        else if( state==0 and root->val == num ){
            v1[1] =  root->val ;
            state++; 
        }
        else if( state==1 ){
            v1[2] =  root->val ; 
            state++;
        }

        // cout<<v1[0]<<" "<<v1[1]<<" "<<v1[2]<<endl;
        for(auto x : root->children ){

            Predecessor_Successor(x , num , v1 , state) ;
        }

    }

    static int max_subtree(generic_tree *root  , pair<int , int > &p1 ){
        
        int ans = root->val ;

        for(auto x : root->children ){
            ans+= max_subtree(x , p1) ;
        }

        if(ans > p1.first ){
            p1.first = ans ;
            p1.second = root->val  ;
        }

        return ans ;

    }

    static void iterative_preorder( generic_tree *root ){
        
        stack< pair< generic_tree* , int  > > stk ;

        stk.push({ root , -1}) ;

        while(!stk.empty()){

            if( stk.top().second ==-1){
                // preorder 
                cout<<stk.top().first->val<<" ";
                stk.top().second++;
                continue ;
            }

            if(stk.top().second == stk.top().first->children.size() ){
                stk.pop() ;
                continue ;
            }


            stk.push({ stk.top().first->children[stk.top().second++ ] , -1 }) ;

        }
        cout<<endl;

    }

    static void iterative_postorder( generic_tree *root ){
        
        stack< pair< generic_tree* , int  > > stk ;

        stk.push({ root , -1}) ;

        while(!stk.empty()){

            if( stk.top().second ==-1){
                stk.top().second++;
                continue ;
            }

            if(stk.top().second == stk.top().first->children.size() ){
                // preorder 
                cout<<stk.top().first->val<<" ";
                stk.pop() ;
                continue ;
            }


            stk.push({ stk.top().first->children[stk.top().second++ ] , -1 }) ;

        }
        cout<<endl;

    }

    static int diameter(generic_tree *root  , int &dia){

        int first_max_height = -1  , second_max_height = -1 ; 
        int tmp_dia ;

        for(auto x :  root->children ){

            tmp_dia = diameter(x , dia) ;

            if(first_max_height < tmp_dia ){
                first_max_height = tmp_dia ;
            }
            else{
                second_max_height = std::max( tmp_dia , second_max_height ) ;
            }

        }

        dia = std::max(dia , { first_max_height + second_max_height + 2 } ) ;

        return  std::max({ first_max_height , second_max_height }) +1  ;

    }

};

int main(void){

    int n1 , n2 , n3 , state = 0 ;
    cin>>n1;

    vector<int> v1(n1);

    for(auto &x :  v1 )cin>>x;

    generic_tree  *root1 = generic_tree::build(v1) ;
  
    // generic_tree::print(root);
    // cout<<generic_tree::height(root)<<endl;
    // generic_tree::pre_post(root) ;
    // generic_tree::lvlorder_nl(root) ;
    // cout<<endl;
    // generic_tree::del_leaf(root) ;
    // generic_tree::display(root) ;
    // generic_tree::lvlorder_nl(root) ;
    
    // cin>>n2;
    // vector<int> v2(n2);
    // for(auto &x :  v2 )cin>>x;

    // generic_tree  *root2 = generic_tree::build(v2) ;

    // bool ans = generic_tree::is_symmetric(root1) ;

    // if(ans){
    //     cout<<"true"<<endl;
    // }
    // else{
    //     cout<<"false"<<endl;
    // }

    // vector<int> ans = generic_tree::node_to_root(root1 , n2) ;
    // print java style 
    // cout<<"[" ;
    
    // for(int i=0  ; i < ans.size(); i++  ){
        
    //     cout<<ans[i] ;
       
    //     if(i==ans.size()-1 ) continue ;
    //     cout<<", " ;

    // }

    // cout<<"]" ;

    // print java style end 

    // CEIL = 90
    // FLOOR = 60
    // cout<<"CEIL = "<<root1->ceil(n2)<<endl;
    // cout<<"FLOOR = "<<root1->floor(n2)<<endl;
    // cin>>n2>>n3 ; 
    // int ans = generic_tree::distance_between_two_node(root1 , n2 , n3)  ;
    // cout<<ans<<endl;

    // cin>>n2 ;
    // vector<int> ans (3 , INT_MAX) ;
    // generic_tree::Predecessor_Successor(root1 , n2 , ans , state ) ;
    // // cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    // cout<<"Predecessor = "<< ( ans[0] == INT_MAX  ? ( "Not found" ) : ( to_string( ans[0] ) ) )<<endl;
    // cout<<"Successor = "<< ( ans[2] == INT_MAX  ? ( "Not found" ) : ( to_string( ans[2] ) ) )<<endl;

    // if()
    //  cout<<generic_tree::Kth_max(root1 , n2)<<endl;
    // pair<int , int > ans  ;
    // generic_tree::max_subtree(root1 , ans ) ;
    // cout<<ans.second<<"@"<<ans.first<<endl;
    // generic_tree::iterative_preorder(root1) ;
    // generic_tree::iterative_postorder(root1) ;
    // int dia=0 ;
    // generic_tree::diameter(root1 , dia) ;
    // cout<<dia<<endl;
    // generic_tree::delete_leaf(root1) ;
    // generic_tree::display(root1) ;



}