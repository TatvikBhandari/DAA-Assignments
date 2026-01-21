//kaneki and mysterious item
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t>0){
        long long N,H,W;
        cin>>N>>H>>W;

        long long low=(H>W)?H:W;
        long long high=low*N;   

        while(low<high){
            long long mid=low+(high-low)/2;

            long long rows=mid/H;
            long long cols=mid/W;

            if(rows>0 && rows*cols>=N){
                high=mid;      
            } 
            else{
                low=mid+1;   
            }
        }
        cout<<low<<endl;
        t--;
    }
    return 0;
}