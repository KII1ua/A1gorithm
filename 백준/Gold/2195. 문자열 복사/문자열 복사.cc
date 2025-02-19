// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string S,P;

    cin >> S >> P;
    int cnt = 0;

    for(int i = 0; i < P.size();) {
        int len = 0;
        for(int j = 0; j < S.size(); j++) {
            int tmp = 0;
            while(S[j+tmp] == P[i+tmp]) {
                tmp++;
            }
            len = max(len, tmp);
        }
        i += len;
        cnt++;
    }

    cout << cnt;
}
