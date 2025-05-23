// baekjoon 24228
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, idx, res;

    cin >> N;
    res = N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);

        if(a == N) {
            idx = i;
        }
    }

    for(int j = idx; j >= 0; j--) {
        if(v[j] == N) {
            N--;
            res--;
        }
    }

    cout << res;
}
