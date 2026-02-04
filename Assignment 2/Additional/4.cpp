#include <iostream>
using namespace std;

int main() {
    int gas[]={1,2,3,4,5};
    int cost[]={3,4,5,1,2};
    int n=5;
    int tGas=0,tCost=0;
    int tank=0,start=0;
    
    for (int i=0;i<n;i++){
        tGas+=gas[i];
        tCost+=cost[i];
        tank+=gas[i]-cost[i];
        if(tank<0){
            start=i+1;
            tank=0;
        }
    }
    if(tGas<tCost){
        cout<<-1<<endl;
    }
    else{
        cout<<start<<endl;
    }
    return 0;
}
