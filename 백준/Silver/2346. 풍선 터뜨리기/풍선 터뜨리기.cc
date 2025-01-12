// baekjoon 24228
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
deque<pair<int, int>> dq;
vector<int> v;
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        dq.push_back({a, i+1});
    }

    while(!dq.empty()) {
        int cnt = dq.front().first;
        int idx = dq.front().second;
        v.push_back(idx);
        dq.pop_front();

        if(cnt > 0) {
            for(int i = 0; i < cnt-1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for(int i = 0; i > cnt; i--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
}
