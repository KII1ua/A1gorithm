#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, H;
ll result;
vector<tuple<int, ll, ll>> v;

void solve() {
    ll start = 1;
    ll end = 9e18;

    while(start <= end) {
        ll mid = (start + end) / 2;

        ll attack = H;
        ll hp = mid;
        bool visited = false;

        for(int i = 0; i < N; i++) {
            if(get<0>(v[i]) == 1) {     // 몬스터인 경우
                ll hit = (get<2>(v[i]) + attack - 1) / attack;
                ll lowhp = get<1>(v[i]) * (hit-1);

                if(lowhp >= hp) {
                    visited = true;
                    break;
                }
                hp -= lowhp;
            }
            else {
                if(hp + get<2>(v[i]) >= mid) {      // 최대 체력까지 찼을때
                    hp = mid;
                }
                else hp += get<2>(v[i]);
                attack += get<1>(v[i]);
            }
        }

        if(visited) {       // 죽었을 경우
            start = mid+1;
            result = mid;
        }
        else end = mid-1;
    }

    cout << result+1;
}

void input() {
    cin >> N >> H;

    for(int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}