// baekjoon 28706
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, L;
int arr[1000001];
int res, cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        res += arr[i];

        if(i >= L) {
            res -= arr[i-L];
        }

        if(res >= 129 && res <= 138) {
            cnt++;
        }
    }

    cout << cnt;
}