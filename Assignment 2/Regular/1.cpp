#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int n=6;
   int start[n]={1,3,0,5,8,5};
   int finish[n]={2,4,6,7,9,9};
   stack<int> st,fi;

   pair<int,int> a[n];

   for(int i=0;i<n;i++){
    a[i]={finish[i],start[i]};
   }
   sort(a,a+n);

   st.push(a[0].second);
   fi.push(a[0].first);
   for(int i=1;i<n;i++){
     if(a[i].second>=fi.top()){
        st.push(a[i].second);
        fi.push(a[i].first);      
     }
   }

   cout<<"Max no of activities :"<<st.size();
    return 0;
}