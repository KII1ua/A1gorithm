// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
vector<pii> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    bool istrue = false;

    for(int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    if((double) (v[1].first - v[0].first) / (v[1].second - v[0].second) == (double) (v[2].first - v[1].first)
    / (v[2].second - v[1].second)) {
        cout << "WHERE IS MY CHICKEN?";
    }
    else cout << "WINNER WINNER CHICKEN DINNER!";
}
