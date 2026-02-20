import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[] arr;
    static int[] temp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        arr = new int[N];
        temp = new int[N];

        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        merge_sort(0, N-1);

        for(int i = 0; i < N; i++) {
            bw.write(arr[i] + "\n");
        }
        bw.flush();
    }

    static void merge_sort(int left, int right) {
        if(left < right) {
            int mid = (left + right) / 2;

            merge_sort(left, mid);
            merge_sort(mid+1, right);

            merge(left, mid, right);
        }
    }

    static void merge(int left, int mid, int right) {
        int i = left;       // 왼쪽 인덱스
        int j = mid+1;      // 오른쪽 인덱스
        int k = left;       // 실제 배열에 담을 인덱스

        while(i <= mid && j <= right) {
            if(arr[i] < arr[j]) {
                temp[k] = arr[i];
                i++;
            }
            else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }

        while(i <= mid) {
            temp[k++] = arr[i++];
        }

        while(j <= right) {
            temp[k++] = arr[j++];
        }

        for(int idx = left; idx <= right; idx++) {
            arr[idx] = temp[idx];
        }
    }
}
