#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e18;
const int MAX = 10001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int V, E, M, x, S, y;
vector<vector<pii>> v(MAX);
ll dist_mac[MAX];
ll dist_star[MAX];
bool is_mac[MAX], is_star[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra_mac() {
    while(!pq.empty()) {
        int node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if(dist_mac[node] < cost) continue;

        for(auto &it : v[node]) {
            int nextNode = it.first;
            ll nextCost = cost + it.second;

            if(dist_mac[nextNode] > nextCost) {
                pq.push({nextCost, nextNode});
                dist_mac[nextNode] = nextCost;
            }
        }
    }
}

void dijkstra_star() {
    while(!pq.empty()) {
        int node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if(dist_star[node] < cost) continue;

        for(auto &it : v[node]) {
            int nextNode = it.first;
            ll nextCost = cost + it.second;

            if(dist_star[nextNode] > nextCost) {
                pq.push({nextCost, nextNode});
                dist_star[nextNode] = nextCost;
            }
        }
    }
}

void solve() {
    ll answer = INF;
    for(int i = 1; i <= V; i++) {
        if(!is_mac[i] && !is_star[i]) {
            if(dist_mac[i] <= x && dist_star[i] <= y) {
                answer = min(answer, dist_mac[i] + dist_star[i]);
            }
        }
    }

    if(answer == INF) {
        cout << -1;
    }
    else cout << answer;
}

void input() {
    cin >> V >> E;

    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for(int i = 1; i <= V; i++) {
        dist_mac[i] = INF;
        dist_star[i] = INF;
    }

    cin >> M >> x;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        pq.push({0, a});
        dist_mac[a] = 0;
        is_mac[a] = true;
    }

    dijkstra_mac();

    cin >> S >> y;

    for(int i = 0; i < S; i++) {
        int a;
        cin >> a;
        pq.push({0, a});
        dist_star[a] = 0;
        is_star[a] = true;
    }

    dijkstra_star();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}