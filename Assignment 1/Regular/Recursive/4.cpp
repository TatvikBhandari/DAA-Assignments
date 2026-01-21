//maximum sub array(divide and concour)
#include <iostream>
using namespace std;

int maxMid(int arr[],int p,int m,int q){
    int sum=0,maxMidL=0;
    for(int i=m;i>=p;i--){
        sum+=arr[i];
        maxMidL=max(maxMidL,sum);
    }
    sum=0;
    int maxMidR=0;
    for(int i=m+1;i<=q;i++){
        sum+=arr[i];
        maxMidR=max(maxMidR,sum);
    }
    return maxMidR+maxMidL;
}
int MaxSum(int arr[],int p,int q){
    if(p==q){
        return max(arr[p],0);
    }
    int m=(p+q)/2;
    int maxL=MaxSum(arr,p,m);
    int maxR=MaxSum(arr,m+1,q);
    int maxM=maxMid(arr,p,m,q);

    int maxLR=max(maxL,maxR);
    return max(maxLR,maxM);
}
int main() {
    int arr[]={2,3,-8,7,-1,2,3};
    cout<<MaxSum(arr,0,6);
    return 0;
}