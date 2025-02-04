// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int V, E;
int dist[401][401];
int answer = INF;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> V >> E;

    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            dist[i][j] = INF;
            if(i == j) dist[i][j] = 0;
        }
    }

    for(int i = 0; i < E; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        if(dist[a][b] < c) continue;

        dist[a][b] = c;
    }

    for(int k = 1; k <= V; k++) {
        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    for(int i = 1; i <= V; i++) {
        for(int j = i; j <= V; j++) {
            if(i != j) {
                answer = min(dist[i][j] + dist[j][i], answer);
            }
        }
    }

    if(answer >= INF) {
        cout << -1;
        return 0;
    }
    
    cout << answer;
}
