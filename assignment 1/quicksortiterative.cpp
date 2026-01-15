#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void iterativeQuickSort(vector<int>& arr, int low, int high) {
    stack<pair<int, int>> s;

    s.push({low, high});

    while (!s.empty()) {
        int l = s.top().first;
        int h = s.top().second;
        s.pop();

        int p = partition(arr, l, h);

        if (p - 1 > l) {
            s.push({l, p - 1});
        }

        if (p + 1 < h) {
            s.push({p + 1, h});
        }
    }
}

int main() {
    vector<int> data = {10, 7, 8, 9, 1, 5};
    int n = data.size();

    iterativeQuickSort(data, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    return 0;
}