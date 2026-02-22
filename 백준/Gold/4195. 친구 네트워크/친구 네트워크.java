import java.util.*;
import java.io.*;

public class Main {
    static int T, N;
    static int MAX = 100000;
    static String[][] graph;
    static int idx;
    static int unf[];
    static int dp[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());

        while(T != 0) {
            T--;

            N = Integer.parseInt(br.readLine());
            graph = new String[N][2];
            idx = 1;
            Map<String, Integer> m = new HashMap<>();

            for(int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                graph[i][0] = st.nextToken();
                graph[i][1] = st.nextToken();

                for(int j = 0; j < 2; j++) {
                    if(!m.containsKey(graph[i][j])) {
                        m.put(graph[i][j], idx);
                        idx++;
                    }
                }
            }

            unf = new int[idx+1];
            dp = new int[idx+1];

            Init();

            for(int i = 0; i < N; i++) {
                int idx1 = m.get(graph[i][0]);
                int idx2 = m.get(graph[i][1]);

                if(!isUnion(idx1, idx2)) {
                    Union(idx1, idx2);
                }

                bw.write(dp[Math.min(Find(idx1), Find(idx2))] + "\n");
            }
        }

        bw.flush();
    }

    static void Init() {
        for(int i = 1; i <= idx; i++) {
            unf[i] = i;
        }

        Arrays.fill(dp, 1);
    }

    static int Find(int a) {
        if(unf[a] == a) {
            return a;
        }
        return unf[a] = Find(unf[a]);
    }

    static void Union(int a, int b) {
        a = Find(a);
        b = Find(b);

        if(a > b) {
            unf[a] = b;
            dp[b] += dp[a];
            dp[a] = dp[b];
        }
        else {
            unf[b] = a;
            dp[a] += dp[b];
            dp[b] = dp[a];
        }
    }

    static boolean isUnion(int a, int b) {
        a = Find(a);
        b = Find(b);

        if(a == b) return true;
        else return false;
    }
}
