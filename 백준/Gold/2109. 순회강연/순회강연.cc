// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
//priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
vector<pii> v;
bool visited[10001];
int N;

bool compare(pii a, pii b) {
    return a.first > b.first;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back(make_pair(p, d));
    }
}

void solve() {
    int cost = 0;

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < N; i++) {
        int pay = v[i].first;
        int idx = v[i].second;

        if(!visited[idx]) {
            visited[idx] = true;
            cost += pay;
        }
        else {
            for(int j = idx; j > 0; j--) {
                if(!visited[j]) {
                    visited[j] = true;
                    cost += pay;
                    break;
                }
            }
        }
    }

    cout << cost;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
