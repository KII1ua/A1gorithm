// baekjoon 24230
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

    int N, a;
    int cnt = 0;

    cin >> N;

    for(int i = 0; i < 3; i++) {
        cin >> a;

        if(N > a) cnt += a;
        else cnt += N;
    }
    cout << cnt;
}