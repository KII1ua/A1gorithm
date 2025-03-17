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
    int bnp_cash = N, timing_cash = N;
    int bnp_stock = 0, timing_stock = 0;

    for (int i = 1; i <= 14; i++) {
        if (bnp_cash >= arr[i]) {
            int buy = bnp_cash / arr[i];
            bnp_stock += buy;
            bnp_cash -= buy * arr[i];
        }
    }
    int bnp_total = bnp_cash + (bnp_stock * arr[14]);

    int up_cnt = 0, down_cnt = 0;
    for (int i = 2; i <= 14; i++) {
        if (arr[i] > arr[i - 1]) {
            up_cnt++;
            down_cnt = 0;
        } else if (arr[i] < arr[i - 1]) {
            down_cnt++;
            up_cnt = 0;
        } else {
            up_cnt = 0;
            down_cnt = 0;
        }

        if (down_cnt >= 3) {
            int buy = timing_cash / arr[i];
            timing_stock += buy;
            timing_cash -= buy * arr[i];
        }
        if (up_cnt >= 3 && timing_stock > 0) {  
            timing_cash += timing_stock * arr[i];
            timing_stock = 0;
        }
    }
    int timing_total = timing_cash + (timing_stock * arr[14]);

    if (bnp_total > timing_total) {
        cout << "BNP" << endl;
    } else if (bnp_total < timing_total) {
        cout << "TIMING" << endl;
    } else {
        cout << "SAMESAME" << endl;
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
