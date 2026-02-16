import java.util.*;
import java.io.*;

public class Main {
    static int[][] graph;
    static int N, M, startx, starty, island;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static boolean[][] visited;
    static boolean[][] checked;

    // 빙산 개수 세기
    static int check() {
        visited = new boolean[N][M];

        int count = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(!visited[i][j] && graph[i][j] > 0) {
                    bfs(i, j);
                    count++;
                }
            }
        }

        return count;
    }

    static void bfs(int a, int b) {
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{a, b});
        visited[a][b] = true;

        while(!q.isEmpty()) {
            int[] arr = q.poll();
            int x = arr[0];
            int y = arr[1];

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                if(!visited[nx][ny] && graph[nx][ny] > 0) {
                    q.add(new int[]{nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    static void melt() {
        int[][] minus = new int[N][M];

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                int cnt = 0;
                if(graph[i][j] > 0) {

                    for(int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                        if(graph[nx][ny] == 0) cnt++;
                    }
                }

                minus[i][j] = cnt;
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(graph[i][j] > 0) {
                    graph[i][j] = Math.max(0, graph[i][j] - minus[i][j]);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new int[N][M];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());

                if(graph[i][j] > 0) {
                    startx = i;
                    starty = j;
                    island++;
                }
            }
        }
        
        int answer = 0;

        while(true) {
            int island = check();

            if(island >= 2) {
                bw.write(answer + "");
                bw.flush();
                return;
            }
            else if(island == 0) {
                bw.write(0 + "");
                bw.flush();
                return;
            }
            else {
                melt();
                answer++;
            }
        }
    }
}
