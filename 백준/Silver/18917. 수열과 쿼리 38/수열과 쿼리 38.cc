// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N;
pair<ll, ll> result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a, b;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a;

        if(a == 1) {
            cin >> b;
            result.first ^= b;
            result.second += b;
        }
        else if(a == 2) {
            cin >> b;
            result.first ^= b;
            result.second -= b;
        }
        else if(a == 3) {
            cout << result.second << endl;
        }
        else if(a == 4) {
            cout << result.first << endl;
        }
    }
}
