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
int N, d;
vector<pii> v;
priority_queue<pii, vector<pii>, greater<pii>> pq;

bool compare(pii a, pii b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }

    return a.second < b.second;
}

void Print() {
    for(auto it : v) {
        cout << it.first << " " << it.second << endl;
    }
}

void solve() {
    sort(v.begin(), v.end(), compare);

    int answer = 0;

    for(int i = 0; i < N; i++) {
        int road = v[i].second - d;
        pq.push({v[i].first, v[i].second});

        if(!pq.empty() && road > pq.top().first) pq.pop();

        answer = max(answer, (int)pq.size());
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        if(a > b) {
            v.push_back({b, a});
        }
        else v.push_back({a, b});
    }

    cin >> d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
