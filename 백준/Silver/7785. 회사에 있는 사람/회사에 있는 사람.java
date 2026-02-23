import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static Map<String, Integer> m;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<String> arr = new ArrayList<>();
        N = Integer.parseInt(br.readLine());

        m = new HashMap<>();

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String s1 = st.nextToken();
            String s2 = st.nextToken();

            if(s2.equals("enter")) {
                m.put(s1, 1);
            }
            else {
                if(m.containsKey(s1)) {
                    m.remove(s1);
                }
            }
        }
        m.forEach((key, value) -> {
            arr.add(key);
        });

        Collections.sort(arr, Collections.reverseOrder());

        for(String s : arr) {
            bw.write(s + "\n");
        }

        bw.flush();
    }
}
