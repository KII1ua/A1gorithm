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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int T, N;
int cnt = 1;

void solve(vector<ll> &arr, map<ll, ll> &m) {
    for(auto &it : arr) {
        if(m[it] == 0) continue;
        ll tmp = it * 4 / 3;

        if(m[tmp] > 0) {
            m[it]--;
            m[tmp]--;
            cout << it << " ";
        }
    }
    cout << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        vector<ll> v(2 * N);
        map<ll, ll> m;

        for(auto &it : v) {
            cin >> it;
            m[it]++;
        }

        cout << "Case #" << cnt++ << ": ";
        solve(v, m);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
