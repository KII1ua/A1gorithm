#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<pii> v;

void solve() {
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto it : v) {
        int day = it.first;
        int cost = it.second;
        pq.push(it.second);

        if(day < pq.size()) {
            pq.pop();
        }
    }

    ll answer = 0;
    while(!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;
}

void input() {
    cin >> N;

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
