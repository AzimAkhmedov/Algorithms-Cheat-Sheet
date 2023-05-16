#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
   bool swapped = false;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
             swap(arr[j], arr[j + 1]);
             swapped = true;
            }
        }
        if(!swapped) break;
    }
        
}
void selectionSort(int arr[], int n){
    int min_idx;
    for (int i = 0; i < n-1; i++){
        min_idx = i;
        for (int j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx])
              min_idx = j;
        }
        if (min_idx!=i)
            swap(arr[min_idx], arr[i]);
    }
}
void display(int arr[], int size){
    for(int i = 0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

    int arr[4] = {2,5,3,1};
    bubbleSort(arr,4);
    display(arr,4);

     
    return 0;
}