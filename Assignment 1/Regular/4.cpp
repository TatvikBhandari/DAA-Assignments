// Maximum sub-array sum
#include <iostream>
using namespace std;

int main() {
    int arr[]={2,3,-8,7,-1,2,3};
    int sumarray[7];
    int n=7;
    int maxsum=arr[0];
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxsum=max(maxsum,sum);
        }
    }
    cout<<"Maximum subarray Sum:"<<maxsum;
    return 0;
}