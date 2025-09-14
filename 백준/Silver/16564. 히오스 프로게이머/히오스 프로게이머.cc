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
int N, K;
ll answer = 0;

void solve(vector<int> &v) {
    ll start = 1;
    ll end = 1e11;

    while(start <= end) {
        ll mid = (start + end) / 2;

        ll dif = 0;
        for(auto it : v) {
            if(it > mid) continue;
            dif += mid - it;
        }

        if(dif > K) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
            answer = max(answer, mid);
        }
    }

    cout << answer;
}

void input() {
    cin >> N >> K;

    vector<int> v(N, 0);

    for(auto &it : v) {
        cin >> it;
    }

    solve(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
