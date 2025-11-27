#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<int> ma, mb, wa, wb;

void solve() {
    sort(ma.begin(), ma.end());
    sort(mb.begin(), mb.end());
    sort(wa.begin(), wa.end());
    sort(wb.begin(), wb.end());

    int i = 0;
    int j = 0;
    int answer = 0;

    while(i < ma.size() && j < wb.size()) {
        if(ma[i] < wb[j]) {
            answer++;
            i++;
            j++;
        }
        else j++;
    }

    i = 0, j = 0;

    while(i < wa.size() && j < mb.size()) {
        if(wa[i] < mb[j]) {
            answer++;
            i++;
            j++;
        }
        else {
            j++;
        }
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if(a > 0) {
            ma.push_back(a);
        }
        else mb.push_back(abs(a));
    }

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if(a > 0) {
            wa.push_back(a);
        }
        else wb.push_back(abs(a));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}