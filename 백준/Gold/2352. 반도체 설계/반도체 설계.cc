#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[40001];

void solve() {
    vector<int> v;

    for(int i = 0; i < N; i++) {
        if(v.empty() || v[v.size()-1] < arr[i]) {
            v.push_back(arr[i]);
        }
        else {
            int lo = -1;
            int hi = v.size()-1;

            while(lo + 1 < hi) {
                int mid = (lo + hi) / 2;

                if(v[mid] > arr[i]) {
                    hi = mid;
                }
                else lo = mid;
            }
            v[hi] = arr[i];
        }
    }

    cout << v.size();
}

void input() {
    cin >> N;

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