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
vector<vector<int>> v(5001);

void solve() {
    for(int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end());
    }

    int answer = 0;

    for(int i = 1;  i <= N; i++) {
        if(v[i].size() == 0) continue;
        int min_dist = MAX;
        for(int j = 1; j < v[i].size(); j++) {
            int tmp = v[i][j] - v[i][j-1];

            answer += tmp;
            min_dist = min(min_dist, tmp);
        }
        answer += min_dist;
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
