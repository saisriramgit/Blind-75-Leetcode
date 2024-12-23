//Time Complexity: O(N * M * 4 ^ S) // S -> length of string
//Space Complexity: O(N * M)

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, 
    int idx, vector<vector<bool>>& vis) {
        if(idx == word.length() - 1)
            return true;
        vis[i][j] = true;

        if(i > 0 && !vis[i - 1][j] && board[i - 1][j] == word[idx + 1] 
        && dfs(board, i - 1, j, word, idx + 1, vis)) {
            return true;
        }

        if(j > 0 && !vis[i][j - 1] && board[i][j - 1] == word[idx + 1] 
        && dfs(board, i, j - 1, word, idx + 1, vis)) {
            return true;
        }

        if(i < board.size() - 1 && !vis[i + 1][j] && board[i + 1][j] == word[idx + 1] 
        && dfs(board, i + 1, j, word, idx + 1, vis)) {
            return true;
        }

        if(j < board[0].size() - 1 && !vis[i][j + 1] && board[i][j + 1] == word[idx + 1] 
        && dfs(board, i, j + 1, word, idx + 1, vis)) {
            return true;
        }

        vis[i][j] = false;
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>>vis(r, vector<bool>(c, false));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(board[i][j] == word[0] && dfs(board, i, j, word, 0, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//Time Complexity: O(N * M * 4 ^ S) // S -> length of string
//Space Complexity: O(S)


class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, 
    int idx) {
        if(idx == word.length() - 1)
            return true;
        board[i][j] -= 65;

        if(i > 0 && board[i - 1][j] == word[idx + 1] 
        && dfs(board, i - 1, j, word, idx + 1)) {
            return true;
        }

        if(j > 0 && board[i][j - 1] == word[idx + 1] 
        && dfs(board, i, j - 1, word, idx + 1)) {
            return true;
        }

        if(i < board.size() - 1 && board[i + 1][j] == word[idx + 1] 
        && dfs(board, i + 1, j, word, idx + 1)) {
            return true;
        }

        if(j < board[0].size() - 1 && board[i][j + 1] == word[idx + 1] 
        && dfs(board, i, j + 1, word, idx + 1)) {
            return true;
        }

        board[i][j] += 65;
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        //vector<vector<bool>>vis(r, vector<bool>(c, false));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};