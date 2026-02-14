import java.util.*;
import java.io.*;

class Pair implements Comparable<Pair> {
    int x;
    int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair o) {
        if(x == o.x) {
            return y - o.y;
        }
        return x - o.x;
    }
}

public class Main {
    static int N;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        Pair[] arr = new Pair[N];

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[i] = new Pair(a, b);
        }

        Arrays.sort(arr);

        for(Pair a : arr) {
            bw.write(a.x + " " + a.y + "\n");
        }

        bw.flush();
    }
}
