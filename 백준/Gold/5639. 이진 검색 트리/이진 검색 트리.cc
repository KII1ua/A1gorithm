#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct Node {
    int root;
    int left;
    int right;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int a, idx;
vector<int> preorder;

void postorder(int start, int end) {
    if(start >= end) return;

    int root = preorder[start];
    int right = end;

    for(int i = start+1; i < end; i++) {
        if(preorder[start] < preorder[i]) {
            right = i;
            break;
        }
    }

    postorder(start+1, right);        // 왼쪽 서브트리 탐색
    postorder(right, end);

    cout << preorder[start] << endl;
}

void solve() {
    postorder(0, preorder.size());
}

void input() {
    while(cin >> a) {
        preorder.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}