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
            else if(ss=="size"){
                cout<<size<<endl;
                continue;
            }

            return ;
        }
        
    }

    void Display(){
        Node*tmp = head ;
        if(tmp==nullptr) return ;
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