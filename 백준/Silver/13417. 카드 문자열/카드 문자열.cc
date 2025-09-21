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
int T, N;
string s;

void solve(vector<char> &v) {
    deque<char> dq;
    dq.push_back(v[0]);

    char stand = v[0];

    for(int i = 1; i < N; i++) {
        if(stand >= v[i]) {
            dq.push_front(v[i]);
            stand = v[i];
        }
        else dq.push_back(v[i]);
    }

    while(!dq.empty()) {
        cout << (char)dq.front();
        dq.pop_front();
    }

    cout << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        vector<char> v(N, 'a');

        for(auto &it : v) {
            cin >> it;
        }

        solve(v);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
