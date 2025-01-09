// baekjoon 13913
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
ll N, K;
vector<ll> v;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    ll start = 1;
    ll end = 1e15;

    while(start + 1 < end) {
        ll mid = (start + end) / 2;

        ll cnt = 0;
        for(int i = 0; i < N; i++) {
            cnt += v[i] / mid;
        }

        if(cnt >= K) start = mid;
        else end = mid;

    }

    cout << start;
}