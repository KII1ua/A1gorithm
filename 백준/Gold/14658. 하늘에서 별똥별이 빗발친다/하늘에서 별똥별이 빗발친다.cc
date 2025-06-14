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
int N, M, L, K;
vector<coordinate> v;

/*
 *      N과 M의 범위가 50만이기 때문에 완전탐색은 불가능 but K의 값은 최대 100이기 때문에
 *      K값을 기준으로 x, y좌표를 두어 L만큼 천막을 펼쳐 계산
 */

void solve() {
    int result = 0;

    for(auto a : v) {
        for(auto b : v) {
            int x = a.x;
            int y = b.y;
            int cnt = 0;
            for(auto c : v) {

                if(x <= c.x && c.x <= x + L && y <= c.y && c.y <= y + L) {
                    cnt++;
                }
            }
            result = max(result, cnt);
        }
    }

    cout << K - result;
}

void input() {
    cin >> N >> M >> L >> K;

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}