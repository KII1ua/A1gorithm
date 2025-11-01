#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<int> v;
int answer = MAX;

void solve() {
    vector<tuple<int, int, int>>  arr;

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            arr.push_back({v[i] + v[j], i, j});
        }
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            int idx1 = get<1>(arr[i]);
            int idx2 = get<2>(arr[i]);
            int idx3 = get<1>(arr[j]);
            int idx4 = get<2>(arr[j]);

            if((idx1 != idx3) && (idx1 != idx4) && (idx2 != idx3) && (idx2 != idx4)) {
                int diff = get<0>(arr[j]) - get<0>(arr[i]);
                answer = min(answer, diff);
                break;
            }
        }
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
