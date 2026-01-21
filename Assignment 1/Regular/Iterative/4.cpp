#include <iostream>
using namespace std;

int maxSubArray(int arr[],int n){
    int currSum=0;
    int maxSum=0;

    for (int i=0;i<n;i++) {
        currSum+=arr[i];
        if (currSum<0)
            currSum=0;
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}

int main(){
    int arr[]={2,3,-8,7,-1,2,3};
    cout<<maxSubArray(arr,7);
    return 0;
}