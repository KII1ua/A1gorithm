#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e14 + 1;
const int MAX = 502;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
ll N, X;
ll lens[51], patty[51];

ll func(int lv, ll x) {
    if(lv == 0) return 1;

    if(x == 1) return 0;
    else if(x <= 1 + lens[lv-1]) {
        return func(lv-1, x-1);
    }
    else if(x == 1 + lens[lv-1] + 1) {
        return patty[lv-1] + 1;
    }
    else if(x <= 1 + lens[lv-1] + 1 + lens[lv-1]) {
        return patty[lv-1] + 1 + func(lv-1, x - (lens[lv-1] + 2));
    }
    else {
        return patty[lv];
    }
}

void solve() {
    lens[0] = 1;
    patty[0] = 1;

    for(int i = 1; i <= N; i++) {
        lens[i] = lens[i-1] * 2 + 3;
        patty[i] = patty[i-1] * 2 + 1;
    }

    cout << func(N, X);
}

void input() {
    cin >> N >> X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}