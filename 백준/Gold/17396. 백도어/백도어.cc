#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e18

struct coordinate {
    int x;
    int y;
    int r;
};

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int arr[100001];
vector<vector<pair<ll, ll>>> v(100001);
ll dist[100001];

void dijkstra() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    fill(dist, dist + N, MAX);
    dist[0] = 0;
    pq.push({0, dist[0]});

    while(!pq.empty()) {
        ll node = pq.top().first;
        ll cost = pq.top().second;
        pq.pop();

        if(dist[node] < cost) continue;

        for(auto iter : v[node]) {
            ll nextNode = iter.first;
            ll nextCost = cost + iter.second;

            if(dist[nextNode] > nextCost) {
                dist[nextNode] = nextCost;
                pq.push({nextNode, nextCost});
            }
        }
    }

    cout << ((dist[N-1] == MAX)? -1 : dist[N-1]);
}

void solve() {
    dijkstra();
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    arr[N-1] = 0;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(arr[a] || arr[b]) continue;
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
