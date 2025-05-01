#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
ll N;
ll result;
queue<int> q;
int cnt = 0;

void solve() {
    if(N == 0) {
        q.push(0);
    }

    while(N > 0) {
        q.push(N % 2);
        N /= 2;
    }

    while(!q.empty()) {
        int tmp = q.front();
        ll stand = 1;
        q.pop();

        if(tmp == 1) {
            for(int i = 0; i < cnt; i++) {
                stand *= 3;
            }
            result += stand;
        }
        cnt++;
    }

    cout << result;
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