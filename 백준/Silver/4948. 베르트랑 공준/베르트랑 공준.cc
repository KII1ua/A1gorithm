// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
bool prime[250000];
int N;

void solve() {
    prime[1] = true;

    for(int i = 2; i < sqrt(250000); i++) {
        if(!prime[i]) {
            for(int j = i * 2; j < 250000; j += i) {
                prime[j] = true;
            }
        }
    }

    while(true) {
        cin >> N;

        if(N) {
            int cnt = 0;
            for(int i = N+1; i <= 2 * N; i++) {
                if(!prime[i]) cnt++;
            }

            cout << cnt << endl;
        }
        else break;
    }
}

void solution() {
    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solution();
}
