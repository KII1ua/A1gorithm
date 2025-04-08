#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
int unf[51];
int people;
vector<int> true_people;
vector<vector<int>> party(51);

int Find(int a) {
    if(a == unf[a]) return a;
    return unf[a] = Find(unf[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a < b) unf[b] = a;
    else unf[a] = b;
}

bool isUnion(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void solve() {
    int result = M;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        for(int j = 0; j < a; j++) {
            int b;
            cin >> b;
            party[i].push_back(b);
        }
    }

    for(int i = 0; i < M; i++) {
        int stand = party[i][0];
        for(int j = 0; j < party[i].size(); j++) {
            Union(stand, party[i][j]);
        }
    }

    for(int i = 0; i < M; i++) {
        bool visited = false;
        for(int j = 0; j < people; j++) {
            if(isUnion(party[i][0], true_people[j])) {
                visited = true;
                break;
            }
        }
        if(visited) {
            result--;
        }
    }

    cout << result;
}

void init() {
    for(int i = 1; i <= N; i++) {
        unf[i] = i;
    }
}

void input() {
    cin >> N >> M;
    cin >> people;
    for(int i = 0; i < people; i++) {
        int a;
        cin >> a;
        true_people.push_back(a);
    }
    init();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}