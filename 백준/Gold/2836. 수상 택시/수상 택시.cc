#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
ll dist;
vector<pair<ll, ll>> v;

void solve() {
    sort(v.begin(), v.end());

    ll left = 0;
    ll right = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].first > right) {
            dist += (right - left) * 2;
            left = v[i].first;
            right = v[i].second;
        }
        else {
            right = max(right, v[i].second);
        }
    }
    dist += (right - left) * 2;

    cout << M + dist;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b) {
            v.push_back(make_pair(b, a));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
