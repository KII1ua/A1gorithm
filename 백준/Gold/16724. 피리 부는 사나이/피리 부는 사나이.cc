#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    string s;
    vector<int> v;
};

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int N, M;
char graph[1001][1001];
int dp[1001][1001];
int cnt;

int dfs(int x, int y) {
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = cnt;

    if(graph[x][y] == 'U') {
        dp[x][y] = dfs(x-1, y);
    }
    else if(graph[x][y] == 'D') {
        dp[x][y] = dfs(x+1, y);
    }
    else if(graph[x][y] == 'L') {
       dp[x][y] = dfs(x, y-1);
    }
    else dp[x][y] = dfs(x, y+1);

    return dp[x][y];
}

void solve() {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(dp[i][j] == -1) {
                dfs(i, j);
                cnt++;
            }
        }
    }

    set<int> st;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            st.insert(dp[i][j]);
        }
    }

    cout << st.size();

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << cnt;
}

void Init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dp[i][j] = -1;
        }
    }
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    Init();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();

    return 0;
}