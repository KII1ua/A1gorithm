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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int X, N;

void input() {
    cin >> X >> N;

    int answer = 0;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        answer += a * b;
    }

    cout << ((answer == X) ? "Yes" : "No");
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
