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
int dx[] = {1, 0};
int dy[] = {0, 1};
int N, M, K;
int arr[30001];
int unf[30001];
halloween graph[30001];
vector<pii> v;
int dp[30001][3000];

int Find(int a) {
    if(a == unf[a]) return a;
    return unf[a] = Find(unf[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) unf[a] = b;
    else unf[b] = a;
}

bool isUnion(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void Print() {
    for(int i = 1; i <= N; i++) {
        cout << graph[i].cnt << " " << graph[i].score << endl;
    }

    for(auto it : v) {
        cout << it.first << " " << it.second << endl;
    }
}

void solve() {
    for(int i = 1; i <= N; i++) {
        int idx = Find(i);
        graph[idx].cnt++;
        graph[idx].score += arr[i];
    }

    for(int i = 1; i <= N; i++) {
        if(graph[i].cnt > 0) {
            v.push_back({graph[i].cnt, graph[i].score});
        }
    }

    int n = v.size();
    int answer = 0;

    for(int i = 1; i <= n; i++) {
        int weight = v[i-1].first;
        int cost = v[i-1].second;
        for(int j = 1; j < K; j++) {
            dp[i][j] = dp[i-1][j];

            if(j >= weight) {
                dp[i][j] = max(dp[i][j], cost + dp[i-1][j-weight]);
                answer = max(dp[i][j], answer);
            }
        }
    }

    cout << answer << endl;
//
//    for(int i = 1; i <= n; i++) {
//        for(int j = 1; j < K; j++) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
}

void Init() {
    for(int i = 1; i <= N; i++) {
        unf[i] = i;
    }
}

void input() {
    cin >> N >> M >> K;

    Init();

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if(!isUnion(a, b)) {
            Union(a, b);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
