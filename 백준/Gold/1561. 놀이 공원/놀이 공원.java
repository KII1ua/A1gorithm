import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[M+1];

        st = new StringTokenizer(br.readLine());

        for(int i = 1; i <= M; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        if(M == 1) {
            bw.write(M + "");
            bw.flush();
            return;
        }
        else if(N <= M) {
            bw.write(N + "");
            bw.flush();
            return;
        }

        long lo = -1;
        long hi = Long.MAX_VALUE;

        while(lo + 1 < hi) {
            long mid = (lo + hi) / 2;

            if(check(mid)) {
                hi = mid;
            }
            else lo = mid;
        }

        long lastnum = 0;
        for(int i = 1; i <= M; i++) {
            lastnum += ((hi-1) / arr[i]) + 1;

            if(lastnum == N) {
                bw.write(i + "");
                bw.flush();
                return;
            }
        }

        for(int i = 1; i <= M; i++) {
            if(hi % arr[i] == 0) {
                lastnum++;
            }

            if(lastnum == N) {
                bw.write(i + "");
                bw.flush();
                return;
            }
        }
    }

    static boolean check(long time) {
        long answer = M;
        for(int i = 1; i <= M; i++) {
            answer += (time / arr[i]);

            if(answer >= N) {
                return answer >= N;
            }
        }

        return answer >= N;
        // answer가 크면 시간을 낮춰야 한다. hi를 mid로
        // answer가 작으면 시간을 더 높여야함   lo를 mid로
    }
}
