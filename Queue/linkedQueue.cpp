#include <iostream>
using namespace std;
struct Node{
    int val;
    Node*next;
    Node(){
        val = 0;
        next = nullptr;
    }
    Node(int v){
        val=v;
        next=nullptr;
    }

};
class Queue{
private:
   Node *head;
public:
    Queue(){
      head = new Node();
    }
    Queue(int v){
        head = new Node(v);
    }
    bool isEmpty(){
        return !head;
    }
    void enqueue(int val){
        if(isEmpty()) head->next = new Node(val);
        else{
         Node*ptr=head; 
         while(ptr->next){
         ptr = ptr->next;
       }
         ptr->next = new Node(val);
        }
    }
    void dequeue(){
        if(isEmpty()) cout<<"Nothing to delete \n";
        else{
            Node*ptr = head->next;
            head = ptr;
        }
       
    }
    void displayQueue(){
        Node*ptr = head;
       while(ptr->next){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
       }
       cout<<ptr->val<<endl;
    }
     
     int Top(){
        Node*ptr = head;
        while(ptr->next){
            ptr=ptr->next;
        } 
        return ptr->val;

     }

};
 
int main(){
    Queue q = Queue(1);
    q.enqueue(1);
    q.enqueue(12);
    q.enqueue(11);
    q.enqueue(2);
    q.displayQueue();
    q.dequeue();
    // after dequeue;
    q.displayQueue();
    cout<<"Top: "<< q.Top()<<endl;
   
    
    return 0;
}