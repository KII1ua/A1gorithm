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
int N, M;
ll answer = MAX;

void solve(vector<int> &v) {
    ll left = 0;
    ll right = 1e18;

    while(left <= right) {
        ll mid = (left + right) / 2;

        ll ballons = 0;

        for(int i = 0; i < N; i++) {
            ballons += mid / v[i];
        }

        if(ballons >= M) {      // 시간을 더 줄여야함
            answer = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    cout << answer;
}

void input() {
    cin >> N >> M;

    vector<int> v;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    solve(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
