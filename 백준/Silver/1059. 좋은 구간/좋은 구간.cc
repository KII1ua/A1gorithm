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
int L, n;
vector<int> v;

void solve() {
    sort(v.begin(), v.end());

    bool flag = false;

    int left = 0;
    int right = 0;

    for(int i = 1; i < L+1; i++) {
        if(v[i] == n) flag = true;
        else if(v[i] > n) {
            right = v[i] - 1;
            left = v[i-1] + 1;
            break;
        }
    }

    if(flag) cout << 0;
    else cout << (n - left + 1) * (right - n + 1) - 1;
}

void input() {
    cin >> L;

    for(int i = 0; i < L; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    v.push_back(0);

    cin >> n;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
