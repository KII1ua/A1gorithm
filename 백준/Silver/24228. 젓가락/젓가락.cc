// baekjoon 28706
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll N, R;

    cin >> N >> R;

//    if(N == 1) {
//        if(R == 1) {
//            cout << 2;
//            return 0;
//        }
//        cout << R;
//        return 0;
//    }
    cout << N + (R * 2) - 1;
}