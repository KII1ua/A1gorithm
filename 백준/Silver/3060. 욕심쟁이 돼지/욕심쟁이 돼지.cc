#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e8

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int T, N;
ll arr[7];

bool check() {
    ll tmp = 0;

    for(int i = 0; i < 6; i++) {
        tmp += arr[i];
    }

    if(tmp > N) {
        return false;
    }
    return true;
}

void solve() {
    int cnt = 1;

    while(check()) {
        ll tmp[6] = {};
        for(int i = 0; i < 6; i++) {
            if(i <= 2) {
                tmp[i] = arr[(i - 1 + 6) % 6] + arr[(i + 1 + 6) % 6] + arr[i+3] + arr[i];
            }
            else {
                tmp[i] = arr[(i - 1 + 6) % 6] + arr[(i + 1 + 6) % 6] + arr[i-3] + arr[i];
            }
        }

        for(int i = 0; i < 6; i++) {
            arr[i] = tmp[i];
        }
        cnt++;
    }

    cout << cnt << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        memset(arr, 0, sizeof(arr));

        for(int i = 0; i < 6; i++) {
            cin >> arr[i];
        }

        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}