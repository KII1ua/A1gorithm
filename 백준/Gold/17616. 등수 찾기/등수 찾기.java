import java.util.*;
import java.io.*;

public class Main {
    static int N, M, X;
    static List<Integer>[] graph;
    static List<Integer>[] dgraph;
    static boolean visited[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N+1];
        dgraph = new ArrayList[N+1];
        visited = new boolean[N+1];

        for(int i = 0; i <= N; i++) {
            graph[i] = new ArrayList<>();
            dgraph[i] = new ArrayList<>();
        }

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            dgraph[b].add(a);
        }

        int c = bfs(X);
        Arrays.fill(visited, false);
        int d = dbfs(X);

        bw.write(d+1 + " ");
        bw.write(N - c + "");
        bw.flush();
    }

    static int bfs(int n) {
        Queue<Integer> q = new ArrayDeque<>();
        q.add(n);
        visited[n] = true;
        int cnt = 0;
        
        while(!q.isEmpty()) {
            int node = q.poll();

            for(int next : graph[node]) {
                if(!visited[next]) {
                    q.add(next);
                    visited[next] = true;
                    cnt++;
                }
            }
        }

        return cnt;
    }

    static int dbfs(int n) {
        Queue<Integer> q = new ArrayDeque<>();
        q.add(n);
        visited[n] = true;
        int cnt = 0;

        while(!q.isEmpty()) {
            int node = q.poll();

            for(int next : dgraph[node]) {
                if(!visited[next]) {
                    q.add(next);
                    visited[next] = true;
                    cnt++;
                }
            }
        }

        return cnt;
    }
}
