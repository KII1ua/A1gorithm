#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M, s, t;
int dist[5001];
vector<vector<pii> > v(5001);

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push(make_pair(dist[start], start));     // 가중치, 시작점

    while(!pq.empty()) {
        int Node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if(weight > dist[Node]) continue;

        for(auto it : v[Node]) {
            int nextNode = it.first;
            int Wei = it.second + weight;

            if(Wei < dist[nextNode]) {
                pq.push(make_pair(Wei, nextNode));
                dist[nextNode] = Wei;
            }
        }
    }
}

void solve() {
    for(int i = 1; i <= N; i++) {
        dist[i] = MAX;
    }

    dijkstra(s);

    cout << dist[t];
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    cin >> s >> t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}