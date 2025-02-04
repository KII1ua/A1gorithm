// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
vector<pair<int, pair<int, int>>> v;
ll dist[501];

bool bellmanford(int start) {
    dist[start] = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < M; j++) {
            int begin = v[j].first;
            int end = v[j].second.first;
            int cost = v[j].second.second;

            if(dist[begin] == INF) continue;

            if(dist[end] > dist[begin] + cost) {
                dist[end] = dist[begin] + cost;

                if(i == N) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, {b, c}});
    }

    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    bool visited = bellmanford(1);

    if(visited) {
        cout << -1;
        return 0;
    }

    for(int i = 2; i <= N; i++) {
        if(dist[i] != INF)
            cout << dist[i] << endl;
        else
            cout << -1 << endl;
    }
}
