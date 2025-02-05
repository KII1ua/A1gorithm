// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int arr[8][8];
bool visited[9][8][8];

bool bfs() {
    queue<pair<int, pair<int, int>>> q;

    q.push({0, {7, 0}});
    visited[0][7][0] = true;

    while(!q.empty()) {
        int xx = q.front().second.first;
        int yy = q.front().second.second;
        int time = q.front().first;
        q.pop();

        if(xx == 0) return true;

        for(int i = 0; i <= 8; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            int nt = time + 1;

            if(nt >= 8) {
                return true;
            }

            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;

            if(nx - time >= 0 && arr[nx - time][ny] == -1) continue; // 가려는 칸에 벽이 있을 경우

            if(nx - time -1 >= 0 && arr[nx - time - 1][ny] == -1) continue;

            if(visited[nt][nx][ny] == false) {
                visited[nt][nx][ny] = true;
                q.push({nt, {nx, ny}});
            }
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;

    for(int i = 0; i < 8; i++) {
        getline(cin, s);
        for(int j = 0; j < 8; j++) {
            if(s[j] == '.') {
                arr[i][j] = 0;
            }
            else if(s[j] == '#') {
                arr[i][j] = -1;
            }
        }
    }

    arr[7][0] = 1;

    if(bfs()) {
        cout << 1;
        return 0;
    }

    cout << 0;
}
