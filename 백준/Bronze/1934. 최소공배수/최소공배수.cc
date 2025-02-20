// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

int T;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        int res = gcd(a, b);
        
        a = a / res;
        b = b / res;
        
        cout << res * a * b << endl;
    }
}
