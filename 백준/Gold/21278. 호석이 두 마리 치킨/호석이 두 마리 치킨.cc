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
int N, M;
int graph[101][101];
bool check[101];
int dist[101];
pii result;
int mindist = MAX;

void init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = MAX;
        }
    }
}

void bt(int idx, int cnt) {
    if(cnt == 2) {
        memset(dist, 0, sizeof(dist));
        int valdist = 0;

        for(int i = 1; i <= N; i++) {
            int curdist = MAX;
            for(int j = 1; j <= N; j++) {
                if(check[i]) {
                    curdist = 0;
                }
                if(check[j] && curdist > graph[i][j]) {
                    curdist = graph[i][j];
                }
            }
            dist[i] = curdist * 2;
            valdist += dist[i];
        }

        if(mindist > valdist) {
            mindist = valdist;

            int tmp = 0;

            for(int i = 1; i <= N; i++) {
                if(check[i] && tmp == 0) {
                    result.first = i;
                    tmp++;
                }
                else if(check[i] && tmp == 1) {
                    result.second = i;
                    break;
                }
            }
        }
        return;
    }

    for(int i = idx; i <= N; i++) {
        if(!check[i]) {
            check[i] = true;
            bt(idx+1, cnt+1);
            check[i] = false;
        }
    }
}

void solve() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    bt(1, 0);

    cout << result.first << " " << result.second << " " << mindist;
}

void input() {
    cin >> N >> M;

    init();

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}