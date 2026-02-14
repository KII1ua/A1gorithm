import java.util.*;
import java.io.*;


public class Main {
    static int K;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        K = Integer.parseInt(br.readLine());

        Deque<Integer> dq = new ArrayDeque<>();

        for(int i = 0; i < K; i++) {
            int a = Integer.parseInt(br.readLine());
            if(a == 0){
                if(dq.size() == 0) {
                    continue;
                }
                else dq.pop();
            }
            else dq.push(a);
        }

        int answer = 0;

        for(int a : dq) {
            answer += a;
        }

        bw.write(answer + " ");

        bw.flush();
    }
}
