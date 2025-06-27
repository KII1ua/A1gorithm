#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {0,0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {0,1, 0, 0, -1, -1, 1, -1, 1};
int N;
unordered_map<ll, ll> um;

void solve() {
    string s = "";
    int cnt = 0;

    while(true) {
        s += '1';
        cnt++;
        int stand = stoi(s);

        if(um.find(stand) != um.end()) {
            cout << -1;
            return;
        }

        int num = stand % N;

        if(num == 0) {
            cout << cnt;
            return;
        }
        s = to_string(num);
        um[stand] = 1;
    }
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