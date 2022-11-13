//
// Created by 张新 on 2022/9/4.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int idx, int i, int j) {
        if (idx == word.length())
            return true;
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
            return false;
        if (board[i][j] == '0' || board[i][j] != word[idx])
            return false;
        board[i][j] = '0';
        bool a = dfs(board, word, idx+1, i+1, j);
        bool b = dfs(board, word, idx+1, i-1, j);
        bool c = dfs(board, word, idx+1, i, j+1);
        bool d = dfs(board, word, idx+1, i, j-1);
        board[i][j] = word[idx];
        return a || b || c || d;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};

