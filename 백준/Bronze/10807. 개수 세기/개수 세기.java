import java.util.*;
import java.io.*;

public class Main {
    static int N, v;
    static int MAX = 101;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        List<Integer> list = new ArrayList<>();

        while(st.hasMoreTokens()) {
            list.add(Integer.parseInt(st.nextToken()));
        }

        v = Integer.parseInt(br.readLine());

        int cnt = 0;
        for(int i = 0; i < list.size(); i++) {
            if(list.get(i) == v) cnt++;
        }

        bw.write(String.valueOf(cnt));

        bw.flush();

        bw.close();
        br.close();
    }
}
