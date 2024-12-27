#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n";

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, B, H, W, p, a;
    int res = int(1e9);

    cin >> N >> B >> H >> W;

    for(int i = 0; i < H; i++) {
        vector<int> v;
        cin >> p;
        for(int j = 0; j < W; j++) {
            cin >> a;
            v.push_back(a);
        }

        for(int k = 0; k < W; k++) {
            if(v[k] >= N) {
                if(p * N <= B)
                    res = min(res, p * N);
            }
        }
    }
    if(res == int(1e9)) {
        cout <<  "stay home";
    }
    else
        cout << res;
}