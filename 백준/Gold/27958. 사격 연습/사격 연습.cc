#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // {현재 체력, 초기 체력}
#define endl "\n"

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M, answer = 0;
int arr[6]; // 총알 공격력

// 맵 상태를 복사하는 함수
void CopyMap(pii src[][9], pii dest[][9]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

int shoot(pii Map[][9], int r, int idx) {
    int attack = arr[idx];
    int score = 0;

    for(int c = 0; c < N; c++) {
        if(Map[r][c].first == 0) continue; // 빈 칸이면 패스

        int current_hp = Map[r][c].first;
        int max_hp = Map[r][c].second;

        // 보너스 표적 (초기 체력이 10 이상인 경우)
        if(max_hp >= 10) {
            score += max_hp;
            Map[r][c] = {0, 0}; // 소멸
            return score;
        }
            // 일반 표적
        else {
            // 1. 공격력이 현재 체력 이상인 경우 (파괴)
            if(attack >= current_hp) {
                score += max_hp; // 점수는 초기 체력 기준
                Map[r][c] = {0, 0}; // 현재 위치 소멸

                // 새끼 표적 생성 (초기 체력 / 4)
                int new_hp = max_hp / 4;
                if(new_hp > 0) {
                    for(int k = 0; k < 4; k++) {
                        int nx = r + dx[k];
                        int ny = c + dy[k];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if(Map[nx][ny].first != 0) continue; // 빈 칸이 아니면 생성 불가

                        // **중요: 생성될 때 현재 체력과 초기 체력을 모두 기록**
                        Map[nx][ny] = {new_hp, new_hp};
                    }
                }
                return score;
            }
                // 2. 공격력이 부족한 경우 (체력 감소)
            else {
                Map[r][c].first -= attack; // 현재 체력만 감소, 초기 체력(.second)은 유지
                return score; // 점수 없음
            }
        }
    }
    return score; // 맞는 표적이 없는 경우
}

void bt(int cnt, pii current_map[][9], int current_score) {
    answer = max(answer, current_score);

    if(cnt == M) return;

    pii next_map[9][9];

    for(int i = 0; i < N; i++) {
        CopyMap(current_map, next_map); // 맵 상태 복사
        int get_score = shoot(next_map, i, cnt); // 복사본에 사격
        bt(cnt + 1, next_map, current_score + get_score);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    pii start_map[9][9]; // {current, initial}

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int hp;
            cin >> hp;
            start_map[i][j] = {hp, hp}; // 처음엔 현재체력 = 초기체력
        }
    }

    for(int i = 0; i < M; i++) {
        cin >> arr[i];
    }

    bt(0, start_map, 0);

    cout << answer;
}