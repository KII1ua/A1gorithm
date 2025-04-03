#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Endl "\n"
#define MAX 1e9

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

void solve(string *s) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < s->length() * 4 + 1; j++) {
            if(i == 0 || i == 4) {
                if(j % 4 == 2) {
                    if(((j - 2) / 4) % 3 == 2) cout << '*';
                    else cout << "#";
                }
                else cout << '.';
            }
            else if (i == 1 || i == 3)
            {
                if (j % 2 == 1)
                {
                    if (j % 12 == 9 || j % 12 == 11) cout << '*';
                    else cout << '#';
                }
                else cout << '.';
            }
            else
            {
                if (j % 2 == 0)
                {
                    if (j % 4 == 2) cout << (*s)[j/4];
                    else
                    {
                        if (j == 0 || (s->length() % 3 != 0 && j == 4 * s->length())) cout << '#';
                        else
                        {
                            if (j % 12 == 0 || j % 12 == 8) cout << '*';
                            else cout << '#';
                        }
                    }
                }
                else cout << '.';
            }
        }
        cout << "\n";
    }
}

void input() {
    string s;
    cin >> s;
    solve(&s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
