#include <iostream>
#include <stack>
using namespace std;

bool isPowerOfTwo(int n){
    return (n&(n-1))==0;
}

int main(){
    string s="fooland";
    int k=2;
    int n=s.length();
    if(isPowerOfTwo(n))
        k=k/2;
    else{
        k=2*k;
    }
    stack<char> st;
    for (char c : s){
        while(!st.empty() && k>0 && st.top()>c){
            st.pop();
            k--;
        }
        st.push(c);
    }
    while(k>0 && !st.empty()){
        st.pop();
        k--;
    }
    string ans= "";
    while (!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }
    cout<<ans<<endl;
    return 0;
}
