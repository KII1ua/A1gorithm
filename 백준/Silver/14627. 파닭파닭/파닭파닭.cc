// baekjoon 13913
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
ll S, C;
ll res;
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> S >> C;

    ll result = 0;
    for(int i = 0; i < S; i++) {
        ll a;
        cin >> a;
        result += a;
        v.push_back(a);
    }

    ll start = 1;
    ll end = *max_element(v.begin(), v.end());

    while(start <= end) {
        ll mid = (start + end) / 2;

        ll cnt = 0;
        for(int i = 0; i < S; i++) {
            cnt += v[i] / mid;
        }

        if(cnt >= C) {
            start = mid + 1;
            res = max(mid, res);
        }
        else end = mid - 1;
    }

    cout << result - (C * res);
}
