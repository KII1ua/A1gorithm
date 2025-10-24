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

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0};
int dy[] = {0, 1};
int N, L, P;
vector<pii> v;
priority_queue<int> pq;

void Print() {
    for(auto it : v) {
        cout << it.first << " " << it.second << endl;
    }
}

void solve() {
    if(L <= P) {
        cout << 0;
        return;
    }

    sort(v.begin(), v.end());

    int gas = P;
    int answer = 0;
    int located = 0;
    for(int i = 0; i < N; i++) {
        int locate = v[i].first;
        int gasAddit = v[i].second;

        if(gas <= locate) {
            while(!pq.empty() && gas <= locate) {
                gas += pq.top();
                pq.pop();
                answer++;
            }

            if(gas < locate) {
                cout << -1;
                return;
            }
        }
        pq.push(gasAddit);
    }

    while(!pq.empty() && gas < L) {
        gas += pq.top();
        pq.pop();
        answer++;
    }

    if(gas >= L) {
        cout << answer;
    }
    else cout << -1;
}

void input() {
    cin >> N;

    for(int i = 0;  i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});        // 위치, 채울 수 있는 양
    }

    cin >> L >> P;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
