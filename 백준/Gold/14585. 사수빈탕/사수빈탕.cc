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
int N, M;
bool arr[301][301];
int dp[301][301];

int solve(int x, int y) {
    if(x >= 301 || y >= 301) return 0;

    int &ret = dp[x][y];
    if(ret != -1) return ret;
    int cnt = (arr[x][y])? max(0, M - x - y) : 0;
    ret = max(solve(x+1, y), solve(x, y+1)) + cnt;
    return ret;
}

void input() {
    cin >> N >> M;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
    }

    cout << solve(0, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
