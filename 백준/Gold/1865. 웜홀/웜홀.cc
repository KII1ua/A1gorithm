// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<pair<int, pii>> v;
int dist[501];
int TC, N, M, W;

bool bellmanford() {
    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < (2 * M) + W; j++) {
            int begin = v[j].first;
            int end = v[j].second.first;
            int cost = v[j].second.second;

//            if(dist[begin] == INF) continue;

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

    cin >> TC;

    for(int l = 0; l < TC; l++) {
        cin >> N >> M >> W;

        for(int k = 0; k < M; k++) {
            int S, E, T;
            cin >> S >> E >> T;
            v.push_back({S, {E, T}});
            v.push_back({E, {S, T}});
        }

        for(int c = 0; c < W; c++) {
            int S, E, T;
            cin >> S >> E >> T;
            v.push_back({S, {E, -T}});
        }
        
        if(bellmanford())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        v.clear();
    }
}
