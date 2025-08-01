#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    string s;
    vector<int> v;
};

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int N, M;
vector<pii> v;

bool compare(pii a, pii b) {
    return a.second > b.second;
    if(a.second == b.second) return a.first > b.first;
}

void solve() {
    sort(v.begin(), v.end(), compare);

    // for(auto it : v) {
    //     cout << it.first << " " << it.second;
    //     cout << endl;
    // }
    int cnt = 0;
    ll result = 0;
    for(auto it : v) {
        ll first_taste = it.first;
        ll supple = it.second;

        ll tmp = first_taste + (supple * (M-1-cnt));
        result += tmp;
        cnt++;
    }

    cout << result;
}

void input() {
    cin >> N >> M;

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