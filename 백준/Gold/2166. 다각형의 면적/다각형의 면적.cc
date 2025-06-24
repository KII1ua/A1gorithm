#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N;
vector<pii> v;

/*
 *  다각형의 면적을 구하기 위해선 신발끈 공식을 사용해야 한다.
 *  그 외 구현하려면 픽의 정리?로 구현해야 하는데 이건 좌표상의 점의 수를 계산해야 하기때문에
 *  넓이가 커지면 구현이 불가하다.
 */

void solve() {
    cout << fixed;
    cout.precision(1);

    ll area1 = 0;
    ll area2 = 0;

    for(int i = 0; i < N; i++) {
        area1 += 1LL * v[i].first * v[i+1].second;
        area2 += 1LL * v[i].second * v[i+1].first;
    }
    cout << abs(area1 - area2) / 2.0;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    v.push_back({v[0].first, v[0].second});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}