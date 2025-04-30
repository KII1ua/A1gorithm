#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int MOD = 1000000007;
int M;
ll ans;

ll powed(ll a, ll b) {
    ll result = 1;
    a %= MOD;

    while(b) {
        if(b % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

void input() {
    cin >> M;

    while(M--) {
        ll a, b;
        cin >> b >> a;
        ll g = gcd(a, b);
        b /= g;
        a /= g;
        ans += a * powed(b, MOD-2) % MOD;
        ans %= MOD;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}