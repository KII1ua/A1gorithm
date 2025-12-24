#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, L;
int cnt[1001];
vector<int> v;

bool check(int cutting, int mid) {
    int cut = 0;
    int last = 0;

    for(int i = 0; i < v.size(); i++) {
        if(v[i] - last >= mid) {
            cut++;
            last = v[i];
        }
    }

    return cut > cutting;
}

void solve() {
    for(int i = 0; i < N; i++) {
        int lo = -1;
        int ri = L+1;

        while(lo + 1 < ri) {
            int mid = (lo + ri) / 2;

            if(check(cnt[i], mid)) {
                lo = mid;
            }
            else ri = mid;
        }

        cout << lo << endl;
    }
}

void input() {
    cin >> N >> M >> L;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    v.push_back(L);

    for(int i = 0; i < N; i++) {
        cin >> cnt[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}