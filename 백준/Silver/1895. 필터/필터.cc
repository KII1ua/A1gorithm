#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int R, C, T, result;
int graph[41][41];

void check(int x, int y) {
    vector<int> v;

    for(int i = x; i < x + 3; i++) {
        for(int j = y; j < y + 3; j++) {
            v.push_back(graph[i][j]);
        }
    }

    sort(v.begin(), v.end());

    if(v[4] >= T) {
        result++;
    }
}

void solve() {
    for(int i = 0; i <= R-3; i++) {
        for(int j = 0; j <= C-3; j++) {
            check(i, j);
        }
    }

    cout << result;
}

void input() {
    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> graph[i][j];
        }
    }
    cin >> T;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}