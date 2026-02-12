import java.util.*;
import java.io.*;

public class Main {
    static int a, b;

    public static void solve() {
        System.out.println(a + b);
    }

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        a = Integer.parseInt(br.readLine());
        b = Integer.parseInt(br.readLine());
    }

    public static void main(String[] args) throws Exception {
        input();
        solve();
    }
}
