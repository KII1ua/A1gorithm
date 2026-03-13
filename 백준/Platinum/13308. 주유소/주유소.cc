#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e14;
const int MAX = 2501;
const int D = 2000000;
const int MOD = 10007;
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0, 0};
int dy[] = {0, -1, 1};
int N, M;
vector<vector<pii>> v(MAX);
int price[MAX];
ll dp[MAX][MAX];       // i까지 왔을때 지나쳐온 주유소중 j가격의 최소 비용

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({price[1], 1, 0});     // 비용, 노드, 가격
    dp[1][price[1]] = 0;

    while(!pq.empty()) {
        int mincost = get<0>(pq.top());
        int node = get<1>(pq.top());
        ll cost = get<2>(pq.top());
        pq.pop();

        if(dp[node][mincost] < cost) continue;

        for(auto &iter : v[node]) {
            int nextnode = iter.first;
            int nextmincost = min(mincost, price[nextnode]);
            ll nextcost = cost + iter.second * mincost;

            if(dp[nextnode][nextmincost] > nextcost) {
                pq.push({nextmincost, nextnode, nextcost});
                dp[nextnode][nextmincost] = nextcost;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> price[i];
    }

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= MAX; j++) {
            dp[i][j] = INF;
        }
    }

    dijkstra();

    ll answer = INF;

    for(int i = 0; i <= MAX; i++) {
        answer = min(answer, dp[N][i]);
    }

    cout << answer;
}