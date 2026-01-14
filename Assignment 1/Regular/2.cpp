//merge sort
#include <iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;

    int left[n1],right[n2];

    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=arr[m+j+1];
    }

    int i=0,j=0,k=l;
    while (i<n1 && j<n2) {
        if (left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while (i<n1){
      arr[k]=left[i];
      k++;i++;
    } 
    while (j<n2){
      arr[k]=right[j];
       k++;j++;
    }
}

void mergesort(int arr[],int l,int r){
   if(l<r){
    int m=l+(-l+r)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
   }
}
int main() {
    int n=7;
    int arr[n]={6,9,3,4,2,1,8};

    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}