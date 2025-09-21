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
int d, n, m, answer;

void solve(vector<int> &v) {
    sort(v.begin(), v.end());

    int left = 0;
    int right = d;

    while(left <= right) {
        int mid = (left + right) / 2;

        int stone = 0;
        int locate = 0;
        int min_dist = d;
        for(int i = 0; i < n; i++) {
            if(v[i] - locate >= mid) {
                min_dist = min(min_dist, v[i] - locate);
                locate = v[i];
            }
            else stone++;
        }

        min_dist = min(min_dist, d - locate);

        if(stone > m) {     // 돌 제거를 m보다 많이 한 경우 점프할 수 있는 mid값을 줄여야함
            right = mid - 1;
        }
        else {
            answer = max(answer, mid);
            left = mid + 1;
        }
    }

    cout << answer;
}

void input() {
    cin >> d >> n >> m;

    vector<int> v(n, 0);

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
