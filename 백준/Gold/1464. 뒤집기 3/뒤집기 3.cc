#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {0,-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0,0, 0, -1, 1, -1, 1, -1, 1};
deque<int> dq;
string s;

void solve() {
    string result = "";

    for(int i = 0; i < s.size(); i++) {
        char now = s[i];

        if(dq.empty()) {
            dq.push_front(now);
        }
        else if(dq.back() <= now) {
            dq.push_back(now);
        }
        else if (dq.front() >= now) {
            dq.push_front(now);
        }
        else {
            dq.push_back(now);
        }
    }

    while(!dq.empty()) {
        char a = dq.front();
        result += a;
        dq.pop_front();
    }

    cout << result;
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
