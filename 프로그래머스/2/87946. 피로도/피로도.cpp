#include <string>
#include <vector>

using namespace std;

int answer = 0;
int N;

void bt(int cnt, int hp, vector<vector<int>> &dungeons, vector<bool> visited) {
    answer = max(answer, cnt);
    
    for(int i = 0; i < N; i++) {
        if(!visited[i] && dungeons[i][0] <= hp) {
            visited[i] = true;
            bt(cnt+1, hp - dungeons[i][1], dungeons, visited);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    N = dungeons.size();
    vector<bool> visited(dungeons.size(), false);
    bt(0, k, dungeons, visited);
    
    return answer;
}