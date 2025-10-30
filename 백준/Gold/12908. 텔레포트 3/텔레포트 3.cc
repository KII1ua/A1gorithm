#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

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
int xs, ys, xe, ye;
vector<pair<ll, ll>> v;
ll graph[8][8];

void Init() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i == j) continue;
            graph[i][j] = MAX;
        }
    }
}

void Print() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(auto it : v) {
        cout << it.first << " " << it.second << endl;
    }
}

void solve() {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(i == j) continue;

            ll lens = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            graph[i][j] = min(graph[i][j], lens);
            graph[j][i] = min(graph[j][i], lens);
        }
    }

    for(int k = 0; k < v.size(); k++) {
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v.size(); j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    cout << graph[0][1];
}

void input() {
    Init();

    cin >> xs >> ys >> xe >> ye;
    v.push_back({xs ,ys});
    v.push_back({xe, ye});

    for(int i = 0; i < 3; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        graph[v.size()][v.size()+1] = 10;
        graph[v.size()+1][v.size()] = 10;
        v.push_back({x1, y1});
        v.push_back({x2, y2});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
