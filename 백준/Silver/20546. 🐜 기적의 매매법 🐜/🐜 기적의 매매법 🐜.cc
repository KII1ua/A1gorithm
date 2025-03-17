#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N;
int arr[16];

void solve() {
    int ans1, ans2 = 0;
    ans1 = N;
    ans2 = N;
    int cnt1 = 0, cnt2 = 0;

    for(int i = 1; i <= 14; i++) {
        if(ans1 >= arr[i]) {
            int buy = ans1 / arr[i];
            cnt1 += buy;
            ans1 -= buy * arr[i];
        }
    }

    int result1 = ans1 + (cnt1 * arr[14]);

    int tmp1 = 0;       // 구매 카운트
    int tmp2 = 0;       // 판매 카운트

    for(int i = 2; i <= 14; i++) {
        if(arr[i] < arr[i-1]) {
            tmp1++;
            tmp2 = 0;
        }
        else if(arr[i] > arr[i-1]) {
            tmp2++;
            tmp1 = 0;
        }
        else {
            tmp1 = 0;
            tmp2 = 0;
        }

        if(tmp1 >= 3) {     // 사는 것
            int buy = ans2 / arr[i];
            cnt2 += buy;
            ans2 -= buy * arr[i];
        }
        else if(tmp2 >= 3 && cnt2 > 0) {
            int money = cnt2 * arr[i];
            ans2 += money;
            cnt2 = 0;
        }
    }

    int result2 = ans2 + cnt2 * arr[14];

    if(result1 > result2) {
        cout << "BNP";
    }
    else if(result1 < result2) {
        cout << "TIMING";
    }
    else {
        cout << "SAMESAME";
    }
}

void input() {
    cin >> N;

    for(int i = 1; i <= 14; i++) {
        cin >> arr[i];
    }

    solve();
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
