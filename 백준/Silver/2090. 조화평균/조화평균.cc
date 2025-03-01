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
ll down[10];
ll up[10];

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> down[i];
    }
}

void solution() {
    ll num = 1;
    ll den = 0;

    memset(up, 1, sizeof(up));

    for(int i = 0; i < N; i++) {
        num *= down[i];
    }

    for(int i = 0; i < N; i++) {
        up[i] = num / down[i];
    }

    for(int i = 0; i < N; i++) {
        den += up[i];
    }

    ll res = gcd(den, num);

    den = den / res;
    num = num / res;

    cout << num << "/" << den;
}

void solve() {
    input();
    solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}
