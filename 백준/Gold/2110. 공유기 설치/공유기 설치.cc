// baekjoon 13913
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
ll N, C, result;
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> C;

    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    ll start = 1;      // 최소 거리 = 1 (집들의 좌표는 겹치지 않기 때문)
    ll end = v[N-1] - v[0];

    while(start <= end) {
        ll mid = (start + end) / 2;

        ll cnt = 1;
        ll mn = v[0];
        for(int i = 1; i < N; i++) {
            if(v[i] - mn >= mid) {
                cnt++;
                mn = v[i];
            }
        }

        if(cnt >= C) {
            start = mid + 1;
            result = max(mid, result);
        }
        else end = mid - 1;
    }

    cout << result;
}