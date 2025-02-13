// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N;
vector<ll> positive;
vector<ll> negative;
ll sum = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int zero = 0, one = 0;

    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(a == 0) {
            zero++;
        }
        else if(a == 1) {
            one++;
        }
        else if(a > 0) {
            positive.push_back(a);
        }
        else {
            negative.push_back(a);
        }
    }

    int psize = positive.size();
    int nsize = negative.size();

    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());

    for(int i = 0; i < psize - 1; i+=2) {
        sum += positive[i] * positive[i+1];
    }

    if(psize % 2 == 1) {
        sum += positive.back();
    }

    for(int i = 0; i < nsize - 1; i+=2) {
        sum += negative[i] * negative[i+1];
    }
    if(nsize % 2 == 1 && !zero) {
        sum += negative.back();
    }

    sum += one;

    cout << sum;
}
