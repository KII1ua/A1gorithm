#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int N, M, K;
ll dp[100001][21];
vector<vector<pii>> v(10001);

void dijkstra(int start) {
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            dp[i][j] = MAX;
        }
    }
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    pq.push({0, 1, 0});     // 비용, 정점, 횟수
    dp[1][0] = 0;

    while(!pq.empty()) {
        ll cost = get<0>(pq.top());
        int cur = get<1>(pq.top());
        int cnt = get<2>(pq.top());
        pq.pop();

        if(dp[cur][cnt] < cost) continue;

        for(auto it : v[cur]) {     // 포장하지 않는 경우 -> 더하는 경우
            int nextcur = it.first;
            ll accurcost = cost + it.second;

            if(cnt <= K && dp[nextcur][cnt] > accurcost) {
                pq.push({accurcost, nextcur, cnt});
                dp[nextcur][cnt] = min(dp[nextcur][cnt], accurcost);
            }
        }

        for(auto it : v[cur]) {     // 포장하지 않는 경우 -> 더하지 않는 경우
            int nextcur = it.first;

            if(cnt + 1 <= K && dp[nextcur][cnt+1] > cost) {
                pq.push({cost, nextcur, cnt+1});
                dp[nextcur][cnt+1] = min(dp[nextcur][cnt+1], cost);
            }
        }
    }
}

void solve() {
    dijkstra(1);

    ll result = MAX;

    for(int i = 0; i <= K; i++) {
        result = min(result, dp[N][i]);
    }

    cout << result;
}

void input() {
    cin >> N >> M >> K;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}