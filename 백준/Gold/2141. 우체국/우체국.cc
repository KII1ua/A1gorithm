#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<pii> v;
ll dp[100001];

void Print() {
    for(auto it : v) {
        cout << it.first << " " << it.second << endl;
    }
}

void solve() {
    sort(v.begin(), v.end());


    ll people = 0;
    for(int i = 0; i < N; i++) {
        people += v[i].second;
    }

    people = (people + 1) / 2;

    ll tmp = 0;
    for(int i = 0; i < N; i++) {
        tmp += v[i].second;

        if(people <= tmp) {
            cout << v[i].first;
            return;
        }
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}