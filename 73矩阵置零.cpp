//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

//一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//一个简单的改进方案是使用 O(m  + n) 的额外空间，但这仍然不是最好的解决方案。
//你能想出一个仅使用常量空间的解决方案吗？

//O(m  + n)很容易，一个记录行中零的位置，一个记录列中零的位置
#include "myhead.h"

///思路1：用二进制数来代替数组记录，但是数组行列太大了，就算用long long 都太大了
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        long long col = 0;
        long long row = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    long long re_row = 1 << i;
                    long long re_col = 1 << j;
                    row |= re_row;
                    col |= re_col;
                }

            }
        }
        int i = 0;
        while (row) {
            if (row & 1) {
                for (int& x : matrix[i]) {
                    x = 0;
                }
            }
            row /= 2;
            i++;
        }
        int j = 0;
        while (col) {
            if (col & 1) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
            col /= 2;
            j++;
        }

    }
};


/////////思路2：
//我们可以用两个标记数组分别记录每一行和每一列是否有零出现。
//我们可以用矩阵的第一行和第一列代替上诉的中的两个标记数组，以达到 O(1) 的额外空间。
//但这样会导致原数组的第一行和第一列被修改，无法记录它们是否原本包含 0。
//因此我们需要额外使用两个标记变量分别记录第一行和第一列是否原本包含 0。
//在实际代码中，我们首先预处理出两个标记变量，接着使用其他行与列去处理第一行与第一列，
//然后反过来使用第一行与第一列去更新其他行与列，最后使用两个标记变量更新第一行与第一列即可。

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

