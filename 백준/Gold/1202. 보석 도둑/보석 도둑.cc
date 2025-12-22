#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, K;
vector<pii> v;
priority_queue<int> pq;
int arr[300001];

bool compare(pii a, pii b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

void Print() {
    for(auto it : v) {
        cout << it.first << " " << it.second << endl;
    }

    for(int i = 0; i < K; i++) {
        cout << arr[i] << " ";
    }
}

void solve() {
    sort(v.begin(), v.end(), compare);
    sort(arr, arr+K);

    int idx = 0;
    ll answer = 0;

    for(int i = 0; i < K; i++) {
        int bagsize = arr[i];

        while(idx < N) {
            int weight = v[idx].first;
            int cost = v[idx].second;

            if(weight <= bagsize) {
                pq.push(cost);
                idx++;
            }
            else break;
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
        v.push_back({a, b});
    }

    for(int i = 0; i < K; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}