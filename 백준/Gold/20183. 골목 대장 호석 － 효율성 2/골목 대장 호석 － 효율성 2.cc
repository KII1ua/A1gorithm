#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e14;
const int MAX = 100005;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, A, B;
ll C;
vector<vector<pii>> v(MAX);
ll dist[MAX];

bool check(ll shame) {
    for(int i = 1; i <= N; i++) dist[i] = INF;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, A});        // 수치심 노드
    dist[A] = 0;

    while(!pq.empty()) {
        int Node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if(dist[Node] < cost) continue;

        for(auto &it : v[Node]) {
            int nextNode = it.first;
            ll nextCost = it.second;

            if(nextCost > shame) continue;

            if(dist[nextNode] > nextCost + cost) {
                pq.push({nextCost + cost, nextNode});
                dist[nextNode] = nextCost + cost;
            }
        }
    }

    return dist[B] <= C;
}

void solve() {
    ll lo = 0;
    ll hi = INF;

    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        if(check(mid)) {
            hi = mid;
        }
        else lo = mid;
    }

    if(hi == INF) cout << -1;
    else cout << lo + 1;
}

void input() {
    cin >> N >> M >> A >> B >> C;


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