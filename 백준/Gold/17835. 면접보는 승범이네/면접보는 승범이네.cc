#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

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
int N, M, K;
vector<vector<pii>> v(100001);
ll dist[100001];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

void dijkstra() {
    while(!pq.empty()) {
        int Node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if(dist[Node] < cost) continue;

        for(auto it : v[Node]) {
            int nextNode = it.first;
            ll nextCost = cost + it.second;

            if(dist[nextNode] > nextCost) {
                pq.push({nextCost, nextNode});
                dist[nextNode] = nextCost;
            }
        }
    }
}

void solve() {
    dijkstra();

    int maxNode = 0;
    ll maxDist = 0;

    for(int i = 1; i <= N; i++) {
        if(dist[i] > maxDist) {
            maxNode = i;
            maxDist = dist[i];
        }
    }

    cout << maxNode << "\n" << maxDist;
}

void input() {
    cin >> N >> M >> K;

    fill(dist, dist+N+1, MAX);

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[b].push_back({a, c});
    }

    for(int i = 0; i < K; i++) {
        int a;
        cin >> a;
        pq.push({0, a});
        dist[a] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
