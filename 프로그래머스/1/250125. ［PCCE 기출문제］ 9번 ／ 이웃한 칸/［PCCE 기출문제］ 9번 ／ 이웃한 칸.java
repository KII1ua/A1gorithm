class Solution {
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
    public int solution(String[][] board, int h, int w) {
        int n = board.length;
        int m = board[0].length;
        
        int answer = 0;
        
        for(int i = 0; i < 4; i++) {
            int nx = h + dx[i];
            int ny = w + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(board[h][w].equals(board[nx][ny])) {
                answer++;
            }
        }
        
        return answer;
    }
}