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

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
int N;
vector<pii> v;
vector<int> vec;

void solve() {
    sort(vec.begin(), vec.end());

    if(N % 2 == 0) {
        cout << abs(vec[N / 2 -1] - vec[N / 2])+1;
    }
    else {
        cout << 1;
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        vec.push_back({b - a});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
