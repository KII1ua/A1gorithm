#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int N, M;
vector<pii> v1;
vector<pii> v2;
vector<int> result;

bool compare(pii a, pii b) {        // 원소, 원래 순서
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void solve() {
    sort(v1.begin(), v1.end(), compare);
    sort(v2.begin(), v2.end(), compare);

    int idx1 = 0, idx2 = 0, limit1 = 0, limit2 = 0;

    while(idx1 < N && idx2 < M) {
        if(v1[idx1].first == v2[idx2].first) {
            if(limit1 > v1[idx1].second) idx1++;
            else if(limit2 > v2[idx2].second) idx2++;
            else {
                limit1 = v1[idx1].second;
                limit2 = v2[idx2].second;

                result.push_back(v1[idx1].first);
                idx1++;
                idx2++;
            }
        }
        else if(v1[idx1].first > v2[idx2].first) {
            idx1++;
        }
        else idx2++;
    }

    cout << result.size() << endl;

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}

void input() {
    cin >> N;

    v1.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> v1[i].first;
        v1[i].second = i;
    }

    cin >> M;

    v2.resize(M);

    for(int i = 0; i < M; i++) {
        cin >> v2[i].first;
        v2[i].second = i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}