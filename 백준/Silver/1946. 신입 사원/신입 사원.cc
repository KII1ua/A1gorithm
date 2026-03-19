#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 20001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;

        vector<pii> x;
        vector<pii> y;

        for(int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            x.push_back({a, b});
            y.push_back({a, b});
        }

        sort(x.begin(), x.end(), [](pii a, pii b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        sort(y.begin(), y.end(), [](pii a, pii b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

        int answer = 0;
        int cntx = 1;
        int cnty = 1;
        int maxy = x[0].second;
        int maxx = y[0].first;

        for(int i = 1; i < N; i++) {
            if(maxy >= x[i].second) {
                maxy = x[i].second;
                cntx++;
            }
        }

        for(int i = 1; i < N; i++) {
            if(maxx >= y[i].first) {
                maxx = y[i].first;
                cnty++;
            }
        }

        answer = max(cntx, cnty);

        cout << answer << endl;
    }
}