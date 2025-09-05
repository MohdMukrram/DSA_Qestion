#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class DLL{ // user difine data structure//
public:
    Node* head;
    Node* tail;
    int size;
    DLL(){
       head = tail = NULL;
       size =0;
    }
    void insertAtTail(int val){
        Node* temp = new Node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp; 
         }
        size++;
    }
    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            temp->next=head;
            head->prev = temp;
            head=temp;
         }
        size++;
    }
    void insertAt (int idx,int val){
        if(idx<0 || idx>size) cout<<"Invalid Index"<<endl;
        else if(idx==0) insertAtHead(val);
        else if(idx==size) insertAtTail(val);
        else{
            Node* t=new Node(val);
            Node* temp = head;
            for(int i=1;i<=idx-1;i++){
                temp = temp->next;
            } 
            t->next = temp->next;
            temp->next = t;
            t->prev = temp;
            t->next->prev = t;
            size++;
         }
    }
    int getAtIdx(int idx){
        if(idx<0||idx>=size){
            cout<<"Invalide Index"<<endl;
            return -1;
        }
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else{
            Node* temp=head;
            for(int i=1;i<=idx;i++){
                temp = temp->next;
            }
            return temp->val;
        }
    }
    void deleteAtHead(){
        if(size==0){
            cout<<"list is empty"<<endl;
            return;
        }
        head= head->next;
       if(head) head->prev = NULL;
       if(head==NULL) tail = NULL;
        size--;
    }
    void deleteAtTail(){
        if(size==0){
            cout<<"list is empty";
            return;
        }
        else if(size==1){
            deleteAtHead();
            return;
        }
        Node* temp = tail->prev;
        temp->next=NULL;
        tail=temp;
        size--;
    }
    void deleteAtIdx(int idx){
       if(size==0){
            cout<<"list is empty";
            return;
        }
        else if(idx<0||idx>=size){
            cout<<"Invalide Index"<<endl;
            return;
        }
        else if(idx==0) return deleteAtHead();
        else if(idx==size-1) return deleteAtTail();
        else{
            Node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp = temp->next;
            }
            temp->next=temp->next->next;
            temp->next->prev = temp;
            size--;
        } 
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl; 
    }
 
};
int main(){
   DLL list;
   list.insertAtTail(10);
    list.display();
    list.insertAtTail(20);
    list.display();
    list.insertAtHead(30);
    list.insertAtHead(40);
    list.insertAtHead(50);
    list.insertAt(2,70);
    list.display();
    list.deleteAtHead();
    list.display();
    list.deleteAtTail();
    list.display();
    list.deleteAtIdx(2);
    list.display();
    cout<<list.getAtIdx(1);
} 