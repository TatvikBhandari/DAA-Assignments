#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N=6;
    int st[]={1,2,4,6,5,8};
    int en[]={3,5,6,7,9,10};
    int Q=3;
    int plan_st[]={1,2,4};
    int plan_en[]={6,7,10};

    pair<int,int> courses[6];
    for (int i=0;i<N;i++){
        courses[i]={en[i],st[i]};
    }
    sort(courses,courses+N);
    for(int q=0;q<Q;q++){
        int L=plan_st[q];
        int R=plan_en[q];
        int count=0;
        int lastEnd=-1;

        for(int i=0;i<N;i++){
            int s=courses[i].second;
            int e=courses[i].first;

            if (s>=L && e<=R && s>=lastEnd){
                count++;
                lastEnd=e;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
