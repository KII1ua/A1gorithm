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

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, K;
vector<pii> jewel;
int bag[300001];
priority_queue<int> pq;

bool compare(pii a, pii b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

void solve() {
    sort(jewel.begin(), jewel.end(), compare);
    sort(bag, bag+K);

    ll answer = 0;
    int idx = 0;
    for(int i = 0; i < K; i++) {
        int bag_size = bag[i];

        while(idx < N) {
            int weight = jewel[idx].first;
            int cost = jewel[idx].second;

            if(weight <= bag_size) {
                pq.push(cost);
                idx++;
            }
            else {
                break;
            }
        }

        if(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
}

void input() {
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        jewel.push_back({a, b});
    }

    for(int i = 0; i < K; i++) {
        cin >> bag[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
