#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int K=3,N=6;
    int arrival[]={1,2,3,5,4,6};
    int departure[]={4,5,6,7,8,9};
    int pref[]={1,1,2,1,2,3};
    int total=0;

    for (int c = 1; c <= K; c++){
        pair<int,int> cust[10];
        int m=0;

        for(int i=0;i<N;i++){
            if(pref[i]==c){
                cust[m++]={departure[i], arrival[i]};
            }
        }
        sort(cust,cust+m);
        stack<pair<int,int>> st;

        for (int i=0;i<m;i++){
            if (st.empty()){
                st.push(cust[i]);
                total++;
            }
            else if(cust[i].second>=st.top().first) {
                st.push(cust[i]);
                total++;
            }
        }
    }
    cout<<total<<endl;
    return 0;
}
