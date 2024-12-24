#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    int N, tmp;
    vector<int> v;
    int cnt = 4;
    int res = 0;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++) {
        int start = i;
        int end = N-1;
        while(start < end) {
            if(v[end] - v[start] > 4) {
                end--;
            } else {
                res = 4 - (end - start);
                cnt = min(cnt, res);
                break;
            }
        }
    }
    cout << cnt;
}