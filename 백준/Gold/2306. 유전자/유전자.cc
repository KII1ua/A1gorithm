#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 20001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dp[501][501];
string s;

int func(int l, int r) {
    if(l >= r) return 0;

    int &ret = dp[l][r];

    if(ret != -1) return ret;

    for(int i = l; i < r; i++) {
        ret = max(ret, func(l, i) + func(i+1, r));
    }

    if((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c')) {
        ret = max(ret, func(l+1, r-1) + 2);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;

    memset(dp, -1, sizeof(dp));

    cout << func(0, s.size()-1);
}