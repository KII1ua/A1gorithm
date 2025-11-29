#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int A, B, C;
string X, Y;
int dp[3001][3001];

int func(int idx1, int idx2) {
    if(idx1 == X.size()) return (Y.size() - idx2) * B;
    if(idx2 == Y.size()) return (X.size() - idx1) * B;
    int &ret = dp[idx1][idx2];
    if(ret != -MAX) return ret;

    ret = max(func(idx1+1, idx2), func(idx1, idx2+1)) + B;
    ret = max((X[idx1] == Y[idx2]? A : C) + func(idx1+1, idx2+1), ret);

    return ret;
}

void solve() {
    cout << func(0, 0);
}

void input() {
    cin >> A >> B >> C >> X >> Y;
    for(int i = 0; i < X.size(); i++) {
        for(int j = 0; j < Y.size(); j++) {
            dp[i][j] = -MAX;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}