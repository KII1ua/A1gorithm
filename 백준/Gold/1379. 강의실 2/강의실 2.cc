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
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {0, -1, 1, 0};
int dy[] = {1, 0, 0, 1};
int N;
vector<tuple<int, int, int>> v;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
priority_queue<int> seat;
map<int, int> m;        // 강의 번호, 강의실번호

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<1>(a) < get<1>(b);
}

void Print() {
    for(auto it : v) {
        cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
    }
}

void solve() {
    sort(v.begin(), v.end());

    int cnt = 1;
    pq.push({get<1>(v[0]), cnt, get<2>(v[0])});
    m[get<2>(v[0])] = cnt;

    for(int i = 1; i < N; i++) {
        int start = get<0>(v[i]);
        int endt = get<1>(v[i]);
        int lecture = get<2>(v[i]);

        if(get<0>(pq.top()) <= start) {       // 현재 자리에서 나갈 수 있음
            int number = get<1>(pq.top());
            pq.pop();
            pq.push({endt, number, lecture});
            m[lecture] = number;
        }
        else {
            cnt++;
            pq.push({endt, cnt, lecture});
            m[lecture] = cnt;
        }
    }

    cout << cnt << endl;

    for(int i = 1; i <= N; i++) {
        cout << m[i] << endl;
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({b, c, a});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
