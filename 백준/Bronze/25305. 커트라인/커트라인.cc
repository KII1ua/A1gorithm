#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int N, k;
    int tmp;
    vector<int> v;

    cin >> N >> k;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), compare);
    cout << v[k-1];
}