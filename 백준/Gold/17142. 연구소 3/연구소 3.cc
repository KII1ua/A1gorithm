#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int left, right;
};

const int INF = 1e9;
const int MAX = 100001;
const int D = 2000000;
const int MOD = 10007;
//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N, M;
int graph[51][51];      // 0 : 빈칸, 1 : 벽, 2 : 바이러스 객체
int answer = 1e9;
vector<pii> v;
int checked[51][51][1025];

void bfs() {
    memset(checked, -1, sizeof(checked));
    for(int k = 0; k < (1 << v.size()); k++) {
        int cnt = 0;
        for(int j = 0; j < v.size(); j++) {
            if((k & (1 << j))) cnt++;
        }

        if(cnt != M) continue;
        queue<pii> q;
        for(int l = 0; l < v.size(); l++) {
            if(k & (1 << l)) {
                q.push({v[l].first, v[l].second});
                checked[v[l].first][v[l].second][k] = 0;
            }
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if(checked[nx][ny][k] == -1 && graph[nx][ny] != 1) {
                    q.push({nx, ny});
                    checked[nx][ny][k] = checked[x][y][k] + 1;
                }
            }
        }

        bool flag = false;
        int ans = 0;

        for(int l = 0; l < N; l++) {
            for(int m = 0; m < N; m++) {
                if(graph[l][m] == 0 && checked[l][m][k] == -1) {
                    flag = true;
                    break;
                }

                if(graph[l][m] == 0 && checked[l][m][k] != -1) {
                    ans = max(ans, checked[l][m][k]);
                }
            }
            if(flag) break;
        }

        if(!flag) {
            answer = min(answer, ans);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 2) {
                v.push_back({i, j});
            }
        }
    }

    bfs();
    
    if(answer == 1e9) {
        cout << -1;
    }
    else cout << answer;
}