#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<vector<pii>> v(1001);
int N, M;
int dist[1001];
int result;
int late;

void dijkstra(int start) {
    for(int i = 1; i <= N; i++) {
        dist[i] = MAX;
    }

    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cost = pq.top().first;
        int locate = pq.top().second;
        pq.pop();

        if(dist[locate] < cost) continue;

        for(int i = 0; i < v[locate].size(); i++) {
            int nextlocate = v[locate][i].first;
            int nextcost = cost + v[locate][i].second;

            if(dist[nextlocate] > nextcost) {
                pq.push(make_pair(nextcost, nextlocate));
                dist[nextlocate] = nextcost;
            }
        }
    }
}

void dijkstrast(int start, int Node) {
    for(int i = 1; i <= N; i++) {
        dist[i] = MAX;
    }

    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int cost = pq.top().first;
        int locate = pq.top().second;
        pq.pop();

        if(dist[locate] < cost) continue;

        for(int i = 0; i < v[locate].size(); i++) {
            int nextlocate = v[locate][i].first;
            int nextcost = cost + v[locate][i].second;

            if(nextlocate == Node) continue;

            if(dist[nextlocate] > nextcost) {
                pq.push(make_pair(nextcost, nextlocate));
                dist[nextlocate] = nextcost;
            }
        }
    }
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        v[a].push_back(make_pair(b, t));
        v[b].push_back(make_pair(a, t));
    }
}

void solve() {
    dijkstra(1);

    result = dist[N];

    for(int i = 2; i < N; i++) {
        dijkstrast(1, i);
        late = max(late, dist[N]);
    }


    if(late == MAX) cout << -1;
    else cout << late - result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}