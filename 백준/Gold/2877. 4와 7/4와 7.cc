#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int arr[] = {4, 7};
int K, N, start, End;

void solve() {
    int tmp = K - start;

    for(int i = N-1; i >= 0; i--) {
        if(tmp & (1 << i)) cout << 7;
        else cout << 4;
    }
}

void findn(int x) {
    for(int i = 1; ;i++) {
        int left = (1 << i) - 1;
        int right = (1 << (i+1)) - 2;

        if(left <= x && x <= right) {
            N = i;
            start = left;
            return;
        }
    }
}

void input() {
    cin >> K;

    findn(K);
    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
