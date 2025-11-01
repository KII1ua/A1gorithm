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
int N, M;
int arr[301][21];
int dp[21][301];
pii par[21][301];

void Print() {
    for(int i = 0; i <= M; i++) {
        for(int j = 0; j <= N; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i <= M; i++) {
        for(int j = 0; j <= N; j++) {
            cout << par[i][j].first << " " << par[i][j].second << " ";
        }
        cout << endl;
    }
}

void solve() {

    for(int i = 1; i <= M; i++) {       // i번까지 고려할 기업 번호
        for(int j = 0; j <= N; j++) {   // j원까지 투자
            for(int k = 0; k <= j; k++) {       // i번기업에 k원 투자
                if(dp[i][j] < dp[i-1][j-k] + arr[k][i]) {
                    dp[i][j] = dp[i-1][j-k] + arr[k][i];
                    par[i][j] = {i-1, j-k};
                }
            }
        }
    }

    cout << dp[M][N] << endl;

    vector<int> v;
    int i = M, j = N;

    while(i > 0 && j > 0) {
        int ni = par[i][j].first;
        int nj = par[i][j].second;
        v.push_back(j - nj);
        i = ni;
        j = nj;
    }

    for(int i = M-1; i >= 0; i--) {
        cout << v[i] << " ";
    }
}

void input() {
    cin >> N >> M;
    int x;

    for(int i = 1; i <= N; i++) {
        cin >> x;
        for(int j = 1; j <= M; j++) {
            int a;
            cin >> a;
            arr[x][j] = a;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
