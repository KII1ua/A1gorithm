#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 123457;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s;
int arr[3];
char answer[51];
int dp[51][51][51][4][4];

bool func(int a, int b, int c, int d, int dd) {
    if(a == arr[0] && b == arr[1] && c == arr[2]) {
        return true;
    }

    if(dp[a][b][c][d][dd]) return false;

    dp[a][b][c][d][dd] = true;

    if(a + 1 <= arr[0]) {
        answer[a + b + c] = 'A';
        if(func(a+1, b, c, 1, d)) return true;
    }

    if(b + 1 <= arr[1]) {
        answer[a + b + c] = 'B';
        if(d != 2 && func(a, b+1, c, 2, d)) return true;
    }

    if(c + 1 <= arr[2]) {
        answer[a + b + c] = 'C';
        if(dd != 3 && d != 3 && func(a, b, c+1, 3, d)) return true;
    }

    return false;
}

void solve() {
    if(func(0, 0, 0, 0, 0)) {
        for(int i = 0; i < s.size(); i++) {
            cout << answer[i];
        }
    }
    else cout << -1;
}

void input() {
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'A') arr[0]++;
        else if(s[i] == 'B') arr[1]++;
        else arr[2]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}