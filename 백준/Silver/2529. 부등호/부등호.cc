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

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int N;
vector<char> v;
int arr[10];
bool visited[10];
ll max_answer = 0;
ll min_answer = 1e12;
string answer1, answer2;

bool check() {
    for(int i = 0; i < N; i++) {
        if(v[i] == '<') {
            if(arr[i] < arr[i+1]) {
                continue;
            }
            else return false;
        }
        else {
            if(arr[i] > arr[i+1]) {
                continue;
            }
            else return false;
        }
    }
    return true;
}

void bt(int x, int cnt) {
    if(cnt == N+1) {
        if(check()) {
            ll num = 0;
            string s = "";
            for(int i = 0; i <= N; i++) {
                num = num * 10 + arr[i];
                s += to_string(arr[i]);
            }

            if(max_answer < num) {
                max_answer = num;
                answer1 = s;
            }

            if(min_answer > num) {
                min_answer = num;
                answer2 = s;
            }
        }

        return;
    }

    for(int i = 0; i < 10; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr[x] = i;
            bt(x+1, cnt+1);
            visited[i] = false;
        }
    }
}

void solve() {
    bt(0, 0);

    cout << answer1 << endl << answer2;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        char c;
        cin >> c;
        v.push_back(c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
