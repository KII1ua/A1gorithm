import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static List<int[]>[][] graph;
    static boolean visited[][];
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static boolean light[][];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N+1][N+1];
        visited = new boolean[N+1][M+1];
        light = new boolean[N+1][M+1];

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                graph[i][j] = new ArrayList<>();
            }
        }

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            graph[a][b].add(new int[]{c, d});
        }

        bfs();

        int answer = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(light[i][j]) answer++;
            }
        }

        bw.write(answer + "");

        bw.flush();
    }

    static void bfs() {
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{1, 1});
        light[1][1] = true;

        while(!q.isEmpty()) {
            int[] arr = q.poll();
            int x = arr[0];
            int y = arr[1];

            for(int[] map : graph[x][y]) {
                int a = map[0];
                int b = map[1];

                if(!light[a][b]) {
                    light[a][b] = true;

                    for(int i = 0; i < 4; i++) {
                        int nx = a + dx[i];
                        int ny = b + dy[i];

                        if(nx <= 0 || nx > N || ny <= 0 || ny > M) continue;

                        if(visited[nx][ny]){
                            visited[nx][ny] = true;
                            q.add(new int[]{nx, ny});
                        }
                    }
                }
            }

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx <= 0 || nx > N || ny <= 0 || ny > M) continue;

                if(!visited[nx][ny] && light[nx][ny]) {
                    q.add(new int[]{nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}
