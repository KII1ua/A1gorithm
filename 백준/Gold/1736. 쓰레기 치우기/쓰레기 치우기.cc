#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0};
int dy[] = {0, 1};
int N, M, trash, answer;
int graph[101][101];

void func(int x, int y) {

    for(int i = x; i < N; i++) {
        for(int j = y; j < M; j++) {
            if(graph[i][j]) {
                trash--;
                graph[i][j] = 0;
                func(i, j);
                return;
            }
        }
    }
}

void solve() {
    while(trash > 0) {
        func(0, 0);
        answer++;
    }

    cout << answer;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 1) {
                trash++;
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