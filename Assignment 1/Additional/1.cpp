//Tutorial question
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    unordered_map<int, int> rank;
    for(int i = 0; i < n; i++) {
        rank[arr[i]] = i + 1;  
    }

    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cout << rank[x] << endl;
    }

    return 0;
}
