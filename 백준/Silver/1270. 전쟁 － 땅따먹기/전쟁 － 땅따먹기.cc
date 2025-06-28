#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e10

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N;
map<ll, ll> m;

void solve(int stand) {
    ll who = -MAX;
    ll cnt = -MAX;
    vector<pair<ll, ll>> v;

    for(auto it : m) {
        ll army = it.first;
        ll count = it.second;

        if(cnt < count && count > stand / 2) {
            v.clear();
            who = army;
            cnt = count;
            v.push_back({who, cnt});
        }
        else {
            if(cnt == count) {
                v.push_back({army, count});
            }
        }
    }

    if(v.size() == 1) {
        cout << v[0].first << endl;
    }
    else {
        cout << "SYJKGW" << endl;
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        m.clear();
        int T;
        cin >> T;
        for(int j = 0; j < T; j++) {
            ll a;
            cin >> a;
            m[a]++;
        }
        solve(T);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}