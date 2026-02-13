import java.util.*;
import java.io.*;

public class Main {
    static String s;
    static int alpha[];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        s = br.readLine();

        alpha = new int[26];

        for(int i = 0; i < 26; i++) {
            alpha[i] = -1;
        }

        for(int i = 0; i < s.length(); i++) {
            int idx = s.charAt(i) - 'a';
            if(alpha[idx] != -1) continue;
            alpha[idx] = i;
        }

        for(int i = 0; i < 26; i++) {
            bw.write(String.valueOf(alpha[i]) + " ");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
