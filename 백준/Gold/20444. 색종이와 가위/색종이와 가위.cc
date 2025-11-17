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
ll N, K;

/*
    N번 자르면 N+1개의 색종이가 나옴
*/

void solve() {
    ll lo = -1;
    ll hi = N+1;

    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;

        ll paper = (mid + 1) * (N - mid + 1);

        if (paper == K) {
            cout << "YES";
            return;
        }

        if (paper > K) {
            hi = mid;
        } else lo = mid;
    }

    cout << "NO";
}

void input() {
    cin >> N >> K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
