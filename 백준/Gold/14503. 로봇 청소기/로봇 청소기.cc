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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int graph[50][50];
bool visited[50][50];
int N, M;
int x, y, dir;

int robotback() {
    if(dir == 0) return 2;
    else if(dir == 1) return 3;
    else if(dir == 2) return 0;
    else return 1;
}

void rotate() {
    if(dir == 0) dir = 3;
    else if(dir == 1) dir = 0;
    else if(dir == 2) dir = 1;
    else dir = 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    cin >> x >> y >> dir;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int answer = 0;

    while(true) {
        bool flag = false;
        int tmpdir;
        if(!visited[x][y] && graph[x][y] == 0) {
            answer++;
            visited[x][y] = true;
            continue;
        }
        else {
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                if(graph[nx][ny] == 0 && !visited[nx][ny]) {
                    flag = true;
                }
            }
        }

        if(!flag) {
            tmpdir = robotback();
            int nx = x + dx[tmpdir];
            int ny = y + dy[tmpdir];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M ||graph[nx][ny] == 1) {
                break;
            }
            else {
                x = nx;
                y = ny;
            }
        }
        else {
            rotate();
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M || graph[nx][ny] == 1) continue;

            if(graph[nx][ny] == 0 && !visited[nx][ny]) {
                x = nx;
                y = ny;
            }
        }
    }

    cout << answer;
}