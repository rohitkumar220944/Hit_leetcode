class Solution {

    public boolean f(char[][] board, String word, int i, int j, int widx) {

        if (widx == word.length()) return true;

        int row = board.length;
        int col = board[0].length;

        // boundary check
        if (i < 0 || j < 0 || i >= row || j >= col) return false;

        // mismatch check
        if (board[i][j] != word.charAt(widx)) return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        boolean res =
                f(board, word, i + 1, j, widx + 1) ||
                f(board, word, i - 1, j, widx + 1) ||
                f(board, word, i, j + 1, widx + 1) ||
                f(board, word, i, j - 1, widx + 1);

        board[i][j] = temp; // backtrack
        return res;
    }

    public boolean exist(char[][] board, String word) {

        int row = board.length;
        int col = board[0].length;

        if (word.length() > row * col) return false;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {   // ✅ FIXED
                if (board[i][j] == word.charAt(0)) {  // ✅ FIXED
                    if (f(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
}
