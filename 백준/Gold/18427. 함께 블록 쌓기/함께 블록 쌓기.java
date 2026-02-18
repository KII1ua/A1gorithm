import java.util.*;
import java.io.*;

public class Main {
    static int N, M, H;
    static List<Integer>[] block;
    static int dp[][];      // i번째 학생들을 가지고 높이가 j인 탑을 만들 수 있는 경우
    static int MOD = 10007;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        block = new ArrayList[N+1];

        for(int i = 0; i <= N; i++) {
            block[i] = new ArrayList<>();
        }

        dp = new int[N+1][H+1];

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            while(st.hasMoreTokens()) {
                int a = Integer.parseInt(st.nextToken());
                block[i].add(a);
            }
        }

        for(int i = 0; i <= N; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= N; i++) {       // 사람
            for(int j = 1; j <= H; j++) {
                for(int k = 0; k < block[i].size(); k++) {
                    if(j >= block[i].get(k)) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-block[i].get(k)]) % MOD;
                    }
                }
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
        }

        bw.write(dp[N][H] +"");
        bw.flush();
    }
}
