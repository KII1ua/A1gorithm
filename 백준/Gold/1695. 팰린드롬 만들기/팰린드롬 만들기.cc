#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 123457;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[5001];
int dp[5001][5001];

int func(int s, int e) {
    if(s > e) return 0;
    int &ret = dp[s][e];

    if(ret != MAX) return ret;

    ret = 0;

    if(arr[s] == arr[e]) {
        ret = func(s+1, e-1);
    }
    else {
        ret = min(func(s, e-1), func(s+1, e)) + 1;
    }

    return ret;
}

void solve() {
    cout << func(0, N-1);
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j] = MAX;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}