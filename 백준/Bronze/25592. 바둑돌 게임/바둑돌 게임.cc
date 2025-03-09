// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N;

void input() {
    cin >> N;
}

void solve() {
    int cnt = 0;

    while(N >= cnt) {
        N -= cnt;
        cnt++;
    }

    if(cnt % 2 != 0) {
        cout << cnt - N;
    }
    else {
        cout << 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}