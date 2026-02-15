import java.util.*;
import java.io.*;

public class Main {
    static String s1, s2;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        s1 = br.readLine();
        s2 = br.readLine();

        int idx1 = -1;
        int idx2 = s2.length();

        for(int i = 0; i < Math.min(s1.length(), s2.length()); i++) {
            if(s1.charAt(i) != s2.charAt(i)) {
                break;
            }
            idx1 = i;
        }

        int i = s1.length()-1;
        int j = s2.length()-1;

        for(; i >= 0 && j >= 0 && i > idx1 && j > idx1; i--,j--) {
            if(s1.charAt(i) != s2.charAt(j)) break;

            idx2 = j;
        }

        bw.write(idx2 - idx1 -1 + "");

        bw.flush();
    }
}
