#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
bool graph[101][101];
int visited[101];

void bfs() {
    queue<int> q;
    vector<int> a, b;

    for(int i = 1; i <= N; i++) {
        if(visited[i] != 0) continue;
        q.push(i);
        visited[i] = 1;

        while(!q.empty()) {
            int Node = q.front();
            q.pop();

            for(int j = 1; j <= N; j++) {
                if(visited[j] != 0) continue;
                if(!graph[Node][j]) {
                    q.push(j);
                    visited[j] = visited[Node] * -1;
                }
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(visited[i] == 1) {
            a.push_back(i);
        }
        else b.push_back(i);
    }

    cout << a.size() << endl;
    for(auto it : a) cout << it << " ";
    cout << endl << b.size() << endl;
    for(auto it : b) cout << it << " ";
}

void solve() {
    bfs();
}

void input() {
    cin >> N;

    memset(graph, 1, sizeof(graph));

    for(int i = 1; i<= N; i++) {
        int M;
        cin >> M;
        for(int j = 0; j < M; j++) {
            int a;
            cin >> a;
            graph[i][a] = false;
            graph[a][i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
