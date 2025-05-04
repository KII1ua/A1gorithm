#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct Node {
    int left;
    int right;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int T, N;
vector<int> preorder;       // 전위
vector<int> inorder;        // 후위

void postorder(int start, int end, int cur) {
    for(int i = start; i < end; i++) {
        if(preorder[cur] == inorder[i]) {
            postorder(start, i, cur+1);
            postorder(i+1, end, cur+1+i-start);
            cout << preorder[cur] << " ";
        }
    }
}

void solve() {
    postorder(0, N, 0);
    cout << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;
        preorder.clear();
        inorder.clear();

        for(int i = 0; i < N; i++) {        // 전위
            int a;
            cin >> a;
            preorder.push_back(a);
        }

        for(int i = 0; i < N; i++) {        // 중위
            int a;
            cin >> a;
            inorder.push_back(a);
        }
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}