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
int dx[] = {0, -1};
int dy[] = {-1, 0};
int N;
vector<pair<double, int>> v;

bool compare(pair<double, int> a, pair<double, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }

    return a.first < b.first;
}

void solve() {
    sort(v.begin(), v.end(), compare);

    for(auto it : v) {
        cout << it.second << " ";
    }
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        double tmp = (double)a / b;
        v.push_back({tmp, i});
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
