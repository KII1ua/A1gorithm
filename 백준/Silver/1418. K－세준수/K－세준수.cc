// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, K;
int arr[100001];        // true 일 경우 소수가 아님
int cnt;

void isprime(int a) {
    for(int i = 2; i <= N; i++) {
        if(arr[i]) continue;

        for(int j = i; j <= N; j += i) {
            arr[j] = max(arr[j], i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    isprime(N);

    for(int i = 1; i <= N; i++) {
        if(arr[i] > K) {
            cnt++;
        }
    }

    cout << N - cnt;
}
