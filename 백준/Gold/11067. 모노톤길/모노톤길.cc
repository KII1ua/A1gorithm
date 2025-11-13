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
int T, N, M;
int arr[11];
vector<pii> answer;

void Print(vector<vector<int>> &v) {
    for(int i = 0; i <= 100000; i++) {
        if(v[i].empty()) continue;
        for(int j = 0; j < v[i].size(); j++) {
            cout << i << " " << v[i][j] << endl;
        }
    }
}

void solve(vector<vector<int>> &v) {
    int y = 0;

    for(int i = 0; i <= 100000; i++) {
        if(v[i].empty()) continue;
        sort(v[i].begin(), v[i].end(), [y](int a, int b){
            return abs(a - y) < abs(b - y);
        });
        y = v[i][v[i].size()-1];
    }

    for(int i = 0; i <= 100000; i++) {
        if(v[i].empty()) continue;
        for(int j = 0; j < v[i].size(); j++) {
            answer.push_back({i, v[i][j]});
        }
    }

    for(int i = 0; i < M; i++) {
        cout << answer[arr[i]-1].first << " " << answer[arr[i]-1].second << endl;
    }
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        vector<vector<int>> v(100001);
        answer.clear();

        for(int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }

        cin >> M;

        for(int i = 0; i < M; i++) {
            cin >> arr[i];
        }

        solve(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
