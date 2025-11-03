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
int arr[1001];
int dp[1001];

int func(int x, int milk, int status) {
    if(x >= N) return 0;
    int &ret = dp[x];

    if(ret != -1) return ret;
    ret = 0;

    if(milk == status) {
        if(status == 0) {
            ret = func(x+1, arr[x+1], 1) + 1;
        }
        else if(status == 1) {
            ret = func(x+1, arr[x+1], 2) + 1;
        }
        else ret = func(x+1, arr[x+1], 0) + 1;
    }
    else ret = func(x+1, arr[x+1], status);

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cout << func(0, arr[0], 0);
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
