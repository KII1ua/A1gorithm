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
int N, cnt;
int arr[200001];

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        if(b) {     // 1 -> 사람이 들어오는경우
            if(arr[a] == 0) arr[a] = 1;
            else cnt++;
        }
        else {      // 0 -> 사람이 나가는 경우
            if(!arr[a]) cnt++;
            else arr[a] = 0;
        }
    }

    for(int i = 1; i < 200001; i++) {
        cnt += arr[i];
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}