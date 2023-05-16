#include <iostream>
using namespace std;

class Queue{
private:
    int size = 10;
    int arr[10];
    int rear;
    int front;

public:
    Queue(){
        size = 10;
        rear = -1;
        front = -1;
        for(int i =0; i< size; i++){
            arr[i] = 0;
        }
    }
    bool isEmpty(){
        return front == -1 && rear == -1;
    }
    bool isFull(){
     return (rear+1)%size==front; 
    }
    void enqueue(int val){
        if(isFull()) return;
        else if(isEmpty()){
            rear=0;
            front=0;
        }else{
            rear= (rear+1)%size;
        }
        arr[rear] = val;
    }
    void dequeue(){
        if(isEmpty()) return;
        if(front==rear){
          arr[rear] =0;
          front= -1;
          rear = -1;
          arr[rear] =0; 
        }else{
            arr[front] = 0;
            front = (front+1)%size;
        }
    }
    void displayQueue(){
        if (isEmpty()) {
          cout << " Empty Queue " << endl;
        }
        else{
            cout<<"Queue: ";
            for(int i = front; i!=rear; i =(i+1)%size){
                cout<<arr[i]<<" ";
            }
               cout <<arr[rear]<< endl;
        } 
    }
     
     int Top(){
         if(isEmpty()) return 0 ;
         return arr[rear];
     }

};
 
int main(){
    Queue q;
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