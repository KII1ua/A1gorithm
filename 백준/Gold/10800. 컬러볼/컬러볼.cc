#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
ll color[200001];
ll weight[200001];
ll result[200001];
vector<tuple<int, int, int>> v;     // 색, 무게, 번호

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {  // 무게 기준으로 오른차순
    if(get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
    return get<1>(a) < get<1>(b);
}

void solve() {
    sort(v.begin(), v.end(), compare);

    ll sum = 0;

    for(int i = 0; i < N; i++) {
        int col = get<0>(v[i]);
        int wei = get<1>(v[i]);
        int idx = get<2>(v[i]);

        color[col] += wei;
        weight[wei] += wei;
        sum += wei;

        result[idx] = sum - color[col] - weight[wei] + wei;

        if(i != 0 && (get<0>(v[i-1]) == col) && (get<1>(v[i-1]) == wei)) result[idx] = result[get<2>(v[i-1])];
    }

    for(int i = 1; i <= N; i++) {
        cout << result[i] << endl;
    }
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_tuple(a, b, i));
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
