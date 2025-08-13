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

struct nutrition {
    int p;
    int f;
    int s;
    int v;
    int cost;
};

int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int N, mp, mf, ms, mv;
vector<nutrition> v;
bool visited[16];
vector<int> tmp;
int result = MAX;

void bt(int start, int picked, int target) {
    vector<int> tmpo;
    if (picked == target) {
        int protein = 0;
        int province = 0; // (fat)
        int carbo = 0;
        int vitamin = 0;
        int totalcost = 0;

        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                protein += v[i].p;
                province += v[i].f;
                carbo += v[i].s;
                vitamin += v[i].v;
                totalcost += v[i].cost;
                tmpo.push_back(i + 1); // 1-based index
            }
        }

        if (protein >= mp && province >= mf && carbo >= ms && vitamin >= mv) {
            if (result > totalcost) {
                tmp = tmpo;
                result = totalcost;
            } else if (result == totalcost) {
                if (tmpo < tmp) tmp = tmpo; // 사전순
            }
        }
        return;
    }

    for (int i = start; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            bt(i + 1, picked + 1, target);
            visited[i] = false;
        }
    }
}

void solve() {
    for (int k = 1; k <= N; k++) {
        bt(0, 0, k);
    }

    if (result == MAX) {
        cout << -1 << "\n";
        return;
    }
    cout << result << "\n";
    for (int i = 0; i < (int)tmp.size(); i++) {
        if (i) cout << ' ';
        cout << tmp[i];
    }
    cout << "\n";
}

void input() {
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    v.reserve(N);
    for (int i = 0; i < N; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        v.push_back({a, b, c, d, e});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    input();
    solve();
}
