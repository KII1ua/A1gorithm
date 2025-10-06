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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
vector<pair<ll, ll>> v;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve() {
    int answer = 1;
    sort(v.begin(), v.end());

    pq.push(v[0].second);

    for(int i = 1; i < N; i++) {
        if(!pq.empty() && pq.top() <= v[i].first) pq.pop();
        pq.push(v[i].second);
        answer = max(answer, (int)pq.size());
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
