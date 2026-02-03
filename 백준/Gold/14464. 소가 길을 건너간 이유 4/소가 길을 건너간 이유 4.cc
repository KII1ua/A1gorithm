#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 200001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int C, N;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pii> v;
vector<int> arr;

void solve() {
    sort(v.begin(), v.end());
    sort(arr.begin(), arr.end());

    int idx = 0;
    int cnt = 0;

    for(int i = 0; i < C; i++) {

        int chicken = arr[i];

        while(idx != N && v[idx].first <= chicken) {        // 가능한 소들 탐색
            pq.push(v[idx].second);
            idx++;
        }

        while(!pq.empty() && pq.top() < chicken) {
            pq.pop();
        }

        if(!pq.empty()) {
            cnt++;
            pq.pop();
        }
    }

    cout << cnt;
}

void input() {
    cin >> C >> N;

    for(int i = 1; i <= C; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}