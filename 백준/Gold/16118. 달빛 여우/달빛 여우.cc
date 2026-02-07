#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 2e9;
const int MAX = 4001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
double dist[MAX][2];
int dists[MAX];
vector<vector<pair<int, double>>> v(MAX);

void dijkstras() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dists[1] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(dists[node] < cost)  continue;

        for(auto &iter : v[node]) {
            int nextNode = iter.first;
            int nextCost = iter.second + cost;

            if(dists[nextNode] > nextCost) {
                pq.push({nextCost, nextNode});
                dists[nextNode] = nextCost;
            }
        }
    }
}

void dijkstra() {
    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
    pq.push({0, 1, 0});     // 가중치, 노드, 횟수
    dist[1][0] = 0;

    while(!pq.empty()) {
        int node = get<1>(pq.top());
        double cost = get<0>(pq.top());
        int count = get<2>(pq.top());
        pq.pop();

        if(dist[node][count] < cost) continue;

        for(auto &iter : v[node]) {
            int nextNode = iter.first;
            double nextCost = (count % 2 == 0? cost + (iter.second / 2) : cost + (iter.second * 2));

            if(dist[nextNode][(count+1) % 2] > nextCost) {
                pq.push({nextCost, nextNode, (count+1) % 2});
                dist[nextNode][(count+1) % 2] = nextCost;
            }
        }
    }
}

void solve() {
    dijkstra();
    dijkstras();

    int answer = 0;
    for(int i = 1; i <= N; i++) {
        double cost = INF;
        for(int j = 0; j < 2; j++) {
            cost = min(dist[i][j], cost);
        }
        if(dists[i] < cost) answer++;
    }

    cout << answer;
}

void Init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 2; j++) {
            dist[i][j] = INF;
        }
    }

    for(int i = 1; i <= N; i++) {
        dists[i] = INF;
    }
}

void input() {
    cin >> N >> M;

    Init();

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