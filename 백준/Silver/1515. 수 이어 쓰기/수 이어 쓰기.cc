#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9


int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
string s;

void solve() {
    int result = 0;
    int idx = 0;

    while(true) {
        result++;
        string stand = to_string(result);

        for(int i = 0; i < stand.length(); i++) {
            if(stand[i] == s[idx]) {
                idx++;
            }

            if(idx == s.length()) {
                cout << stand;
                return;
            }
        }
    }
}

void input() {
    cin >> s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
