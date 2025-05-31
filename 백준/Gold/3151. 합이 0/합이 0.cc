#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int n;
vector<int> v;
const int N = 50000;
int cnt[N * 3];

void solve() {
    sort(v.begin(), v.end());
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ll val = v[i] + v[j];
            ll res = cnt[-val + N];

            if(-val == v[i]) res--;
            if(-val == v[j]) res--;
            ans += res;
        }
    }
    cout << ans / 3;
}

void input() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        cnt[v[i] + N]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}