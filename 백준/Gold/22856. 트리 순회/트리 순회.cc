#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int left, right;
};

const int INF = 1e9;
const int MAX = 100001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
Tree tree[100001];
int order[100001];
int parent[100001];
bool visited[100001];
int cnt, answer;
pii last;

void func(int node) {

    if(tree[node].left != -1) {
        order[tree[node].left] = ++cnt;
        func(tree[node].left);
    }

    order[node] = ++cnt;

    if(tree[node].right != -1)  {
        order[tree[node].right] = ++cnt;
        func(tree[node].right);
    }
}

void dfs(int node) {
    if(tree[node].left != -1 && !visited[tree[node].left])  {
        visited[tree[node].left] = true;
        answer++;
        dfs(tree[node].left);
    }
    else if(tree[node].right != -1 && !visited[tree[node].right])  {
        visited[tree[node].right] = true;
        answer++;
        dfs(tree[node].right);
    }
    else if(node == last.first) {
        return;
    }
    else {
        answer++;
        dfs(parent[node]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].left = b;
        tree[a].right = c;

        if(b != -1) {
            parent[b] = a;
        }
        if(c != -1) {
            parent[c] = a;
        }
    }

    func(1);

    for(int i = 1; i <= N; i++) {
        if(last.second < order[i]) {
            last.first = i;
            last.second = order[i];
        }
    }

    dfs(1);

    cout << answer;
}