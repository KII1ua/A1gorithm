// baekjoon 4889
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int R, G, tmp;

    cin >> R >> G;

    tmp = gcd(R, G);

    for(int i = 1; i <= tmp; i++) {
        if(tmp % i == 0) {
            cout << i << " " << R / i << " " << G / i << endl;
        }
    }
}