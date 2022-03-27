//给你一个 m* n 的矩阵，矩阵中的数字 各不相同请你按任意顺序返回矩阵中的所有幸运数。
//幸运数是指矩阵中满足同时下列两个条件的元素：
//在同一行的所有元素中最小
//在同一列的所有元素中最大

/////////思路：遍历矩阵，记录每一行的最小元素和每一列的最大元素
////只要两者相等就说明它是幸运数
///题外话：(看讨论区中大佬用数学证明幸运数要么只有一个要么没有）
#include "myhead.h"
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 100000); //记录每一行的最小元素
        vector<int> col(n, 0);     //记录每一列的最大元素
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < row[i]) row[i] = matrix[i][j];
                if (matrix[i][j] > col[j]) col[j] = matrix[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == col[j]) res.push_back(row[i]);
            }
        }
        return res;
    }
};