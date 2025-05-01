#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int R, C, T, result;
int graph[1001][51][51];
pii front, behind;

void operate(int time) {        // 에어컨 작동
    // 우, 상, 좌, 하
    int xx[] = {0, -1, 0, 1};
    int yy[] = {1, 0, -1, 0};

    int x = front.first;
    int y = 0;
    int prev = 0;
    int idx = 0;

    while(true) {
        int nx = x + xx[idx];
        int ny = y + yy[idx];

        if(nx >= R || ny >= C || nx < 0 || ny < 0) {
            idx++;
            continue;
        }

        if(nx == front.first && ny == 0) {
            break;
        }

        int cur = graph[time][nx][ny];
        graph[time][nx][ny] = prev;
        prev = cur;
        x = nx, y = ny;
    }

    int xx1[] = {0, 1, 0, -1};
    int yy1[] = {1, 0, -1, 0};

    x = behind.first, y = 0;
    idx = 0;
    prev = 0;

    while(true) {
        int nx = x + xx1[idx];
        int ny = y + yy1[idx];

        if(nx >= R || ny >= C || nx < 0 || ny < 0) {
            idx++;
            continue;
        }

        if(nx == behind.first && ny == 0) {
            break;
        }

        int cur = graph[time][nx][ny];
        graph[time][nx][ny] = prev;
        prev = cur;
        x = nx, y = ny;
    }
}

void diffusion(int time) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(graph[time-1][i][j] == -1) {
                graph[time][i][j] = -1;
                continue;
            }

            if(graph[time-1][i][j] >= 5) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {        // 상 하 좌 우 탐색
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
                        if (graph[time-1][nx][ny] != -1) {
                            graph[time][nx][ny] += graph[time-1][i][j] / 5;
                            cnt++;
                        }
                    }
                }
                graph[time][i][j] += graph[time-1][i][j] - (graph[time-1][i][j] / 5 * cnt);
            }
            else {
                graph[time][i][j] += graph[time-1][i][j];
            }
        }
    }
}

void solve() {
    for(int i = 0; i < R; i++) {
        if(graph[0][i][0] == -1) {
            front.first = i;
            front.second = 0;
            behind.first = i+1;
            behind.second = 0;
            break;
        }
    }

    for(int i = 1; i <= T; i++) {
        diffusion(i);
        operate(i);
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(graph[T][i][j] != -1) {
                result += graph[T][i][j];
            }
        }
    }

    cout << result;
}

void input() {
    cin >> R >> C >> T;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> graph[0][i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}