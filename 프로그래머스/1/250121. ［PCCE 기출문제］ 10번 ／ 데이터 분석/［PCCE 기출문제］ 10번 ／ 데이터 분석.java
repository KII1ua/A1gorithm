import java.util.*;

class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        Map<String, Integer> m = new HashMap<>();
        m.put("code", 0);
        m.put("date", 1);
        m.put("maximum", 2);
        m.put("remain", 3);
        
        int idx1 = m.get(ext);
        int idx2 = m.get(sort_by);
        
        List<int[]> arr = new ArrayList<>();
        
        for(int[] a : data) {
            if(a[idx1] < val_ext) {
                arr.add(a);
            }
        }
        
        arr.sort((a, b) -> (Integer.compare(a[idx2], b[idx2])));
        
        return arr.stream().toArray(int[][]::new);
    }
}