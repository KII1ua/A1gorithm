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

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, result;
int graph[101][101];

bool graphcheck(int h, int w, int x, int y) {
    for(int i = x; i < x + h; i++) {
        for(int j = y; j < y + w; j++) {
            if(!graph[i][j]) return false;
        }
    }
    return true;
}

bool check(int x, int y) {
    for(int i = 0; i <= 100 - x; i++) {
        for(int j = 0; j <= 100 - y; j++) {
            if(graphcheck(x, y, i, j)) return true;       // 크기, 좌표
        }
    }
    return false;
}

void solve() {
    for(int i = 1; i < 101; i++) {
        for(int j = 1; j < 101; j++) {
            if(check(i, j)) {
                result = max(result, i * j);
            }
        }
    }
    cout << result;
}

void input() {
    cin >> N;

    for(int k = 0; k < N; k++) {
        int a, b;
        cin >> a >> b;

        for(int i = b; i < b + 10; i++) {
            for(int j = a; j < a + 10; j++) {
                graph[i][j] = 1;
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