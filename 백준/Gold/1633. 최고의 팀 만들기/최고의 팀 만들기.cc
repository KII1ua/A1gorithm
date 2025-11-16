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
vector<pii> v;
int dp[1001][16][16];

void Init() {
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 16; j++) {
            for(int k = 0; k < 16; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
}

int func(int idx, int w, int b) {

    if(idx == v.size()) {
        return (w == 0 && b == 0)? 0 : -MAX;
    }
    int &ret = dp[idx][w][b];

    if(ret != -1) {
        return ret;
    }

    ret = func(idx+1, w, b);

    if(w > 0) {
        ret = max(ret, func(idx+1, w-1, b) + v[idx].first);
    }

    if(b > 0) {
        ret = max(ret, func(idx+1, w, b-1) + v[idx].second);
    }

    return ret;
}

void solve() {
    Init();

    cout << func(0, 15, 15);
}


void input() {
    int x, y;

    while(cin >> x >> y) {
        v.push_back({x, y});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
