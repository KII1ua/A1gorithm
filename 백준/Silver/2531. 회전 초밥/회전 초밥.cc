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
int N, D, K, C, flag, coupon, result;
int arr[30001];
int check[3001];

void solve() {
    for(int i = 0; i < N; i++) {
        flag = 0;
        coupon = 1;
        for(int j = i; j < i + K; j++) {
            if(check[arr[j % N]] == 1) flag++;      // 이미 존재한 초밥인 경우
            else check[arr[j % N]] = 1;             // 없는 경우 어떤 초밥인지 체크

            if(arr[j % N] == C) coupon = 0;         // 선택한 초밥이 쿠폰 초밥인 경우
        }
        result = max(result, K - flag + coupon);
        memset(check, 0, sizeof(check));
    }

    cout << result;
}

void input() {
    cin >> N >> D >> K >> C;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}