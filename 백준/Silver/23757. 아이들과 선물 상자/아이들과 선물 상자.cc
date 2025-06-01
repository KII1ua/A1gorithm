#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int N, M;
int children[100001];
priority_queue<int, vector<int>> pq;

void solve() {
    for(int i = 0; i < M; i++) {
        if(pq.top() >= children[i] && !pq.empty()) {
            int tp = pq.top();
            pq.pop();
            tp -= children[i];
            pq.push(tp);
        }
        else {
            cout << "0";
            exit(0);
        }
    }

    cout << "1";
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }
    
    for(int i = 0; i < M; i++) {
        cin >> children[i];
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}