#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int left, right;
};

const int INF = 1e9;
const int MAX = 100001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<pii> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), [](pii a, pii b){
        return a.second < b.second;
        if(a.second == b.second) return a.first < b.first;
    });

    int min_date = v[0].second - v[0].first;
    int start_date = v[0].second;

    if(min_date < 0) {
        cout << -1;
        return 0;
    }

    for(int i = 1; i < N; i++) {
        if(start_date + v[i].first <= v[i].second) {
            start_date = start_date + v[i].first;
        }
        else {
            int diff = start_date + v[i].first - v[i].second;
            min_date -= diff;
            start_date = v[i].second;

            if(diff < 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << min_date;
}