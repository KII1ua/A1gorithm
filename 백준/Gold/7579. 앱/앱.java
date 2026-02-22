import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int MAX = 10001;
    static int[] dp;
    static int[] array;
    static int[] cost;
    static List<Integer>[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        dp = new int[MAX];
        array = new int[N];
        cost = new int[N];

        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < N; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());

        int ct = 0;

        for(int i = 0; i < N; i++) {
            cost[i] = Integer.parseInt(st.nextToken());
            ct += cost[i];
        }

        for(int i = 0; i < N; i++) {
            int memory = array[i];
            int costs = cost[i];

            for(int j = ct; j >= 0; j--) {
                if(j - costs >= 0) {
                    dp[j] = Math.max(dp[j], dp[j - costs] + memory);
                }
            }
        }

        for(int i = 0; i <= ct; i++) {
            if(dp[i] >= M) {
                bw.write(i + "");
                break;
            }
        }

        bw.flush();
    }
}
