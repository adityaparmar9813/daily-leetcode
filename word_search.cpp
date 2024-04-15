class Solution {
public:
    bool dfs(int i, int j, int index, vector<vector<char>>& board, string word) {
        if(word.length() == index) {
            return true;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '\0';

        bool top = dfs(i-1, j, index+1, board, word);
        bool bottom = dfs(i+1, j, index+1, board, word);
        bool left = dfs(i, j-1, index+1, board, word);
        bool right = dfs(i, j+1, index+1, board, word);

        bool ans = top || bottom || left || right;    
        board[i][j] = temp;

        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i < board.size(); i++) {
            for(int j=0; j < board[0].size(); j++) {
                if(board[i][j] == word[0] && dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
}; 

// Time Complexity : O(4^l * m * n)
// Space Complexity : O(4^l)
