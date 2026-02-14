import java.util.*;
import java.io.*;


public class Main {
    static int N;

    static int lower_bound(int a, List<Integer> arr) {
        int lo = -1;
        int hi = arr.size();

        while(lo + 1 < hi) {
            int mid = (lo + hi) / 2;

            if(arr.get(mid) >= a) {
                hi = mid;
            }
            else lo = mid;
        }

        return hi;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        List<Integer> arr = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < N; i++) {
            int a = Integer.parseInt(st.nextToken());

            if(arr.size() == 0 || arr.get(arr.size()-1) < a) {
                arr.add(a);
            }
            else {
                int idx = lower_bound(a, arr);

                arr.set(idx, a);
            }
        }

        bw.write(arr.size() + "");
        
        bw.flush();
    }
}
