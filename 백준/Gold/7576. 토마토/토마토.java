import java.util.*;
import java.io.*;

class Pair {
    int x;
    int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int M, N;
    static int graph[][];
    static int visited[][];
    static int dx[] = {0, 0, -1, 1};
    static int dy[] = {-1, 1, 0, 0};
    static Deque<Pair> q = new ArrayDeque<>();

    static void bfs() {
        while(!q.isEmpty()) {
            Pair a = q.peek();
            q.poll();

            for(int i = 0; i < 4; i++) {
                int nx = a.x + dx[i];
                int ny = a.y + dy[i];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                if(visited[nx][ny] == 0 && graph[nx][ny] == 0) {
                    q.add(new Pair(nx, ny));
                    visited[nx][ny] = visited[a.x][a.y] + 1;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        graph = new int[N][M];
        visited = new int[N][M];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());

                if(graph[i][j] == 1) {
                    q.add(new Pair(i, j));
                    visited[i][j] = 1;
                }
            }
        }

        bfs();

        int answer = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(visited[i][j] == 0 && graph[i][j] == 0) {
                    bw.write(-1 + " ");
                    bw.flush();
                    return;
                }
                else {
                    answer = Math.max(answer, visited[i][j]);
                }
            }
        }

        bw.write(answer - 1 + " ");
        bw.flush();
    }
}
