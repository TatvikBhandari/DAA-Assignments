#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int m=3,n=3;
    int x[]={2, 1}; 
    int y[]={3, 1}; 
    int hx=m-1,vy=n-1;
    sort(x,x+hx,greater<int>());
    sort(y,y+vy,greater<int>());
    int hP=1,vP=1;
    int i=0,j=0;
    int cost=0;
    while(i<hx && j<vy){
        if(x[i]>y[j]){
            cost+=x[i]*vP;
            hP++;
            i++;
        }
        else{
            cost+=y[j]*hP;
            vP++;
            j++;
        }
    }
    while(i<hx){
        cost+=x[i]*vP;
        i++;
    }
    while(j<vy){
        cost+=y[j]*hP;
        j++;
    }
    cout<<"Minimum cost :"<<cost<<endl;
    return 0;
}
