// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;

struct score {
    string name;
    int kor, eng, math;
};

vector<score> v;

bool compare(score a, score b) {
    if(a.kor == b.kor && a.eng == b.eng && a.math == b.math) {
        return a.name < b.name;
    }
    else if(a.kor == b.kor && a.eng == b.eng && a.math != b.math) {
        return a.math > b.math;
    }
    else if(a.kor == b.kor && a.eng != b.eng) {
        return a.eng < b.eng;
    }
    else {
        return a.kor > b.kor;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        string s;
        score sc;
        int k, e, m;
        cin >> s >> k >> e >> m;

        sc.name = s;
        sc.kor = k;
        sc.eng = e;
        sc.math = m;

        v.push_back({sc.name, sc.kor, sc.eng, sc.math});
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < N; i++) {
        cout << v[i].name << endl;
    }
}
