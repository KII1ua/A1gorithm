#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, L;
int arr[5000001];

void solve() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 0; i < N; i++) {
        pq.push(make_pair(arr[i], i));

        while(true) {
            int num = pq.top().first;
            int idx = pq.top().second;

            if(i - L + 1 <= idx && idx <= i) {
                cout << num << " ";
                break;
            }
            pq.pop();
        }
    }
}

void input() {
    cin >> N >> L;

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