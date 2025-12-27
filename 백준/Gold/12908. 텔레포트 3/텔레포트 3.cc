#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
ll xs, ys, xe, ye;
vector<tuple<ll, ll, ll, ll>> v(3);
ll answer = INF;

bool check(vector<int> &arr) {
    for(auto &it : arr) {
        if(it != 5) {
            it++;
            return true;
        }
        else {
            it = -1;
        }
    }

    return false;
}

void solve() {
    vector<int> seq(3, -1);

    answer = abs(xe - xs) + abs(ye - ys);

    do {
        ll startx = xs;
        ll starty = ys;
        ll tmp = 0;

        for(auto &it : seq) {
            if(it == -1) continue;

            tmp += abs(startx - get<0>(v[it])) + abs(starty - get<1>(v[it])) + 10;
            startx = get<2>(v[it]);
            starty = get<3>(v[it]);
        }

        tmp += abs(xe - startx) + abs(ye - starty);
        answer = min(answer, tmp);
    } while(check(seq));

    cout << answer;
}

void input() {
    cin >> xs >> ys >> xe >> ye;

    for(int i = 0; i < 3; i++) {
        auto &a = v[i];

        cin >> get<0>(a) >> get<1>(a) >> get<2>(a) >> get<3>(a);
        v.push_back({get<2>(a), get<3>(a), get<0>(a), get<1>(a)});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}