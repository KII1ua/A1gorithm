// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
bool prime[1000001];
int T;

void solve() {
    prime[1] = true;

    for(int i = 2; i <= sqrt(1000000); i++) {
        if(!prime[i]) {
            for(int j = i * 2; j <= 1000000; j += i) {
                prime[j] = true;
            }
        }
    }

    cin >> T;

    for(int i = 0; i < T; i++) {
        int a;
        cin >> a;

        int count = 0;
        for(int j = a-1; j >= 2; j--) {
            if(!prime[a-j] && !prime[j] && j <= a - j) {
                count++;
            }
        }

        cout << count << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}
