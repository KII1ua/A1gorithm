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

    for(int i = 1; i <= N; i++) {
        if(v[i].size() == 0) continue;

        for(int j = 0; j < v[i].size(); j++) {
            int pos = v[i][j];
            int min_dist = MAX;

            if(j < v[i].size() - 1) {     // 오른쪽 탐색
                int dst = abs(pos - v[i][j+1]);
                min_dist = min(dst, min_dist);
            }

            if(j != 0) {
                int dst = pos - v[i][j-1];
                min_dist = min(dst, min_dist);
            }

            answer += min_dist;
        }
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
