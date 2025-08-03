#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    string s;
    vector<int> v;
};

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int G, P;
int nextPos[100001];
bool visited[100001];

void Init() {
    for(int i = 1; i <= G; i++) {
        nextPos[i] = i;
    }
}

void input() {
    cin >> G >> P;

    Init();

    int cnt = 0;

    for(int i = 0; i < P; i++) {
        int a;
        cin >> a;

        int loc = nextPos[a];

        while(loc >= 1 && visited[loc]) loc--;

        if(loc == 0) break;

        visited[loc] = true;
        cnt++;
        nextPos[a] = loc-1;
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}