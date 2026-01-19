#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e14 + 1;
const int MAX = 502;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;

void solve() {
    vector<int> v(N, 0);

    for(auto &it : v) {
        cin >> it;
    }

    int answer = 0;

    while(v.size() != 1) {
        int idx = 0;
        int value = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] > value) {
                idx = i;
                value = v[i];
            }
        }

        if(v[idx - 1] >= 0) {
            left = v[idx-1];
        }

        if(v[idx + 1] < v.size()) {
            right = v[idx+1];
        }

        if(left > right) {
            answer += value - left;
            v.erase(v.begin() + idx);
        }
        else {
            answer += value - right;
            v.erase(v.begin() + idx);
        }
    }

    cout << answer;
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}