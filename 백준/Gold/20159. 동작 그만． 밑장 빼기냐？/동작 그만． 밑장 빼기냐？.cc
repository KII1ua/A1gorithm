#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, answer;
int arr[100002];
int odd[100002];
int even[100002];

void solve() {
    for(int i = 1; i <= N; i++) {
        if(i % 2 == 0) {
            even[i] = even[i-2] + arr[i];
            odd[i] = odd[i-1];
        }
        else {
            odd[i] = odd[i-2] + arr[i];
            even[i] = even[i-1];
        }
    }

    answer = odd[N];

    for(int i = 1; i <= N; i++) {
        if(i % 2 == 0) {
            answer = max(answer, odd[i] + even[N-1] - even[i-1]);
        }
        else {
            answer = max(answer, odd[i-1] + even[N] - even[i]);
        }
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}