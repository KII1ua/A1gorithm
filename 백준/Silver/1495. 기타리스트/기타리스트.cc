// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, S, M;
int volume[51];
bool visited[50001][51];
int dp[51];

void input() {
    cin >> N >> S >> M;

    for(int i = 1; i <= N; i++) {
        cin >> volume[i];
    }
}

void bfs() {
    int x = S;

    queue<pii> q;
    q.push(make_pair(0, S));
    visited[S][0] = true;

    while(!q.empty()) {
        int idx = q.front().first;
        int vol = q.front().second;
        q.pop();

        if(idx <= N) {
            int arr[] = {vol + volume[idx+1], vol - volume[idx+1]};

            for(int i = 0; i < 2; i++) {
                int xx = arr[i];

                if(xx >= 0 && xx <= M && !visited[xx][idx+1]) {
                    q.push(make_pair(idx+1, xx));
                    visited[xx][idx+1] = true;
                    dp[idx+1] = max(dp[idx+1], xx);
                }
            }
        }
    }
}

void solve() {
    memset(dp, -1, sizeof(dp));

    bfs();

    for(int i = 1; i <= N; i++) {
        if(dp[i] == -1) {
            cout << -1;
            return;
        }
    }

    cout << dp[N];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
