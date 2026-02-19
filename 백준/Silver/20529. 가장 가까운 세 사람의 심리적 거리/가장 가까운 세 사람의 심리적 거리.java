import java.util.*;
import java.io.*;

public class Main {
    static int T, N;
    static String[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());

        for(int k = 0; k < T; k++) {
            N = Integer.parseInt(br.readLine());

            StringTokenizer st = new StringTokenizer(br.readLine());
            Set<String> set = new HashSet<>();

            arr = new String[N];

            for(int m = 0; m < N; m++) {
                arr[m] = st.nextToken();
                set.add(arr[m]);
            }

            if(N > 32) {
                bw.write("0" + '\n');
            }
            else {
                int answer = Integer.MAX_VALUE;
                for(int i = 0; i < N; i++) {
                    for(int j = i+1; j < N; j++) {
                        for(int l = j+1; l < N; l++) {
                            answer = Math.min(answer, check(arr[i], arr[j]) + check(arr[i], arr[l]) + check(arr[j], arr[l]));
                        }
                    }
                }

                bw.write(answer + "\n");
            }
        }
        bw.flush();
    }
    static int check(String a, String b) {
        int ans = 0;

        for(int i = 0; i < 4; i++) {
            if(a.charAt(i) != b.charAt(i)) ans++;
        }

        return ans;
    }
}
