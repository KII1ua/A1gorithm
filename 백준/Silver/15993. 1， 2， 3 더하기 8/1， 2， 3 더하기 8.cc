// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int T;
vector<pair<ll, ll>> v(100001);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    v[1] = make_pair(1, 0);
    v[2] = make_pair(1, 1);
    v[3] = make_pair(2, 2);

    for(int i = 4; i <= 100000; i++) {
        v[i] = {(v[i-1].second + v[i-2].second + v[i-3].second) % 1000000009, (v[i-1].first + v[i-2].first + v[i-3].first) % 1000000009};
    }

    for(int i = 0; i < T; i++) {
        int a;
        cin >> a;
        cout << v[a].first << " " << v[a].second << endl;
    }
}
