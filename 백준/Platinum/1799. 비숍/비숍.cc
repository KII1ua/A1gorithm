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

//int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
//int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
//int dx[] = {1, 1};
//int dy[] = {-1, 1};
int dx[] = {1, -1, -1, 1};
int dy[] = {-1, 1, -1, 1};
int N;
int graph[11][11], colorgraph[11][11], answer[2];      // graph -> 원본 그래프(둘 수 있는지, 없는지), colorgraph -> 흰색, 검은색 나눠서 생각
bool Select[11][11];    // 비숍을 두었는지 여부 배열

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << colorgraph[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        while(nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if(Select[nx][ny]) {
                return false;
            }
            nx += dx[i];
            ny += dy[i];
        }
    }
    return true;
}

void dfs(int idx, int cnt, int color) {
    if(answer[color] < cnt) answer[color] = cnt;

    for(int i = idx+1; i < N * N; i++) {
        int x = i / N;
        int y = i % N;

        if(graph[x][y] == 0 || colorgraph[x][y] != color || !check(x,y)) continue;
        Select[x][y] = true;
        dfs(i, cnt+1, color);
        Select[x][y] = false;
    }
}

void solve() {
    dfs(-1, 0, 0);
    dfs(-1, 0, 1);

    cout << answer[0] + answer[1];
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];     // 0이 흰색 1이 검은색

            if(i % 2 == 0) {
                if(j % 2 == 0) {
                    colorgraph[i][j] = 1;
                }
                else {
                    colorgraph[i][j] = 0;
                }
            }
            else {
                if(j % 2 == 0) {
                    colorgraph[i][j] = 0;
                }
                else {
                    colorgraph[i][j] = 1;
                }
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