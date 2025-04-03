#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Endl "\n"
#define MAX 1e9

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
int graph[20][20];
bool visited[20][20];
int startx, starty;
int dist, Exp;
int lv = 2;
bool End;

void bfs(int x, int y) {
    queue<tuple<int, int, int>> q;
    vector<tuple<int, int, int>> v;     // 거리, x, y;
    q.push(make_tuple(x, y, 0));
    visited[x][y] = true;

    while(!q.empty()) {
        int xx = get<0>(q.front());
        int yy = get<1>(q.front());
        int dst = get<2>(q.front());
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(visited[nx][ny] || graph[nx][ny] > lv) continue;

            if(graph[nx][ny] != 0 && graph[nx][ny] < lv) {      // 같은 경로 상에서 먹이를 먹는 경우
                v.push_back(make_tuple(dst+1, nx, ny));
            }

            q.push(make_tuple(nx, ny, dst+1));
            visited[nx][ny] = true;
        }
    }

    if(v.empty()) {
        End = true;
        return;
    }

    sort(v.begin(), v.end());       // 거리, 행, 열 순으로 정렬
    dist += get<0>(v[0]);
    startx = get<1>(v[0]);
    starty = get<2>(v[0]);
    graph[startx][starty] = 0;
    Exp++;
    if(lv == Exp) {
        lv++;
        Exp = 0;
    }
}

void solve() {
    while(!End) {
        memset(visited, 0, sizeof(visited));
        bfs(startx, starty);
    }

    cout << dist;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 9) {
                startx = i;
                starty = j;
                graph[i][j] = 0;
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
