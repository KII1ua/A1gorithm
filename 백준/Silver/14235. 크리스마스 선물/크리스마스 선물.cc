#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
priority_queue<int, vector<int>> pq;

void solve() {

}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(a == 0) {
            if(pq.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else {
            for(int j = 0; j < a; j++) {
                int b;
                cin >> b;
                pq.push(b);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}