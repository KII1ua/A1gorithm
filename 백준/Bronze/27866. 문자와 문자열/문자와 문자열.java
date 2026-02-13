import java.util.*;
import java.io.*;

public class Main {
    static String s;
    static int i;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        s = br.readLine();
        i = Integer.parseInt(br.readLine());

        for(int j = 0; j < s.length(); j++) {
            if(j+1 == i) {
                bw.write(s.charAt(j));
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
