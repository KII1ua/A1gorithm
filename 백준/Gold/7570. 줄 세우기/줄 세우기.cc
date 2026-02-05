#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 1000001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[MAX];
int idx[MAX];
int dp[MAX];

void solve() {
    if(N == 1) {
        cout << 0;
        return;
    }
    for(int i = 1; i <= N; i++) {
        idx[arr[i]] = i;
    }

    int cnt = 1;
    int answer = 1;

    for(int i = 2; i <= N; i++) {
        if(idx[i] > idx[i-1]) {
            cnt++;
            answer = max(answer, cnt);
        }
        else cnt = 1;
    }
    

    cout << N - answer;
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}