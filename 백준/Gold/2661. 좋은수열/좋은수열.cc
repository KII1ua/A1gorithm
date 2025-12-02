#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;

/*
    N이 1부터 8까지 나열해보니 12나오고 13나오고 반복임
*/

bool check(string s) {
    int n = s.size();

    for(int i = 1; i <= n / 2; i++) {
        string left = s.substr(n - i * 2, i);
        string right = s.substr(n - i, i);

        if(left == right) return false;
    }

    return true;
}

void bt(int cnt, string s) {
    if(cnt == N) {
        cout << s;
        exit(0);
    }

    for(int i = 1; i <= 3; i++) {
        string nextstr = s + to_string(i);

        if(check(nextstr)) {
            bt(cnt+1, nextstr);
        }
    }
}

void solve() {
    bt(0, "");
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}