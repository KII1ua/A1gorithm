#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 1000001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
ll N, K;

ll pw(ll a, ll b) {
    ll ans = 1;

    while(b != 0) {
        if(b % 2 == 1) {        // 홀수
            ans *= a;
        }
        a = a * a;
        b >>= 1;
    }

    return ans;
}

void solve() {
    ll answer = 1;

    ll temp = K;

    for(ll i = 2; i * i <= temp; i++) {
        ll a = 0, b = 0;

        while(K % i == 0) {
            a++;
            K /= i;
        }

        for(ll j = i; j <= N; j *= i) {
            b += N / j;
        }

        answer *= pw(i, min(a, b));
    }

    if(K > 1) {     // K가 소수일 경우
        if(N >= K) {        // N!에 포함될 경우
            answer *= K;
        }
    }

    cout << answer << endl;
}

void input() {
    while(cin >> N >> K) {
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}