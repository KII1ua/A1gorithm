import java.util.*;
import java.io.*;

public class Main {
    static int N, r1, r2;
    static List<int[]>[] v;
    static int[] dist;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        r1 = Integer.parseInt(st.nextToken());
        r2 = Integer.parseInt(st.nextToken());

        v = new ArrayList[N+1];

        for(int i = 0; i <= N; i++) {
            v[i] = new ArrayList<>();
        }

        dist = new int[N+1];

        for(int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            v[a].add(new int[]{b, c});
            v[b].add(new int[]{a, c});
        }

        bfs();
    }

    static void bfs() {
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{r1, 1, 0});
        dist[r1] = 1;

        while(!q.isEmpty()) {
            int[] arr = q.poll();
            int node = arr[0];
            int cost = arr[1];
            int edge = arr[2];

            if(node == r2) {
                System.out.println(cost - edge - 1 + "\n");

                System.exit(0);
            }

            for(int[] tmp : v[node]) {
                int nextNode = tmp[0];
                int nextCost = cost + tmp[1];
                int nextEdge = Math.max(edge, tmp[1]);

                if(dist[nextNode] == 0) {
                    q.add(new int[]{nextNode, nextCost, nextEdge});
                    dist[nextNode] = nextCost;
                }
            }
        }
    }
}
