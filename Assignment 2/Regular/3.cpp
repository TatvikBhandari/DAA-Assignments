#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n=3;
    int value[]={100,60,120};
    int weight[]={20,10,40};
    int w=50;

    pair<float,int> a[3];

    for (int i=0;i<n;i++){
        a[i]={(float)value[i]/weight[i],i};
    }

    sort(a,a+n,greater<>());
    float maxValue = 0.0f;

    for (int i=0;i<n && w>0;i++){
        int index=a[i].second;
        if(weight[index]<=w){
            maxValue+=value[index];
            w-=weight[index];
        }
        else{
            maxValue+=a[i].first*w;
            w=0;
        }
    }
    cout<<"Maximum value :"<<maxValue;
    return 0;
}
