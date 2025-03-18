#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
vector<pii> house, chicken;
vector<int> v;
int graph[51][51];
bool Select[13];
int result = 1e9;

int calc_distance() {
    int dist = 0;

    for(int i = 0; i < house.size(); i++) {
        int tmpdist = 1e9;
        for(int j = 0; j < v.size(); j++) {
            int chickenx = chicken[v[j]].first;
            int chickeny = chicken[v[j]].second;

            int housex = house[i].first;
            int housey = house[i].second;

            tmpdist = min(abs(chickenx - housex) + abs(chickeny - housey), tmpdist);
        }
        dist += tmpdist;
    }

    return dist;
}

void bt(int idx, int cnt) {
    if(cnt == M) {
        result = min(result, calc_distance());
    }

    for(int i = idx; i < chicken.size(); i++) {
        if(Select[i]) continue;
        Select[i] = true;
        v.push_back(i);
        bt(i, cnt+1);
        Select[i] = false;
        v.pop_back();
    }
}

void solve() {
    bt(0, 0);

    cout << result;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 1) house.push_back(make_pair(i, j));
            else if(graph[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }

    solve();
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
