import java.util.*;
import java.io.*;

public class Main {
    static int N, D;
    static List<Node> arr;
    static int[] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        arr = new ArrayList<>();
        dp = new int[D+1];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            arr.add(new Node(a, b, c));
        }

        for(int i = 0; i <= D; i++) {
            dp[i] = i;
        }

        Collections.sort(arr, (o1, o2) -> {
            if(o1.start == o2.start) return o1.end - o2.end;
            return o1.start - o2.start;
        });

        int idx = 0;

        for(int i = 0; i <= D; i++) {
            if(i > 0) {
                dp[i] = Math.min(dp[i-1] + 1, dp[i]);
            }

            while(idx < arr.size() && arr.get(idx).start == i) {
                if(arr.get(idx).end <= D) {
                    dp[arr.get(idx).end] = Math.min(dp[arr.get(idx).end], dp[arr.get(idx).start] + arr.get(idx).lens);
                }
                idx++;
            }
        }

        bw.write(dp[D] + "");
        bw.flush();
    }

    static class Node {
        int start;
        int end;
        int lens;

        public Node(int start, int end, int lens) {
            this.start = start;
            this.end = end;
            this.lens = lens;
        }
    }
}
