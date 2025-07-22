#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int C, N;
vector<pii> v;
int dp[10001];

void solve() {
    fill(dp, dp+C+101, MAX);
    dp[0] = 0;
    int result = MAX;
    for(auto it : v) {
        int cost = it.first;
        int client = it.second;

        for(int i = client; i <= C + 100; i++) {
            dp[i] = min(dp[i], dp[i-client] + cost);
        }
    }

    for(int i = C; i <= C + 100; i++) {
        result = min(dp[i], result);
    }

    cout << result;
}

void input() {
    cin >> C >> N;

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