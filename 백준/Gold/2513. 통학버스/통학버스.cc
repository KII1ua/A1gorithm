#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, K, S;
vector<pii> v1, v2;

bool compare(pii a, pii b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }

    return a.first > b.first;
}

int func(vector<pii> &arr) {
    int idx = 0;
    int dist = 0;

    while(idx < arr.size()) {
        if(arr[idx].second <= 0) {
            idx++;
            continue;
        }

        dist += arr[idx].first * 2;

        int capacity = K;
        int temp_idx = idx;

        while(temp_idx < arr.size() && capacity > 0) {
            if(arr[temp_idx].second <= capacity) {
                capacity -= arr[temp_idx].second;
                arr[temp_idx].second = 0;
                temp_idx++;
            }
            else {
                arr[temp_idx].second -= capacity;
                capacity = 0;
            }
        }
    }

    return dist;
}

void solve() {
    int answer = 0;
    if(!v1.empty()) {
        sort(v1.begin(), v1.end(), compare);
        answer += func(v1);
    }

    if(!v2.empty()) {
        sort(v2.begin(), v2.end(), compare);
        answer += func(v2);
    }

    cout << answer;
}

void input() {
    cin >> N >> K >> S;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        if(S > a) {
            v1.push_back({abs(S - a), b});
        }
        else {
            v2.push_back({abs(S - a), b});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}