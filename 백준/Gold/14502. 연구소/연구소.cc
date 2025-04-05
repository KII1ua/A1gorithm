#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
int graph[9][9];
int C_graph[9][9];
vector<pii> wall, virus;
bool visited[64];
int result;
bool lab[9][9];

void bfs(int x, int y) {
    memset(lab, 0, sizeof(lab));
    queue<pii> q;
    q.push(make_pair(x, y));
    lab[x][y] = true;

    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        lab[xx][yy] = true;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if(!lab[nx][ny] && C_graph[nx][ny] != 1) {
                    q.push(make_pair(nx, ny));
                    C_graph[nx][ny] = 2;
                    lab[nx][ny] = true;
                }
            }
        }
    }
}

int areaCount() {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(C_graph[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

void Copy_graph() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            C_graph[i][j] = graph[i][j];
        }
    }
}

void make_wall() {
    memset(lab, 0, sizeof(lab));
    int cnt = 0;
    Copy_graph();

    for(int i = 0; i < wall.size(); i++) {
        if(cnt == 3) break;

        if(visited[i]) {
            int x = wall[i].first;
            int y = wall[i].second;
            C_graph[x][y] = 1;
            cnt++;
        }
    }

    for(int i = 0; i < virus.size(); i++) {
        int x = virus[i].first;
        int y = virus[i].second;

        bfs(x, y);
    }

    result = max(result, areaCount());
}

void dfs(int x, int cnt) {
    if(cnt == 3) {
        make_wall();
        return;
    }

    for(int i = x; i < wall.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(x, cnt+1);
            visited[i] = false;
        }
    }
}

void solve() {
    dfs(0, 0);

    cout << result;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 0) {
                wall.push_back(make_pair(i, j));
            }
            else if(graph[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
