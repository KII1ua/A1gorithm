// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, M;
vector<pair<string, int>> v;

bool compare(pair<string, int> a, pair<string, int> b) {
    if(a.second < b.second) {
        return a.second < b.second;
    }
    return a.second < b.second;
}

void binary_search(int stand) {
    int start = 0;
    int end = N-1;

    while(start < end) {
        int mid = (start + end) / 2;

        if(v[mid].second >= stand)
            end = mid;
        else
            start = mid + 1;
    }
    cout << v[start].first << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string s;
        int a;
        cin >> s >> a;
        v.push_back(make_pair(s, a));
    }

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        binary_search(a);
    }
}
