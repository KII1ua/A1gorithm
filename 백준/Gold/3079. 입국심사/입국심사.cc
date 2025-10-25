#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e18

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
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0};
int dy[] = {0, 1};
int graph[1002][1002];
int N, M;
int arr[100001];

bool check(ll time) {

    ll people = 0;
    for(int i = 0; i < N; i++) {
        people += (time / arr[i]);
        if(people >= M) return people >= M;
    }

    return people >= M;
}

void solve() {
    ll left = 0;
    ll right = MAX;

    while(left + 1 < right) {
        ll mid = (left + right) / 2;

        if(check(mid)) {
            right = mid;
        }
        else left = mid;
    }

    cout << right;
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
