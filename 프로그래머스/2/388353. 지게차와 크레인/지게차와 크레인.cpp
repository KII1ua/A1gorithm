#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 수정한 bfs 함수
void bfs(vector<string> &storage, int N, int M, char stand) {
    // Phase 1: Accessible Empty Space Identification
    // ' ' 공간만 탐색하여 외부와 연결된 모든 빈 공간을 찾음
    bool accessible_space[51][51] = {false};
    queue<pii> q;

    // 1. 큐 초기화: 경계에 있는 ' ' 빈 공간만 시작점으로 사용
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i == 0 || i == N-1 || j == 0 || j == M-1) {
                if(storage[i][j] == ' ') {
                    q.push({i, j});
                    accessible_space[i][j] = true;
                }
            }
        }
    }

    // 2. BFS 탐색: 오직 ' ' 공간을 통해서만 전파
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(accessible_space[nx][ny]) continue;
            
            // 핵심: 'stand' 물건은 벽으로 간주하여 탐색을 막음.
            if(storage[nx][ny] == ' ') {
                q.push({nx, ny});
                accessible_space[nx][ny] = true;
            }
        }
    }

    // Phase 2: Item Removal
    // 접근 가능한 빈 공간에 인접한 'stand' 물건들을 제거
    vector<pii> to_remove;
    
    // 3. 제거 대상 물건 목록 작성: 'stand' 이면서 인접한 곳에 accessible_space가 true인 칸이 있는지 확인
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(storage[i][j] == stand) {
                // 경계에 있는 물건은 무조건 제거 대상에 포함 (Phase 1에서 빈 공간은 이미 처리됨)
                if (i == 0 || i == N-1 || j == 0 || j == M-1) {
                    to_remove.push_back({i, j});
                    continue;
                }

                // 인접한 칸 중에 접근 가능한 빈 공간이 있는지 확인
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    // 경계 체크는 이미 Phase 1에서 했으므로, nx, ny는 격자 내부
                    if(accessible_space[nx][ny]) {
                        to_remove.push_back({i, j});
                        break; // 하나라도 인접하면 제거 대상 확정
                    }
                }
            }
        }
    }
    
    // 4. 제거 적용
    for (const auto& p : to_remove) {
        storage[p.first][p.second] = ' ';
    }
}

// solution 함수는 requests 매개변수를 처리하도록 수정
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    int N = storage.size();
    int M = storage[0].size();
    
    for(int k = 0; k < requests.size(); k++) {
        char stand = requests[k][0];
        
        if(requests[k].size() == 2) {		// 크레인을 사용하여 모두 제거
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < M; j++) {
                    if(storage[i][j] == stand) {
                        storage[i][j] = ' ';
                    }
                }
            }
        }
        else {			// 바깥에 있는것만 제거
            // 수정된 bfs 함수를 호출합니다.
            bfs(storage, N, M, stand);
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(storage[i][j] != ' ') answer++;
        }
    }
    
    return answer;
}