import java.util.*;
import java.io.*;

public class Main {
    static int T;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());

        for(int t = T; t > 0; t--) {
            String s = br.readLine();

            LinkedList<Character> list = new LinkedList<>();
            ListIterator<Character> cursor = list.listIterator();

            for(int i = 0; i < s.length(); i++) {
                char a = s.charAt(i);

                if(a == '<') {
                    if(cursor.hasPrevious()) {
                        cursor.previous();
                    }
                }
                else if(a == '>') {
                    if(cursor.hasNext()) {
                        cursor.next();
                    }
                }
                else if(a == '-') {
                    if(cursor.hasPrevious()) {
                        cursor.previous();
                        cursor.remove();
                    }
                }
                else {
                    cursor.add(a);
                }
            }

            StringBuilder sb = new StringBuilder();
            for(char ch : list) {
                sb.append(ch);
            }

            bw.write(sb.toString() + "\n");
        }
        bw.flush();
    }
}
