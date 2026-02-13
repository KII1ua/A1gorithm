import java.util.*;
import java.io.*;

public class Main {
    static String s;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        s = br.readLine();

        bw.write(String.valueOf(s.length()));

        bw.flush();
        bw.close();
        br.close();
    }
}
