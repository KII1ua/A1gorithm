// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
ll X, K, ret;

void input() {
    cin >> X >> K;
}

void solve() {
    int j=0;
    for(int i=0;;i++){
        if(!((X>>i)&1)){
            ret |= ((K>>j)&1) << i;
            j++;
            if(!(K>>j)) break;
        }
    }

    cout << ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
