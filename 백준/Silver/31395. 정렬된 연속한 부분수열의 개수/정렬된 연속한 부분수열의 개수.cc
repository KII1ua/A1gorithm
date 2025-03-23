#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N;
ll arr[200002];
ll result;

void solve() {
    int cnt = 0;

    for(int i = 1; i <= N; i++) {
        cnt++;
        result += cnt;
        if(arr[i] > arr[i+1]) {
            cnt = 0;
        }
    }

    cout << result;
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    arr[N+1] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
