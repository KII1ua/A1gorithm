import java.util.*;
import java.io.*;

public class Main {
    static String s1, s2;
    static char arr1[], arr2[];
    static int dp[][];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        s1 = br.readLine();
        s2 = br.readLine();

        arr1 = new char[s1.length()+1];
        arr2 = new char[s2.length()+1];

        dp = new int[s1.length()+1][s2.length()+1];

        for(int i = 1; i <= s1.length(); i++) {
            arr1[i] = s1.charAt(i-1);
        }

        for(int i = 1; i <= s2.length(); i++) {
            arr2[i] = s2.charAt(i-1);
        }

        int answer = 0;

        for(int i = 1; i <= s1.length(); i++) {
            for(int j = 1; j <= s2.length(); j++) {
                if(arr1[i] == arr2[j]) {
                    dp[i][j] = Math.max(dp[i-1][j-1] + 1, dp[i][j]);
                    answer = Math.max(answer, dp[i][j]);
                }
            }
        }

        bw.write(answer + "");

        bw.flush();
    }
}
