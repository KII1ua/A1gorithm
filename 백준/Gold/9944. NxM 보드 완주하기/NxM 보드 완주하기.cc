#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, cnt;
char graph[31][31];
bool visited[31][31];
int answer;
const int MAX = 1000001;

bool check() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] != '*' && !visited[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void bt(int x, int y, int dir, int cnt) {
    if(cnt >= answer) return;

    if(check()) {
        answer = min(answer, cnt);
        return;
    }

    if(dir == -1) {     // 방향 전환
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(!visited[nx][ny] && graph[nx][ny] != '*') {
                visited[nx][ny] = true;
                bt(nx, ny, i, cnt+1);
                visited[nx][ny] = false;
            }
        }
    }
    else {          // 기존의 방향 그대로
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] || graph[nx][ny] == '*') {
            bt(x, y, -1, cnt);
            return;
        }
        visited[nx][ny] = true;
        bt(nx, ny, dir, cnt);
        visited[nx][ny] = false;
    }
}

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == '.') {
                visited[i][j] = true;
                bt(i, j, -1, 0);
                visited[i][j] = false;
            }
        }
    }

    if(answer == MAX) {
        cout << "Case " << ++cnt << ": " << -1 << endl;
    }
    else {
        cout << "Case " << ++cnt << ": " << answer << endl;
    }

}

void input() {
    while(cin >> N >> M) {
        answer = MAX;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> graph[i][j];
            }
        }

        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}