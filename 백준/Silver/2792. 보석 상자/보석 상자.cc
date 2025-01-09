// baekjoon 13913
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
ll N, M, tmp;
vector<int> v;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll start, end;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    start = 0, end = v[M-1];

    while(start + 1 < end) {
        ll mid = (start + end) / 2;     // 질투심

        ll cnt = 0;
        for(int i = 0; i < M; i++) {
            cnt += v[i] / mid;
            if(v[i] % mid != 0) cnt++;
        }

        if(N >= cnt) end = mid;
        else   start = mid;
    }

    cout << start + 1;
}