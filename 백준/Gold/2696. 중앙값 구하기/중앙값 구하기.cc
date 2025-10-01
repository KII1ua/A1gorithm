#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int T, N;

void solve() {

}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        int middle;

        priority_queue<int, vector<int>, greater<int>> min_pq;
        priority_queue<int, vector<int>> max_pq;
        vector<int> v;

        cin >> middle;
        v.push_back(middle);

        for(int i = 2; i <= N; i++) {
            int a;
            cin >> a;

            if(a > middle) {
                min_pq.push(a);
            }
            else max_pq.push(a);

            if(i % 2 == 1) {
                if(max_pq.size() < min_pq.size()) {
                    max_pq.push(middle);
                    middle = min_pq.top();
                    min_pq.pop();
                    v.push_back(middle);
                }
                else if(max_pq.size() > min_pq.size()) {
                    min_pq.push(middle);
                    middle = max_pq.top();
                    max_pq.pop();
                    v.push_back(middle);
                }
                else v.push_back(middle);
            }
        }
        cout << N / 2 + 1 << endl;

        for(int i = 0; i < v.size(); i++) {
            if(i % 10 == 0 && i != 0) {
                cout << endl;
            }
            cout << v[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
