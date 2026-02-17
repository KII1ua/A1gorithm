import java.util.*;
import java.io.*;

public class Main {
    static int T;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());

        for(int i = 0; i < T; i++) {
            String s = br.readLine();
            char[] arr = s.toCharArray();

            int lo = 0;
            int hi = s.length()-1;
            int answer = 0;

            while(lo < hi) {
                if(arr[lo] == arr[hi]) {
                    lo++;
                    hi--;
                }
                else {
                    if(check(arr, lo+1, hi)) {
                        answer = 1;
                    }
                    else if(check(arr, lo, hi-1)) {
                        answer = 1;
                    }
                    else {
                        answer = 2;
                    }
                    break;
                }
            }

            bw.write(answer + "\n");

            bw.flush();
        }
    }
    static boolean check(char[] arr, int lo, int hi) {
        while(lo < hi) {
            if(arr[lo] != arr[hi]) return false;

            lo++;
            hi--;
        }

        return true;
    }
}
