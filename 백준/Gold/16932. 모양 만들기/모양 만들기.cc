#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
int graph[1001][1001];
int tmp = 2;
int arr[100001];
int result = 0;

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
}

int bfs(int x, int y) {
    queue<pii> q;
    q.push(make_pair(x, y));
    graph[x][y] = tmp;
    int cnt = 1;

    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(graph[nx][ny] == 1) {
                    graph[nx][ny] = tmp;
                    q.push(make_pair(nx, ny));
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == 1) {
                int idx = bfs(i, j);
                arr[tmp] = idx;
                tmp++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == 0) {
                set<int> st;
                int res = 0;
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if(graph[nx][ny] != 0) {
                            st.insert(graph[nx][ny]);
                        }
                    }
                }

                for(auto s : st) {
                    res += arr[s];
                }

                result = max(result, res);
            }
        }
    }

    cout << result+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
