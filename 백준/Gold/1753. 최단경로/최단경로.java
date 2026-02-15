import java.util.*;
import java.io.*;

public class Main {
    static int V, E, K;
    static List<Node>[] v;
    static int dist[];

    static class Node {
        int to, weight;

        Node(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static void dijkstra() {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (a[0] - b[0]));
        pq.add(new int[]{0, K});     // 가중치, 노드
        dist[K] = 0;

        while(!pq.isEmpty()) {
            int[] arr = pq.poll();
            int cost = arr[0];
            int node = arr[1];

            if(dist[node] < cost) continue;

            for(Node a : v[node]) {
                int nextNode = a.to;
                int nextCost = cost + a.weight;

                if(dist[nextNode] > nextCost) {
                    pq.add(new int[]{nextCost, nextNode});
                    dist[nextNode] = nextCost;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        K = Integer.parseInt(br.readLine());

        dist = new int[V+1];

        Arrays.fill(dist, Integer.MAX_VALUE);

        v = new ArrayList[V+1];

        for(int i = 1; i <= V; i++) {
            v[i] = new ArrayList<>();
        }

        for(int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            v[a].add(new Node(b, c));
        }

        dijkstra();

        for(int i = 1; i <= V; i++) {
            if(dist[i] == Integer.MAX_VALUE) {
                bw.write("INF" + "\n");
            }
            else bw.write(dist[i] + "\n");
        }

        bw.flush();
    }
}
