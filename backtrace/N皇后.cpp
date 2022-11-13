//
// Created by 张新 on 2022/9/10.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        string col = "";
        for (int i=0; i<n; i++) {
            col += '.';
        }
        vector<string> matrix(n, col);
        dfs(matrix, 0, n);
        return res;
    }

    void dfs(vector<string>& matrix, int k, int n) {
        if (k == n) {
            res.push_back(matrix);
            return;
        }
        for (int i=0; i<n; i++) {
            if (isValid(matrix, k, i, n)) {
                matrix[k][i] = 'Q';
                dfs(matrix, k+1, n);
                matrix[k][i] = '.';
            }
        }
    }

    bool isValid(vector<string>& matrix, int k, int i, int n) {
        for (int j=0; j<k; j++) {
            if (matrix[j][i] == 'Q')
                return false;
        }
        int a = k - 1, b = i - 1;
        while (a >=0 && b >= 0) {
            if (matrix[a][b] == 'Q')
                return false;
            a -= 1;
            b -= 1;
        }
        a = k - 1;
        b = i + 1;
        while (a >= 0 && b < n) {
            if (matrix[a][b] == 'Q')
                return false;
            a -= 1;
            b += 1;
        }
        return true;
    }
};