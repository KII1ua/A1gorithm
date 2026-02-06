#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 2e9;
const int MAX = 1001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int dp[MAX][MAX];
vector<int> man, women;

int func(int x, int y) {
    if(x == N) return 0;

    if(y == M) return INF;

    int &ret = dp[x][y];

    if(ret != -1) return ret;

    ret = INF;
    ret = min({ret, func(x+1, y+1) + abs(man[x] - women[y]), func(x, y+1)});

    return ret;
}

void solve() {
    if(N > M) {
        swap(man, women);
        int tmp = N;
        N = M;
        M = tmp;
    }
    sort(man.begin(), man.end());
    sort(women.begin(), women.end());

    memset(dp, -1, sizeof(dp));
    cout << func(0, 0);
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        man.push_back(a);
    }

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        women.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}