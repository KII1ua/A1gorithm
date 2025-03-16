#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string s;

void solve() {
    ll ans = 0, mul = 1, mod = 1e9 + 7;

    for(int i = 0; i < s.size(); i++) {
        if (s[i] == 'O')
            ans += mul;
        ans %= mod;
        mul *= 2;
        mul %= mod;
    }

    cout << ans;
}

void input() {
    cin >> s;
    solve();
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
