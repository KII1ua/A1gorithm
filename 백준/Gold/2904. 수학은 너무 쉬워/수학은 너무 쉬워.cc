#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e14 + 1;
const int MAX = 100005;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[101];
bool prime[1000001];
int cnt[1000001];
int max_value = 0;

void func(int a) {
    for (int i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            cnt[i]++;
            a /= i;
        }
    }
    if (a > 1) cnt[a]++;
}

void Init() {
    prime[1] = true;
    for(int i = 2; i <= max_value; i++) {
        if(prime[i]) continue;
        for(int j = i + i; j <= max_value; j += i) {
            prime[j] = true;
        }
    }
}

void solve() {
    Init();
    for(int i = 0; i < N; i++) {
        func(arr[i]);
    }

    int ans = 1;

    for(int i = 2; i <= max_value; i++) {
        if(cnt[i] > 0) {
            ans *= pow(i, cnt[i] / N);
        }
    }

    int answer = 0;

    for(int i = 2; i <= max_value; i++) {
        int target = cnt[i] / N;

        if(target == 0) continue;

        for(int j = 0; j < N; j++) {
            int temp = arr[j];
            int count = 0;

            while(temp % i == 0) {
                count++;
                temp /= i;
            }

            if(count < target) {
                answer += (target - count);
            }
        }
    }

    cout << ans << " " << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        max_value = max(arr[i], max_value);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}