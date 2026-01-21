//Binary Search
#include <iostream>
using namespace std;

void binarySearch(int arr[],int left,int right,int n){
    if(left>right){
        cout<<"Element not found";
        return;
    }

    int mid=left+(right-left)/2;

    if(arr[mid]==n){
        cout<<"Element found at index :"<<mid;
        return;
    }
    else if(arr[mid]>n){
        binarySearch(arr,left,mid-1,n);
    }
    else if(arr[mid]<n){
        binarySearch(arr,mid+1,right,n);
    }
}

int main() {
    int arr[]={1,2,3,4,5,6,7,8};
    int n;
    cout<<"Enter value to search";
    cin>>n;

    int left=0,right=7;
    binarySearch(arr,left,right,n);
    return 0;
}
