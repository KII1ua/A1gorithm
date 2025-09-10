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

struct TRIE {
    bool finish;
    TRIE *Node[11];
    TRIE() {
        finish = false;
        for(int i = 0; i < 11; i++) {
            Node[i] = nullptr;
        }
    }

    void insert(char *str);
    bool find(const char *str);
};

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int T, N;
char phone[10001][11];

void TRIE::insert(char *str) {
    if(*str == NULL) {
        finish = true;
        return;
    }
    int cur = *str - '0';
    if(Node[cur] == NULL) Node[cur] = new TRIE();
    Node[cur]->insert(str+1);
}

bool TRIE::find(const char *str) {
    if(*str == NULL) return true;
    if(finish) return false;

    int cur = *str - '0';
    return Node[cur]->find(str+1);
}

void solve(TRIE &root) {
    bool flag = true;

    for(int i = 0; i < N; i++) {
        if(flag) flag = root.find(phone[i]);
        if(!flag) break;
    }

    if(flag) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        TRIE root;
        for(int i = 0; i < N; i++) {
            cin >> phone[i];
            root.insert(phone[i]);
        }

        solve(root);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
