/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

void min_heapify(int *a,int i,int n){
    int j;
    int temp = a[i];
    j = 2 * i;
    while (j < n){
        if (j < n && a[j+1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    
}
void build_minheap(int *a, int n)
{
    for(int i = n/2; i >= 0; i--)
    {
        min_heapify(a,i,n);
    }
}


int main(){
   int arr[10] = {1,5,10,20,1,0,7,9,11,90};
   for (int i = 0; i < 10; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   build_minheap(arr,10);
   cout<<"After heap building"<<endl;
    for (int i = 0; i < 10; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
