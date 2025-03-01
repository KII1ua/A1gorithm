// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, L;
vector<pair<int, pair<int, int>>> v;

void input() {
    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        int l, d;
        cin >> l >> d;
        if(d == 0) v.push_back({0, {d, l}});
        else v.push_back({1, {L-l-1, L-1}});
    }
}

void solve() {
    int loc = 0;
    int time = 0;

    if(N == 1) {
        cout << time;
        return;
    }

    while(true) {
        bool visited = false;
        for(int i = v[loc].second.first; i <= v[loc].second.second; i++) {
            if(i >= v[loc+1].second.first && i <= v[loc+1].second.second) {
                visited = true;
                break;
            }
        }
        if(visited) {
            loc++;
        }
        else {
            time++;
            for(int i = loc; i < N; i++) {
                if(v[i].first) {
                    v[i].second.first--;
                    v[i].second.second--;
                } else {
                    v[i].second.first++;
                    v[i].second.second++;
                }
            }
        }

        if(loc == N-1) {
            cout << time;
            return;
        }
    }
}

void solution() {
    input();
    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solution();
}
