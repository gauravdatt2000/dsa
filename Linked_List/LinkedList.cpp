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

            return ;
        }
        
    }

    void Print(){
        Node*tmp = head ;
        while(tmp){
            cout<<tmp->data<<endl;
            tmp =  tmp->next ;
        }
    }
};

int main(){
    LinkedList linkedList ;
    linkedList.Execute();
    linkedList.Print();
    cout<<linkedList.size<<endl;
    if(linkedList.tail){
        cout<<linkedList.tail->data<<endl;
    }
}