#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
int queen[16];
int cnt;

bool can(int x) {
    for(int i = 0; i < x; i++) {
        if(queen[i] == queen[x] || x - i == abs(queen[x] - queen[i])) return false;
    }
    return true;
}

void dfs(int x) {
    if(x == N) {
        cnt++;
        return;
    }

    for(int i = 0; i < N; i++) {
        queen[x] = i;

        if(can(x)) {
            dfs(x+1);
        }
    }
}

void solve() {
    dfs(0);

    cout << cnt;
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}