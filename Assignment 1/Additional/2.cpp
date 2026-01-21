//number of overtakes
#include <iostream>
using namespace std;

int merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int count=0;
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
            count+=(n1-i);
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
    return count;
}

int mergesort(int arr[],int l,int r){
    int count=0;
   if(l<r){
    int m=l+(-l+r)/2;
    count+=mergesort(arr,l,m);
    count+=mergesort(arr,m+1,r);
    count+=merge(arr,l,m,r);
   }
   return count;
}

int main() {
    int n;
    cout<<"Enter size :";
    cin>>n;
    int arr[n];
    cout<<"enter array elements :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<mergesort(arr,0,n-1);
    return 0;
}