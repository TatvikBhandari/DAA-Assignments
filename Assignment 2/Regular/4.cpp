#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n=5;
    int deadline[n]={2,1,2,1,3};
    int profit[n]={100,19,27,25,15};
    
    int maxsize=0;
    for(int i=0;i<n;i++){
        if(maxsize<deadline[i]){
            maxsize=deadline[i];
        }
    }
    int selectedjobs[maxsize];
    for(int i=0;i<maxsize;i++){
        selectedjobs[i]=-1;
    }

    pair<int,int> a[n];
    for(int i=0;i<n;i++){
        a[i]={profit[i],deadline[i]};
    }

    sort(a,a+n,greater<>());

    int count=0,tprofit=0;
    for(int i=0;i<n;i++) {
        int d=a[i].second;

        for(int j=d-1;j>=0;j--){
            if(selectedjobs[j]==-1){
                selectedjobs[j]=a[i].first; 
                count++;
                tprofit+=a[i].first;
                break;
            }
        }
    }
    cout<<"Jobs Completed:"<<count<<endl;
    cout<< "Maximum Profit:"<<tprofit<<endl;
    return 0;
}