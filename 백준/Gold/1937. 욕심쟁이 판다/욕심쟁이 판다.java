import java.util.*;
import java.io.*;

public class Main {
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int N;
    static int graph[][];
    static int dp[][];


    static int func(int x, int y) {
        if(dp[x][y] != -1) return dp[x][y];

        dp[x][y] = 1;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if(graph[x][y] < graph[nx][ny]) {
                dp[x][y] = Math.max(dp[x][y], func(nx, ny) + 1);
            }
        }

        return dp[x][y];
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        graph = new int[N][N];
        dp = new int[N][N];

        for(int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int answer = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(dp[i][j] == -1) {
                    dp[i][j] = func(i, j);
                    answer = Math.max(answer, dp[i][j]);
                }
            }
        }

        bw.write(answer + " ");

        bw.flush();
    }
}
