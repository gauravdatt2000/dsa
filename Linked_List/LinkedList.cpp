#include "bits/stdc++.h"
using namespace std;

class Node{
  public : 
  
  int data;
  Node *next ; 

  Node(int val){
    data = val;
  }

};

class LinkedList{
    public :

    Node* head = nullptr ;
    Node* tail =  nullptr ;

    int size = 0;

    void AddAt(int index , int data){

    }

    void removeFirst(){
        if(head){
            head = head->next;
            size--;
            return ;
        }
        cout<<"List is empty"<<endl;
    }

    void getFirst(){
        if(size){
            cout<<head->data<<endl;
            return;
        }
        cout<<"List is empty"<<endl;
    }

    void getLast(){
        if(size){
            cout<<tail->data<<endl;
            return ;
        }
        cout<<"List is empty"<<endl;
    }

    void getAt(int index){
        
        if(size==0){
            cout<<"List is empty"<<endl;
        }
        else if( 0 <= index && index < size){
            
            Node *tmp = head ;
            int tempIndex = 0;

            while(tmp!=nullptr ){
                if(tempIndex==index){
                    cout<<tmp->data<<endl ;
                    return ;
                }
                tempIndex++;
                tmp = tmp ->next; 
            }

        }
        else{
            cout<<"Invalid arguments"<<endl;
        }
    }

    void AddLast(int data){
        size++;
        Node *tmp = new Node(data) ;

        if(head){
            tail->next = tmp ;
            tail = tail->next ;
            return ;
        }
        head = tmp ;
        tail = tmp ;
    }

    void AddFirst(int data){
        
        Node *tmp = new Node(data) ;
        size++ ;

        if(head){
            tmp->next = head ;
            head = tmp ;
            return ;
        }
        head  = tmp ;
        tail = tmp ;

    }

    void Execute(){
        
        string ss;
        int tmpData;

        while (cin>>ss)
        {
            if(ss=="addLast"){
                cin>>tmpData;
                AddLast(tmpData);
                continue;
            }
            else if(ss=="display"){
                Display();
                continue;
            }
            else if(ss=="getFirst"){
                getFirst();
                continue;
            }
            else if(ss=="addFirst"){
                cin>>tmpData ;
                AddFirst(tmpData);
                continue;
            }
            else if(ss=="getLast"){
                getLast();
                continue;
            }
            else if(ss=="removeFirst"){
                removeFirst();
                continue;
            }
            else if(ss=="getAt"){
                cin>>tmpData;
                getAt(tmpData);
                continue;
            }
            else if(ss=="size"){
                cout<<size<<endl;
                continue;
            }

            return ;
        }
        
    }

    void Display(){
        Node*tmp = head ;
        while(tmp){
            cout<<tmp->data<<" ";
            tmp =  tmp->next ;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList linkedList ;
    linkedList.Execute();
}