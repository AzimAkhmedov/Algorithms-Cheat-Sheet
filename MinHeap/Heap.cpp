/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class MinHeap{
    int *heap_array; 
    int capacity; 
    int heap_size;

public:
    MinHeap(int capacity){
        this->heap_size = 0;
        this->capacity = capacity;
        this->heap_array = new int[capacity];
    }
     void MinHeapify(int i){
        int l = left(i);
        int r = right(i);

        int smallest = i;
        if (l < heap_size && heap_array[l] < heap_array[i])
            smallest = l;
        if (r < heap_size && heap_array[r] < heap_array[smallest])
            smallest = r;

        if (smallest != i){
            swap(heap_array[i], heap_array[smallest]);
            MinHeapify(smallest);
        }
    }
    int parent(int i){ return (i-1)/2;}
    int left(int i){ return (2*i + 1);}
    int right(int i){ return (2*i + 2);}
    int getMin(){ return heap_array[0]; }

    void insert(int k){
        if (heap_size == capacity){
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }
        int i = heap_size;
        heap_array[heap_size++] = k;

        while (i != 0 && heap_array[parent(i)] > heap_array[i]){
            swap(heap_array[i], heap_array[parent(i)]);
            i = parent(i);
        }
        
    }
    int extractMin(){
        if (heap_size <= 0)
            return -1;
        if (heap_size == 1){
            heap_size--;
            return heap_array[0];
        }
        int root = heap_array[0];
        heap_array[0] = heap_array[heap_size-1];
        heap_size--;
        MinHeapify(0);

        return root;
    }
    void printElements(){
        for(int i = 0; i<heap_size; i++){
            cout<<heap_array[i]<<" ";
        }
        cout<<endl;
    }
};  
int main(){
        MinHeap h(11);
    h.insert(15);
    h.insert(2);
    h.insert(3);
    h.insert(1);
    h.insert(45);
    h.insert(5);
    h.insert(4);
    cout << "Root of heap: " << h.getMin() << endl;
    
    h.printElements();
    h.extractMin();
    
    
    h.printElements();
    return 0;
}
