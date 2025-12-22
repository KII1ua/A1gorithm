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

void Print() {
    for(auto it : v) {
        cout << it.first << " " << it.second << endl;
    }
}

void solve() {
    sort(v.begin(), v.end());

    if(v[0].first > 301) {
        cout << 0;
        return;
    }
    int end_time = 301;
    int i = 0;
    int cnt = 0;

    while(end_time <= 1130) {
        int new_time = 0;

        for(; i < N; i++) {
            if(v[i].first >= v[i].second) continue;

            if(end_time >= v[i].first) {
                if(new_time < v[i].second) {
                    new_time = v[i].second;
                }
            }
            else break;

        }
        if(end_time == 0) {
            break;
        }
        else {
            end_time = new_time;
            cnt++;
        }
    }

    if(end_time > 1130) {
        cout << cnt;
        return;
    }
    else {
        cout << 0;
        return;
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({a * 100 + b, c * 100 + d});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}