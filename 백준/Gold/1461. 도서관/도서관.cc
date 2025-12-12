#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
vector<int> mi, pl;

bool compare(int a, int b) {
    return a > b;
}

void Print() {
    for(auto it : mi) {
        cout << it << " ";
    }
    cout << endl;

    for(auto it : pl) {
        cout << it << " ";
    }
    cout << endl;
}

void solve() {
    sort(mi.begin(), mi.end());
    sort(pl.begin(), pl.end(), compare);
    int answer = 0;

    int max_mi = (mi.empty())? 0 : abs(mi[0]);
    int max_pl = (pl.empty())? 0 : abs(pl[0]);

    if(max_mi > max_pl) {     // 마이너스 첫번째부터 m개는 한번만
        bool flag = false;

        for(int i = 0; i < mi.size();) {
            if(!flag) {
                flag = true;

                answer += abs(mi[i]);
            }
            else {
                answer += abs(mi[i]) * 2;
            }
            i += M;
        }

        for(int i = 0; i < pl.size();) {
            answer += pl[i] * 2;
            i += M;
        }
    }
    else {
        bool flag = false;

        for(int i = 0; i < pl.size();) {
            if(!flag) {
                flag = true;

                answer += pl[i];
            }
            else {
                answer += pl[i] * 2;
            }
            i += M;
        }

        for(int i = 0; i < mi.size();) {
            answer += abs(mi[i]) * 2;
            i += M;
        }
    }

    cout << answer;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if(a > 0) {
            pl.push_back(a);
        }
        else mi.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}