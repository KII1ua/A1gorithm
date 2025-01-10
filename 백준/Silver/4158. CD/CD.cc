// baekjoon 13913
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, M, a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(true) {
        cin >> N >> M;

        if(N == 0 && M == 0) break;

        unordered_set<int> uos;
        int cnt = 0;

        for(int i = 0; i < N; i++) {
            int a;
            cin >> a;
            uos.insert(a);
        }

        for(int j = 0; j < M; j++) {
            int a;
            cin >> a;
            if(uos.find(a) != uos.end()) cnt++;
        }

        cout << cnt << endl;
    }
}
