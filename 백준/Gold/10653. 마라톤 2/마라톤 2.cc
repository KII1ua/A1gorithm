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
int N, K;
vector<pii> v;

int dist(int a, int b, vector<pii> &vec) {
    return abs(vec[a].first - vec[b].first) + abs(vec[a].second - vec[b].second);
}

void solve() {
    vector<vector<int>> dp(N, vector<int>(K+1, MAX));
    dp[0][0] = 0;

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i && j <= K; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i-k-1][j-k] + dist(i-k-1, i, v));
            }
        }
    }

    int answer = MAX;
    for(int i = 0; i <= K; i++) {
        answer = min(answer, dp[N-1][i]);
    }

    cout << answer;
}

void input() {
    cin >> N >> K;

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
