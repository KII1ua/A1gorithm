#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, answer;
int arr[100001];

void solve() {
    int lo = 0;
    int ri = N-1;

    int sz = N-2;

    while(lo < ri) {
        int value = min(arr[lo], arr[ri]) * sz;

        if(arr[lo] > arr[ri]) {
            ri--;
        }
        else lo++;
        sz--;

        answer = max(answer, value);
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}