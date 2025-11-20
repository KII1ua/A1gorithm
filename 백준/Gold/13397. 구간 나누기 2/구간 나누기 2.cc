#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9;

struct coordinate {
    int x;
    int y;
    int r;
};

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int arr[5001];

bool check(int mid) {

    int cnt = 1;

    int n_max = arr[0];
    int n_min = arr[0];
    for(int i = 1; i < N; i++) {
        if(arr[i] > n_max) n_max = arr[i];
        if(arr[i] < n_min) n_min = arr[i];

        if((n_max - n_min) > mid) {
            cnt++;
            n_min = arr[i];
            n_max = arr[i];
        }
    }

    return cnt > M;
}

void solve() {
    int lo = -1;
    int hi = MAX;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        if(check(mid)) {
            lo = mid;
        }
        else hi = mid;
    }

    cout << hi;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
