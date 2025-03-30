#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {0,-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0,0, 0, -1, 1, -1, 1, -1, 1};
int N, result;
int arr[26];
bool visited[26];
int status = (1 << 26) - 1;

void dfs(int idx, int tmp) {
    if(idx == N) {
        if(tmp == status) {
            result++;
        }
        return;
    }

    dfs(idx+1, tmp);
    dfs(idx+1, tmp | arr[idx]);
}

void solve() {
    dfs(0, 0);

    cout << result;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int bit = 0;
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            char now = s[j];
            bit |= (1 << (now - 'a'));
        }
        arr[i] = bit;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
