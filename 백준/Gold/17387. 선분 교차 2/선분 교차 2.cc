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

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
pair<ll, ll> x1, x2, x3, x4;

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    ll clock = ((b.first - a.first) * (c.second - a.second)) - ((b.second - a.second) * (c.first - a.first));

    if(clock > 0) return 1;     // 반시계
    if(clock < 0) return -1;    // 시계
    else return 0;              // 일직선
}

void solve() {
    int ccw1 = ccw(x1, x2, x3);
    int ccw2 = ccw(x1, x2, x4);
    int ccw3 = ccw(x3, x4, x1);
    int ccw4 = ccw(x3, x4, x2);

    if(ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) {
        cout << 1;
        return;
    }
    else if(ccw1 == 0 && ccw2 == 0) {
        if(x1 > x2) swap(x1, x2);

        if(x3 > x4) swap(x3, x4);

        if(x1 <= x4 && x3 <= x2) {
            cout << 1;
        }
        else cout << 0;
    }
    else if((ccw1 * ccw2 == 0) && (ccw3 * ccw4) <= 0 || (ccw3 * ccw4) == 0 && (ccw1 * ccw2) <= 0) {
        cout << 1;
    }
    else cout << 0;
}

void input() {
    cin >> x1.first >> x1.second >> x2.first >> x2.second >> x3.first >> x3.second >> x4.first >> x4.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
