//Binary Search
#include <iostream>
using namespace std;

int main() {
    int arr[]={1,2,3,4,5,6,7,8};
    int n;
    cout<<"Enter value to search";
    cin>>n;
    int left=0,right=7;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==n){
            cout<<"Element found at index :"<<mid;
        }
        else if(arr[mid]>n){
            right=mid-1;
        }
        else if(arr[mid]<n){
            left=mid+1;
        }
        else{
            cout<<"Element not found";
        }
    }
    return 0;
}