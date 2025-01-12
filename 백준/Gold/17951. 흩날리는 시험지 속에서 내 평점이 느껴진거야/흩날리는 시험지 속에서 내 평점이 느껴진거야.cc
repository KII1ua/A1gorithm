// baekjoon 24228
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, K;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    ll start = 0;
    ll end = int(1e15);

    while(start + 1 < end) {
        ll mid = (start + end) / 2;

        ll sum = 0, cnt = 0;
        for(int i = 0; i < N; i++) {
            sum += v[i];
            if(sum >= mid) {
                sum = 0;
                cnt++;
            }
        }

        if(cnt >= K)  start = mid;
        else end = mid;
    }
    cout << start;
}
