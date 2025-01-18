// baekjoon 1504
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
//#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    cout << "? 1" << endl;
    cin >> a;
    cout << "? " << N << endl;
    cin >> b;

    if(a == 0 && b == 1) cout << "! " << 1 << endl;
    else if(a == 1 && b == 0) cout << "! " << -1 << endl;
    else cout << "! " << 0 << endl;
}
