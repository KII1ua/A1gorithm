#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
string S, T;

void dfs(string s) {
    if(s == S) {
        cout << 1;
        exit(0);
    }
    if(s.length() == 0) {
        return;
    }
    if(s[s.length()-1] == 'A') {
        dfs(s.substr(0, s.length()-1));
    }
    if(s[s.length()-1] == 'B') {
        string tmp = s.substr(0, s.length()-1);
        reverse(tmp.begin(), tmp.end());
        dfs(tmp);
    }
}

void solve() {
    dfs(T);

    cout << 0;
}

void input() {
    cin >> S >> T;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}