// baekjoon 24230
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, cnt;
vector<int> color;
vector<int> graph[200001];
int visited[200001];

void dfs(int x, int y) {            // 루트 노드, 자식 노드
    visited[y] = 1;

    if(color[x] != color[y]) {
        cnt++;
    }

    for(int i = 0; i < graph[y].size(); i++) {      // 자식노드에 연결된 간선 정보
        if (!visited[graph[y][i]]) {
            dfs(y, graph[y][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int a, x, y;

    cin >> N;

    color.push_back(0);

    for(int i = 0; i < N; i++) {
        cin >> a;
        color.push_back(a);
    }

    for(int j = 0; j < N-1; j++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(0, 1);      // 부모노드, 자식노드

    cout << cnt;
}