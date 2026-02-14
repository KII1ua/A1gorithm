import java.util.*;
import java.io.*;

class Pair implements Comparable<Pair> {
    int a;
    String b;

    Pair(int a, String b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public int compareTo(Pair o) {
        return a - o.a;
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
            String s = st.nextToken();

            arr[i] = new Pair(a, s);
        }

        Arrays.sort(arr);

        for(Pair a : arr) {
            bw.write(a.a+ " " + a.b + "\n");
        }

        bw.flush();
    }
}
