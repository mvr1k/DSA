#include <bits/stdc++.h> 
using namespace std;
void swap(vector<int> &arr,int l,int r){
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}
void heapify(vector<int> &arr,int index){
    //we have to consider the following node and its immidiate childs
    //if left child is bigger we have to swap the left with root and call heapify on root
    //same goes for the right node
    int n = arr.size();

    int left = index * 2 + 1;
    int right = index * 2 + 2;


    int biggest = index;//by default its going to be the current one
    //check if left node is worthy
    //but make sure that the node exists 
    if(left < n && arr[left] > arr[biggest]){
        biggest = left;
    } 
    if(right < n && arr[right] > arr[biggest]){
        biggest = right;
    }

    //after this we surely have the worthiest guy who will take the root position
    //if we dont have than basically its already heapified

    if(biggest != index){
        swap(arr,biggest,index);
        heapify(arr, biggest);
    }
    //swap with the root and hipify the children

    



}
vector<int> buildMinHeap(vector<int> &arr){
    //we have to heapify each and every non leaf node in a bottom up approach
    //as we know in a complete binary tree 
    //leaf nodes -> n / 2 + 1 -> n - 1
    //non-leaf nodes 0 -> n / 2 - 1 
    int n = arr.size();
    for(int i = (n / 2) - 1;i >= 0;i--){
        heapify(arr, i);
    }
    return arr;
}


int main(){
    vector<int> arr;
    arr = {9 ,3 ,2 ,6 ,7};
    arr = buildMinHeap(arr);
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
}