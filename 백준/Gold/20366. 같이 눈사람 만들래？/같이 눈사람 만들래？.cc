#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[601];
vector<tuple<int, int, int>> v;
int answer = INF;

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            v.push_back({arr[i] + arr[j], i, j});
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            int idx1 = get<1>(v[i]);
            int idx2 = get<2>(v[i]);

            int idx3 = get<1>(v[j]);
            int idx4 = get<2>(v[j]);

            if((idx1 != idx3) && (idx1 != idx4) && (idx2 != idx3) && (idx2 != idx4)) {
                int diff = get<0>(v[j]) - get<0>(v[i]);
                answer = min(answer, diff);
            }
            else break;
        }
    }

    cout << answer;
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