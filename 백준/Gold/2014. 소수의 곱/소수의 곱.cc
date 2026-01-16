#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e14 + 1;
const int MAX = 100001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int K, N;
int arr[MAX];
priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve() {
    ll value = 0;
    while(N--) {
        value = pq.top();
        pq.pop();

        for(int i = 0; i < K; i++) {
            ll tmp = value * arr[i];
            pq.push(tmp);

            if(value % arr[i] == 0) break;
        }
    }

    cout << value;
}

void input() {
    cin >> K >> N;

    for(int i = 0; i < K; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}