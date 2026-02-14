import java.util.*;
import java.io.*;

public class Main {
    static Integer arr[];

    static int compare(Integer a, Integer b) {
        return b - a;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();

        arr = new Integer[s.length()];

        for(int i = 0; i < s.length(); i++) {
            arr[i] = s.charAt(i) - '0';
        }

        Arrays.sort(arr, (a, b) -> b-a);

        for(int a : arr) {
            bw.write(String.valueOf(a));
        }

        bw.flush();
    }
}
