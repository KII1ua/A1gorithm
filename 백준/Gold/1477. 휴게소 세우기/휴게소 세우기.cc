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
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, 1};
int N, M, L;
priority_queue<int> pq;
vector<int> v;

void Print() {
    for(auto it : v) {
        cout << it << endl;
    }
}

void solve() {
    v.push_back(0);
    v.push_back(L);
    sort(v.begin(), v.end());

    vector<int> diff;
    for(int i = 1; i < v.size(); i++) {
        diff.push_back(v[i]-1 - v[i-1]);
    }

    sort(diff.begin(), diff.end());

    int lo = 0;
    int hi = 1000;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        int cnt = 0;
        for(int i = 0; i < diff.size(); i++) {
            cnt += diff[i] / mid;
        }

        if(cnt <= M) {
            hi = mid;
        }
        else lo = mid;
    }

    cout << lo + 1;
}

void input() {
    cin >> N >> M >> L;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
