import java.util.*;
import java.io.*;

public class Main {
    static String s;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        s = br.readLine();

        Set<String> st = new HashSet<>();

        for(int i = 0; i < s.length(); i++) {
            for(int j = i+1; j <= s.length(); j++) {
                st.add(s.substring(i, j));
            }
        }

        bw.write(st.size() + "");

        bw.flush();
    }
}
