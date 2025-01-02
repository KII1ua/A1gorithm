// baekjoon 28706
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int R, C, answer;
char graph[21][21];
bool visited[26];       // 알파벳 별 방문체크

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

void dfs(int x, int y, int dist) {
    bool cango = false;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
        char nextalpha = graph[nx][ny];
        if(visited[nextalpha - 'A']) continue;

        cango = true;
        visited[nextalpha - 'A'] = true;
        dfs(nx, ny, dist+1);
        visited[nextalpha - 'A'] = false;
    }

    if(!cango) {
        answer = max(answer, dist);
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> graph[i][j];
        }
    }

    char nextalpha = graph[0][0];
    visited[nextalpha - 'A'] = true;        // 첫번째 0, 0 방문지점은 무조건 밟고 가야하기 때문에 방문체크

    dfs(0, 0, 1);

    cout << answer;
}