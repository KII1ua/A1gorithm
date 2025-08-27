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
int N;
ll cross[100001];
ll leftbr[100001];
ll rightbr[100001];
ll answer = 1e18;
ll bridge;

void solve() {
    for(int i = 0; i < N; i++) {
        ll dist = leftbr[i] + cross[i] + rightbr[N-1] - rightbr[i];

        if(dist < answer) {
            answer = dist;
            bridge = i+1;
        }
    }
    cout << bridge << " " << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> cross[i];
    }

    for(int i = 1; i < N; i++) {
        cin >> leftbr[i];
        leftbr[i] += leftbr[i-1];
    }

    for(int i = 1; i < N; i++) {
        cin >> rightbr[i];
        rightbr[i] += rightbr[i-1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
