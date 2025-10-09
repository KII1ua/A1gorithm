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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, K, S;
int graph[401][401];

void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i = 0; i < S; i++) {
        int a, b;
        cin >> a >> b;

        if(graph[a][b] == graph[b][a]) {
            cout << 0 << endl;
        }
        else if(graph[a][b] < graph[b][a]) {
            cout << -1 << endl;
        }
        else cout << 1 << endl;
    }
}

void Init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;
            graph[i][j] = MAX;
        }
    }
}

void input() {
    cin >> N >> K;

    Init();

    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    cin >> S;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
