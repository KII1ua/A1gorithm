import java.util.*;
import java.io.*;

public class Main {
    static int T, k, n;
    static int arr[][];

    static int lower_bound(int[] sum2, int goal) {
        int lo = -1;
        int hi = sum2.length;

        while(lo + 1 < hi) {
            int mid = (lo + hi) / 2;

            if(sum2[mid] >= goal) {
                hi = mid;
            }
            else lo = mid;
        }

        return hi;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());

        while(T != 0) {
            T--;
            StringTokenizer st = new StringTokenizer(br.readLine());

            k = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());

            int[] sum1 = new int[n * n];
            int[] sum2 = new int[n * n];

            arr = new int[4][n];

            for(int i = 0; i < 4; i++) {
                st = new StringTokenizer(br.readLine());

                for(int j = 0; j < n; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int idx1 = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    sum1[idx1] = arr[0][i] + arr[1][j];
                    idx1++;
                }
            }

            idx1 = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    sum2[idx1] = arr[2][i] + arr[3][j];
                    idx1++;
                }
            }

            Arrays.sort(sum1);
            Arrays.sort(sum2);

            int answer = Integer.MAX_VALUE;
            int diff = Integer.MAX_VALUE;

            for(int i = 0; i < sum1.length; i++) {
                int value = k - sum1[i];

                int idx = lower_bound(sum2, value);

                if(idx < sum2.length) {
                    int val = sum1[i] + sum2[idx];

                    int df = Math.abs(k - val);

                    if(diff >= df) {
                        if(diff == df) {
                            answer = Math.min(answer, val);
                        }
                        else {
                            diff = df;
                            answer = val;
                        }
                    }
                }

                if(idx > 0) {
                    int val = sum1[i] + sum2[idx-1];

                    int df = Math.abs(k - val);

                    if(diff >= df) {
                        if(diff == df) {
                            answer = Math.min(answer, val);
                        }
                        else {
                            diff = df;
                            answer = val;
                        }
                    }
                }
            }

            bw.write(answer + "" + "\n");

            bw.flush();
        }
    }
}
