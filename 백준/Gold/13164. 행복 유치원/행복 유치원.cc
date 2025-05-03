#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, K;
int arr[300001];
priority_queue<int, vector<int>> pq;

/*
 *      N명의 유치원 생 수를 K만큼 나눴을때 나오는 나머지
 */

bool compare(int a, int b) {
    return a > b;
}

void solve() {
    for(int i = 0; i < N-1; i++) {
        int tmp = arr[i+1] - arr[i];
        pq.push(tmp);
    }

    for(int i = 0; i < K-1; i++) {
        pq.pop();
    }

    ll result = 0;
    while(!pq.empty()) {
        ll tmp = pq.top();
        pq.pop();
        result += tmp;
    }

    cout << result;
}

void input() {
    cin >> N >> K;

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