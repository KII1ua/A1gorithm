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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
string s;
int alpha[26];
int answer;

void dfs(int x, int last) {
    if(x == s.size()){
        answer++;
        return;
    }

    for(int i = 0; i < 26; i++) {
        if(alpha[i] == 0) continue;

        if(i == last) continue;
        alpha[i]--;
        dfs(x+1, i);
        alpha[i]++;
    }
}

void solve() {
    dfs(0, 27);

    cout << answer;
}

void input() {
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        alpha[s[i] - 'a']++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
